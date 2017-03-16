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
typedef pair<ll,ll> PII;
typedef pair<double,double> PDD;

const double eps=1e-9;

string solve();

int main()
{
 //   freopen("/Users/cjf/Desktop/testcpp/testcpp/A-large.in","r",stdin);

    freopen("/Users/cjf/Desktop/testcpp/testcpp/B-small-attempt0.in","r",stdin);
	freopen("/Users/cjf/Desktop/testcpp/testcpp/B.txt","w",stdout);
    
	int T,l;
	cin>>T; 
	for (l=1;l<=T;l++)
	{
        string ans = solve();
		printf("Case #%d: ",l); cout<<ans<<endl;//printf("%.6f\n",res);
	}
	return 0;
}

string solve()
{
    int i,x,y;
    string ans;
    cin>>x>>y;
    char w='W',e='E',s='S',n='N';
    if (x<0) swap(w,e);
    if (y<0) swap(s,n);
    REP(i,abs(x)*2) if (i%2==0) ans+=w;else ans+=e;
    REP(i,abs(y)*2) if (i%2==0) ans+=s;else ans+=n;
    return ans;
}

