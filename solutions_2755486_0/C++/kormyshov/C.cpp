#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <memory.h>
#include <cmath>
#include <pthread.h>
#include <semaphore.h>

#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <algorithm>

#define ABS(a) ((a)<0?(-(a)):(a))
#define SIGN(a) ((a)<0?(-1):((a)>0?(1):(0)))
#define SQR(a) ((a)*(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

#define PI (3.1415926)
#define INF (2147483647)
#define INF2 (1073741823)
#define EPS (0.00000001)

#define MOD (1000000007)

#define y1 stupid_cmath
#define y0 stupid_cmath_too

using namespace std;

typedef long long LL;
template<typename T1,typename T2> ostream& operator<<(ostream &O,pair<T1,T2> t) {return O<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &O,vector<T> t){for(int _=0;_<(int)t.size();++_)O<<t[_]<<" ";return O; }

ifstream in("input.txt");
ofstream out("output.txt");

#define MAX_T 101
#define MAX_Threads 4
sem_t sem[MAX_T], sem_count;
pthread_t pthread[MAX_T];

class Answer{
public:
	int ans;
	friend ostream& operator <<(ostream& out, const Answer &a){
		out<<a.ans;
		return out;
	}
};
Answer ans[MAX_T];

void* solve(void *_id){
	int id = *(int*)_id;
	// считывание данных

	int N;
	in>>N;
	int mm[19][9];
	for(int i=0;i<N;++i) for(int j=0;j<8;++j) in>>mm[i][j];

	// завершение считывания
	sem_post(&sem[id+1]);
	// основное решение

	vector<pair<int,int> > v;

	int i, j, k;

	for(i=0;i<N;++i) mm[i][2]+=1000, mm[i][3]+=1000;

	for(i=0;i<N;++i){
		for(j=0;j<mm[i][1];++j)
			v.push_back(make_pair(mm[i][0]+j*mm[i][5], i));
	}

	sort(v.begin(), v.end());

	int res = 0;

	int mas[2000];
	memset(mas, 0, sizeof(mas));

	int t, w, e, s, n;
	for(i=0;i<(int)v.size();){
		k = v[i].first;
		for(j=i;j<(int)v.size() && v[j].first == k;++j){
			t = v[j].second;
			n = (k - mm[t][0])/mm[t][5];
			w = mm[t][2] + n * mm[t][6];
			e = mm[t][3] + n * mm[t][6];
			s = mm[t][4] + n * mm[t][7];
			for(int o=w;o<e;++o) if(mas[o] < s) {
				++res;
				break;
			}
		}
		for(j=i;j<(int)v.size() && v[j].first == k;++j){
			t = v[j].second;
			n = (k - mm[t][0])/mm[t][5];
			w = mm[t][2] + n * mm[t][6];
			e = mm[t][3] + n * mm[t][6];
			s = mm[t][4] + n * mm[t][7];
			for(int o=w;o<e;++o) mas[o] = MAX(mas[o], s);
		}
		i = j;
	}


	// окончание решения
	//sem_wait(&sem[id]);
	// вывод данных

	//out<<"Case #"<<id<<": ";

	ans[id].ans = res;

	cout<<"Write in "<<id<<endl;
	// окончание вывода
	sem_post(&sem[id+1]);
	sem_post(&sem_count);
	pthread_exit(0);
}

void gcj_solve(){
	cout<<"Start solver.\n";
	int T;
	char s[99];
	in>>T;

	sem_init(&sem_count, 0, MAX_Threads);
	sem_init(&sem[1], 0, 2);
	for(int ii=2; ii<=T; ++ii) sem_init(&sem[ii], 0, 0);

	for(int ii=0; ii<T;){
		cout<<"Wait start "<<ii<<" thread.\n";
		sem_wait(&sem[ii+1]);
		sem_wait(&sem_count);
		++ii;
		cout<<"Go "<<ii<<" thread.\n";
		if(pthread_create(&pthread[ii], NULL, solve, &ii) != 0){
			sprintf(s, "Creating the %d thread", ii);
			perror(s);
			return ;
		}
	}
	for(int ii=1; ii<=T; ++ii){
		if(pthread_join(pthread[ii], NULL) != 0){
			sprintf(s, "Joining the %d thread", ii);
			perror(s);
			return ;
		}
	}
	for(int ii=1; ii<=T; ++ii) out<<"Case #"<<ii<<": "<<ans[ii]<<endl;
	cout<<"End solver.\n";
}

int main()
{
	ios_base::sync_with_stdio(0);

	gcj_solve();

	return 0;
}

int cpp4cf_main()
{
	freopen("C.cpp","r",stdin);

	char s[99];
	bool f;

	while(true) {
		cin>>s;
		if(cin.eof()) break;
		if(strstr(s,"/*")) {
			cin>>s;
			if(strstr(s,"Test")) {
				cin>>s;
				if(strstr(s,"on")) {
					cout<<"Output: ";
					cpp4cf_main();
					cout<<"\nAnswer: ";
					f = false;
					while(true) {
						cin>>s;
						if(strstr(s,"*/")) break;
						if(strstr(s,"//")) {
							if(f) cout<<endl;
							else f = true;
						}else cout<<s<<" ";
					}
					cout<<"\n\n";
				}
			}
		}
	}

	return 0;
}


