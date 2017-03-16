
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h> 
#include <map>  
#include <string>
#include <vector> 
#include <list>
#include <iostream>   
#include <sstream> 
#include <queue> 
#include <algorithm>

using namespace std; 
 
#define PB 		push_back
#define FOR(a,start,end) 	for(int a=int(start); a<int(end); a++)
#define INF 		INT_MAX
#define SORT(a) 	sort(a.begin(),a.end())
#define CL(a,x) 		memset(a,x,sizeof(a))
#define REP(a,x)	for(int a=0;a<x;a++)
#define REP1(a,x)	for(int a=1;a<=x;a++)
#define MP 		make_pair
#define vi vector<int>
#define vvi vector<vector<int> >
#define vii vector<pair<int,int> >
#define vvii vector<vector<pair<int,int> > >
#define pii pair<int,int>
#define vs vector<string>

int i,k,j,n,r,c,i1,m,s,g,z1; 
int cas,a,b,z,w,d,h,t,zmin;
int amin,amax,bmin,bmax;

vii vp;
vvii vz; 
pii p1,p2;
 
string we,we1,we2,wex;
vi vk,va,vb;
vs tt;


int main() { 
//	freopen( "c:\\wojtek\\uva\\uva\\debug\\tal0.in", "rt", stdin); 
	//	int czas=clock(); 
	//pi=2*acos(0.0);

	//d=1000000007;
	
	
	cin>>t;


	for(cas=1;cas<=t;cas++){
		vk.clear();
		z=0;
		z1=0;		
		cin>>a>>n;
		zmin=n;
		for(i=0;i<n;i++){
			cin>>b;
			vk.push_back(b);
		}
		SORT(vk);
		i=0;
		while((i<n)&&(a>vk[i])){
			a+=vk[i];
			i++;
		}
		
		if((a!=1)&&(i<n)){
			z1=-1;
			b=a;
			for(j=n;j>=i;j--){
				z1++;
				z=0;
				a=b;
				for(i1=i;i1<j;i1++){
					while(a<=vk[i1]){
						z++;
						a+=a-1;
					}
					a+=vk[i1];
				}
				if((z+z1)<zmin)
					zmin=z+z1;
			}
		}
		else if(a==1)
			zmin=n;
		else
			zmin=z;
		cout<<"Case #"<<cas<<": "<<zmin<<endl;
		
	
	}

	
		
//	czas = clock() - czas;
//	printf("%lf\n",double(czas)/CLOCKS_PER_SEC);					

			
	return 0;

} 
