// topcoder.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include <stdio.h>
#include <tchar.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;

typedef long long ll;

static const double EPS = 1e-9;
inline int ROUND(double x) { return (int)(x+0.5); }
inline bool ISINT(double x) { return fabs(ROUND(x)-x)<EPS; }
inline bool ISEQUAL(double x,double y) { return fabs(x-y)<EPS; }
template<class T> void amin(T &a, T v) { if (a > v) a = v; }
template<class T> void amax(T &a, T v) { if (a < v) a = v; }
#define INRANGE(x,a,b) ((a)<=(x)&&(x)<=(b))
#define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
#define SZ(a) ((int)a.size())
#define NG (-1)
#define BIG (987654321)

void split1(const string& str, vector<string>& out, const char splitter=' ')
{
	out.clear();
	string::size_type st = 0;
	string::size_type next = 0;
	string tmp = str;
	do
	{
		next=tmp.find(splitter,st); // tmp.find_first_of("+-",st); 複数の文字で分けたいとき
		string word = tmp.substr(st,next-st);
		if(word.length()>=1) // 空文字列ありのときは消す
		{
			out.push_back(word);
		}
		st = next+1;
	} while(next!=string::npos);
}

ll gcd(ll x, ll y)
{
	if(x==0) return y;
	if(y==0) return x;

	ll t;

	while(y!=0)
	{
		t = x%y;
		x = y;
		y = t;
	}
	return x;
}

ll leftest(ll A)
{
	for(ll i=62;i>=0;i--)
	{
		if(A & (1LL<<i))
		{
			return i;
		}
	}

	return -1;
}	


int main(){

     freopen("_google_code_jam_input.txt","r",stdin);
	 freopen("_google_code_jam_output.txt","w",stdout);


	 int T;
	 scanf("%d",&T);

	 for (int testcase = 1; testcase<=T; ++testcase)
	 {
		 char str[10000];
		 scanf("%s",str);

		 vector <string> vs;
		 split1(string(str), vs, '/');

		 ll P, Q;
		 {
			 stringstream ss(vs[0]);
			 ss >> P;
		 }


		 {
			 stringstream ss(vs[1]);
			 ss >> Q;
		 }

		 ll g = gcd(P, Q);

		 P /= g;
		 Q /= g;

		 if( (Q & (Q-1LL))!=0)
		 {
			 fprintf(stderr,"Case #%d: impossible\n",testcase);
			 printf("Case #%d: impossible\n",testcase);
		 }
		 else
		 {
			 ll best = leftest(Q)-leftest(P);

			 fprintf(stderr,"Case #%d: %lld\n",testcase,best);
			 printf("Case #%d: %lld\n",testcase,best);
		 }

	 }

	 return 0;
}
