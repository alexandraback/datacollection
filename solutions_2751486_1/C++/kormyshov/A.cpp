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
	LL ans;
	friend ostream& operator <<(ostream& out, const Answer &a){
		out<<a.ans;
		return out;
	}
};
Answer ans[MAX_T];

bool gl(char c){
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
	return false;
}

void* solve(void *_id){
	int id = *(int*)_id;
	// считывание данных


	char s[1000009];
	int n, len;
	in>>s>>n;


	// завершение считывания
	sem_post(&sem[id+1]);
	// основное решение

	len = strlen(s);
	LL res=0;
	int p=-1, c=0;
	for(int i=0;s[i];++i)
		if(!gl(s[i])){
			++c;
			if(c>=n){
				res += (i-n+1 - p)*1LL*(len-i);
				p = i-n+1;
				//cout<<i<<" "<<i-n+1 - p<<" "<<len-i<<" "<<res<<endl;
			}
		}else c=0;


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
	freopen("A.cpp","r",stdin);

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


