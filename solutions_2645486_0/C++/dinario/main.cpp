#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
#define fon(i,n) for(i=0;i<n;++i)
#define re return
#define ll long long
#pragma comment(linker, "/stack:64000000")
const double EPS = 1E-9;const int INF = 1000000000;const ll INF64 = (ll)1E16;const double PI = 3.1415926535897932384626433832795;
//typedef struct{int a;}tpo;typedef map<double,tpo> tmap;

int main()
{
	#ifndef ONLINE_JUDGE
	ifstream cin("B-small-attempt0.in");
	//ifstream cin("input.txt");
	ofstream cout("output.txt");
	#endif

	ll i,j,n,c,k,f,t,T;
	int a[20000];
	ll *din=new ll[20000000];
	ll *cool=new ll[10000000],icool;
	cin>>T;map <int,ll>ndin;map <int,ll>::iterator itr;
	fon(t,T){
		ll E,R,sum;int e;
		cin>>E>>R>>n;fon(i,n)cin>>a[i];
		icool=1;cool[0]=E;din[E]=0;
		
		for(i=0;i<n;++i){
			ndin.clear();
			for(j=0;j<icool;++j){
				for(k=0;k<=cool[j];++k){
					sum=din[cool[j]]+a[i]*k;
					e=cool[j]-k+R;if(e>E)e=E;
					itr=ndin.find(e);
					if(itr==ndin.end())ndin.insert(make_pair(e,sum));
					else if(itr->second<sum)itr->second=sum;
				}
			}icool=0;
			for(itr=ndin.begin();itr!=ndin.end();++itr){
				cool[icool]=itr->first;
				din[itr->first]=itr->second;
				icool++;
			}
		}
		ll dmax=0;for(i=0;i<icool;++i)
			if(din[cool[i]]>dmax)dmax=din[cool[i]];
		cout<<"Case #"<<t+1<<": "<<dmax<<endl;
	}
	re 0;
}