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

vector<int> v(3,1);//x,y,n;
map<vector<int>, double> mp;

double solve();
int main()
{
	v[0]=v[1]=0;
	v[2]=1;
	mp[v]=1;
	for(int i=2;i<10000001;i++) {
		v[2]=i;
		mp[v]=0;
	}
    freopen("B-small-attempt2.in","r",stdin);
//	freopen("A-large.in","r",stdin);
	freopen("B.txt","w",stdout);
	int T,l;
	cin>>T; 
	for (l=1;l<=T;l++)
	{
		double e = solve();
		printf("Case #%d: ",l); cout<<e<<endl;//printf("%.6f\n",res);
	}
	return 0;
}




double f(vector<int> w)
{
	if (mp.find(w)!=mp.end()) return mp[w];
	int i;
	i=(w[0]+w[1])/2;
	i=i*(2*i+1);
	if (w[2]>i+w[1]+1) return mp[w]=0;
	double ans = 0;
	if (w[0]==0)
	{
		i = w[1]/2+1;
		if (w[2]==i*(2*i-1)) ans=1;
	}
	else if (w[1]==0)
	{
		
		v[0]=0;v[1]=w[0]-2;
		for (i=(v[1]/2+1)*(v[1]/2+1); i<w[2];i++){
			v[2]=i;
			ans+=f(v)*(pow(0.5,w[2]-i));
		}
	}
	else
	{
		vector<int> v=w;
		v[0]=w[0]+1;v[1]=w[1]-1;
		i=v[0]+v[1]-2;
		i=i/2+1;
		i*=i;
		for (; i<w[2];i++){
			v[2]=i;
			ans+=f(v)*(pow(0.5,w[2]-i));
		}
	}
//	cout<<w[2]<<" "<<w[0]<<" "<<w[1]<<" "<<ans<<endl;
	return mp[w]=ans;
}

double g(vector<int> w)
{
	int i;
	double ans=0;
	vector<int> v=w;
	for (i=1;i<=w[2];i++)
	{
		v[2]=i;
		ans+=f(v);
	//	checkmax(ans,f(v));
	}
	return ans;
}
double solve()
{
	int i,x,y,n;
	cin>>n>>x>>y;
	if (x<0) x=-x;

	v[0]=x;v[1]=y;v[2]=n;
	return g(v);
}

