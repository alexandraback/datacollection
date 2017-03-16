#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <fstream>
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
	ifstream cin("C-small-1-attempt2.in");
	//ifstream cin("input.txt");
	ofstream cout("output.txt");
	#endif

	ll i,j,n,c,k,f,t,T,r,m;
	int *a=new int[2000000];
	cin>>T;
	fon(t,T){
		ll R,M,N,K;
		cin>>R>>M>>N>>K;
		cout<<"Case #"<<t+1<<":"<<endl;
		int c[10]={0};
		for(i=0;i<R;++i){
			
			for(j=0;j<K;++j){
				cin>>f;
				if(f%3==0)c[3]=1;if(f%5==0)c[5]=1;
				if(f==4*4*4)c[4]=1;
				if(f==4*4*2){c[4]=1;c[2]=1;}
				if(f%2==0&&f%4!=0)c[2]=1;
				else if(f%2==0){int j=rand()%2;c[(j+1)*2]=1;}
			}
			int d[10],id=0;
			for(j=2;j<6;++j){if(c[j]==1)d[id++]=j;}
			id=0;
			while(id<3)d[id++]=2+rand()%4;
			for(j=0;j<3;++j)cout<<d[j];cout<<endl;
		}
	}
	re 0;
}