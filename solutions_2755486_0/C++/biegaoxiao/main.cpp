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

int solve();

int main()
{
 //   freopen("/Users/cjf/Desktop/testcpp/testcpp/A-large.in","r",stdin);

    freopen("/Users/cjf/Desktop/testcpp/testcpp/C-small-attempt1.in","r",stdin);
	freopen("/Users/cjf/Desktop/testcpp/testcpp/c.txt","w",stdout);
    
	int T,l;
	cin>>T; 
	for (l=1;l<=T;l++)
	{
        int ans = solve();
		printf("Case #%d: ",l); cout<<ans<<endl;//printf("%.6f\n",res);
	}
	return 0;
}


struct Node{
    int d, w, e, s;
};

bool cmp(Node a,Node b){
    return a.d<b.d;
}

int solve()
{
    int v[1000]={0};
    int i,j,m;
    cin>>m;
    vector<Node> nds;
    REP(i, m)
    {
        int d,n,w,e,s,dd,dp,ds;
        cin>>d>>n>>w>>e>>s>>dd>>dp>>ds;
        w=w*2+400;
        e=e*2+400;
        dp*=2;
        Node nd={d,w,e,s};
        REP(j, n){
            nd.d=d+j*dd;
            nd.w=w+j*dp;
            nd.e=e+j*dp;
            nd.s=s+j*ds;
            nds.push_back(nd);
        }
    }
    sort(nds.begin(),nds.end(),cmp);
    int ans = 0;
    int vv[1000]={0};
 //   cout<<nds.size()<<endl;
    REP(i, nds.size()){
        Node nd = nds[i];
        int d=nd.d, w=nd.w, e=nd.e, s=nd.s;
        bool flag = false;
        for (j=w;j<=e;j++)
        {
            if (v[j] < s){
                flag = true;
                checkmax(vv[j],s);
            }
        }
        if (flag) ans++;
    //    if (flag) cout<<d<<endl;
        if (i<nds.size()-1 && d!=nds[i+1].d){
            for (j=0;j<1000;j++) checkmax(v[j],vv[j]);
        }
    }
    return ans;
}

