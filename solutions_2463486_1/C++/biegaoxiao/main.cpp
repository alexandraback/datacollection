//
//  main.cpp
//  testcpp
//
//  Created by 陈 建飞 on 12-11-11.
//  Copyright (c) 2012年 陈 建飞. All rights reserved.
//
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T gcd(T a,T b){return a==0?b:gcd(b%a,a);}
template<class T> inline int countbit(T n){return n==0?0:(1+countbit(n&(n-1)));}
template<class T> inline void pout(T A[],int n){cout<<"{";for (int i=0;i<n;i++)cout<<A[i]<<", ";cout<<"}\n";}
template<class T> inline void pout(vector<T> A,int n=-1){if (n==-1) n=A.size();cout<<"{";for (int i=0;i<n;i++)cout<<A[i]<<", ";cout<<"}\n";}

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
#define FORIT(a,aa) for(a=aa.begin();a!=aa.end();++a)
#define split(str) {vs.clear();istringstream sss(str);while(sss>>(str))vs.push_back(str);}

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;

const double eps=1e-9;

int solve();
vector<ll> v;

bool isP(ll d)
{
    int i=0,j,a[20];
    while (d) {
        a[i++] = d%10;
        d/=10;
    }
    REP(j, i/2)
    {
        if (a[j] != a[i-1-j]) return false;
    }
    return true;
}

ll n = 10000001L;
void pre()
{
    ll i;
    for (i = 1; i < n; i++) if (isP(i) && isP(i*i)) v.push_back(i*i);
}
int main()
{
	int T,l;
    pre();
	cin>>T; 
	for (l=1;l<=T;l++)
	{
		printf("Case #%d: ",l); cout<<solve()<<endl;//printf("%.6f\n",res);
	}
	return 0;
}

int h(ll d)
{
    int i;
    REP(i, v.size()) if (d < v[i]) break;
    return i;
}
int solve()
{
    ll n,m;
    cin>>n>>m;
    return h(m)-h(n-1);
    
}

