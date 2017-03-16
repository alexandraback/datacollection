//
//  main.cpp
//  testcpp
//
//  Created by ³Â ½¨·É on 12-11-11.
//  Copyright (c) 2012Äê ³Â ½¨·É. All rights reserved.
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
int main()
{
 //   freopen("A-small-attempt0.in","r",stdin);
	freopen("A-large.in","r",stdin);
	freopen("A.txt","w",stdout);
	int T,l;
	cin>>T; 
	for (l=1;l<=T;l++)
	{
		int e = solve();
		printf("Case #%d: ",l); cout<<e<<endl;//printf("%.6f\n",res);
	}
	return 0;
}

int p,n,a[200];
struct Node{
	int p,ans,id;
	Node(int pp,int ansp,int idp)
	{
		p=pp;ans=ansp;id=idp;
	}
	Node(){}
};
int solve()
{
	int i;
	cin>>p>>n;
	REP(i,n) cin>>a[i];
	sort(a,a+n);
	queue<Node> Q;
	Node node(p,0,0);
	Q.push(node);
	int best = n;
	while(!Q.empty())
	{
		Node nd = Q.front();
		Q.pop();
		if (nd.id >= n)
		{
			if (nd.ans < best) best = nd.ans;//cout<<best<<endl;
		}
		else
		{
			Node nd1 = nd;
			if (nd.p > a[nd.id])
			{
				nd.p+=a[nd.id];
				nd.id++;
				Q.push(nd);
			}
			else
			{
				nd1.ans+=1;
				nd1.p+=nd1.p-1;
				if (nd1.ans<best) Q.push(nd1);
				checkmin(best, nd.ans+n-nd.id);
				
			}
		}

	}
	return best;
}

