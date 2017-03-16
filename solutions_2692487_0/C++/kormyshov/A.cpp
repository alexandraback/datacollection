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

int N, res=109;
vector<int> m(109);

void rec(int a, int i, int r){
	//cout<<a<<" "<<i<<" "<<r<<" "<<res<<endl;
	if(i==N){
		res = MIN(res, r);
		return ;
	}
	rec(a, i+1, r+1);
	if(a>1){
	while(a<=m[i]) {
		a+=a-1;
		r++;
	}
	rec(a+m[i], i+1, r);
	}
}

void solve(){
	int A;
	cin>>A>>N;
	res = 109;
	for(int i=0;i<N;++i) cin>>m[i];
	sort(m.begin(), m.begin()+N);
	rec(A, 0, 0);
	printf("%d", res);
}

int main()
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
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


