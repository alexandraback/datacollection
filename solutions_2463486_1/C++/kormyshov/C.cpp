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

bool isPalindrome(LL a){
	char s[99];
	sprintf(s, "%lld", a);
	int i=0, j=strlen(s)-1;
	while(i<j){
		if(s[i]!=s[j]) break;
		++i;
		--j;
	}
	return i>=j;
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);

	vector<LL> v;
	for(int i=1;i<=1e7;++i)
		if(isPalindrome(i) && isPalindrome(i*1LL*i))
			v.push_back(i*1LL*i);

	int t;
	cin>>t;
	LL a, b;
	for(int i=1;i<=t;++i){
		cin>>a>>b;
		printf("Case #%d: %d\n", i, upper_bound(v.begin(), v.end(), b)-lower_bound(v.begin(), v.end(), a));
	}

	return 0;
}

int cpp4cf_main()
{
	/*freopen("C.cpp","r",stdin);*/

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


