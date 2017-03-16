#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <memory.h>
#include <cmath>

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

ifstream in("dict.txt");
int mm[27][1305000], len=0;

struct w{
	//public:
	int ind, pos, res, st;
	//void operator = (w a){
		//this->ind = a.ind;
		//this->pos = a.pos;
		//this->res = a.res;
		//this->st  = a.st;
	//}
};

class cmp{
	public:
		bool operator()(w a, w b){
			return a.res > b.res || (a.res == b.res && (a.ind < b.ind || (a.ind == b.ind && a.st < b.st)));
			//return a.ind < b.ind || (a.ind == b.ind && a.res > b.res);
		}
};

priority_queue<w, vector<w>, cmp> q;

void solve(){
	char s[4009];
	int len, tmp;
	cin>>s;
	len = strlen(s);
	w t;
	while(!q.empty()) q.pop();
	t.ind = 0; t.pos = 0; t.res = 0; t.st = 5;
	q.push(t);
	int mx=0;
	while(!q.empty()){
		t = q.top();
		mx = MAX(mx, t.ind);
		//if(q.size()%10000==0) cout<<q.size()<<" "<<mx<<" "<<t.ind<<endl;
		//cout<<t.ind<<" "<<t.pos<<" "<<t.res<<" "<<t.st<<endl;
		q.pop();
		if(t.ind + (6-q.size()/10000000)*1.7 < mx) continue ;
		if(t.ind == len){
			if(mm[26][t.pos]) break;
			else continue ;
		}
		if(mm[26][t.pos]){
			tmp = t.pos;
			t.pos = 0;
			q.push(t);
			t.pos = tmp;
		}
		if(mm[s[t.ind]-'a'][t.pos]){
			tmp = t.pos;
			t.pos = mm[s[t.ind]-'a'][t.pos];
			t.ind++;
			t.st++;
			q.push(t);
			t.st--;
			t.ind--;
			t.pos = tmp;
		}
		if(t.st>=4){
			t.res++;
			t.st = 0;
			t.ind++;
			tmp = t.pos;
			for(int i=0;i<26;++i){
				if(i == s[t.ind]-'a') continue ;
				if(mm[i][tmp]){
					t.pos = mm[i][tmp];
					q.push(t);
					t.pos = tmp;
				}
			}
		}
	}
	//if(mm[26][t.pos]==0) cout<<"error!!!\n";
	printf("%d", t.res);
}

void add(char s[99]){
	int p=0;
	for(int i=0;s[i];++i){
		if(mm[s[i]-'a'][p]) p = mm[s[i]-'a'][p];
		else{
			++len;
			mm[s[i]-'a'][p] = len;
			p = len;
		}
	}
	mm[26][p] = 1;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(0);

	char s[99];
	while(in>>s){
		add(s);
	}

	int T;
	cin>>T;
	for(int i=1;i<=T;++i){
		printf("Case #%d: ", i);
		solve();
		printf("\n");
	}
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


