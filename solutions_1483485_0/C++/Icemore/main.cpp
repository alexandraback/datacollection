#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <cmath>
#include <sstream>
#include <ctime>
#include <memory.h>
#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define forv(i, a) for(int i=0; i<(int)a.size(); i++)
#define mset(a, val) memset(a, val, sizeof(a))
#define all(a) a.begin(),a.end()
#define mp make_pair
#define pb push_back
#define VI vector< int >
#define VS vector< string >
#define PII pair< int,int >
#define PDD pair< double,double >
#define PIS pair< int, string >
#define sqr(a) ((a)*(a))
#define cube(a) ((a)*(a)*(a))
#define pi 3.1415926535897932384626433832795
#define PI pi
#define iinf 1000000000
#define linf 1000000000000000000LL
#define sinf 10000
#define eps 1e-12
#define lng long long
#define X first
#define Y second
using namespace std;
#define prev asdprev
#define exit(a) { if (a) cerr<<"oops "<<a<<endl; exit(a); }

#define max(a, b) ((a>b)?a:b)

char mapa[30]="yhesocvxduiglbkrztnwjpfmaq";
char buff[500];

#define taska "intersection"
int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#else
	//freopen(taska".in", "r", stdin);freopen(taska".out", "w", stdout); freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif

	int T;
	
	gets(buff);
	T=atoi(buff);

	forn(tc, T){
		gets(buff);

		for(int i=0; buff[i]; ++i){
			if(isspace(buff[i])) continue;
			else buff[i]=mapa[buff[i]-'a'];
		}

		cout<<"Case #"<<tc+1<<": "<<buff<<endl;
	}


	return 0;
}