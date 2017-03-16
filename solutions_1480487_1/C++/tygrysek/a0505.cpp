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

typedef long long 	ll;
typedef vector<int> 	vi;
typedef pair<int,int> 	pii;
typedef vector<pair<int,int> >	vpii;

long amax,i,k,i2,i1,r,k1,j,m,l,n,i3,j10,j2,j3,a1,a2,a3; 
long cas,c,a,k2,z,t,ng,b,p,s;
pair<long,long> p2;
long ta[2000];
vector<pair<long,long> > vp;
vector<long> va,vk1,vk2,vk3;
vector<vector<int> > vb;
vi vk,vh,vr;
double pi,dx,ax,tx[2000];

int main() { 
	//freopen( "c:\\wojtek\\uva\\uva\\debug\\t1.in", "rt", stdin); 
	//	int czas=clock(); 
	//pi=2*acos(0.0);
	 
	
	scanf("%ld",&t);
	//cin>>t; 
	//CL(ta,0);

	

	for(cas=1;cas<=t;cas++){  
		scanf("%ld",&n);
		//cin>>n;
		CL(ta,0);
		CL(tx,0);
		a=0;
		for(i=0;i<n;i++){
			scanf("%ld",&b);
			ta[i]=b;
			a+=ta[i];
		}
		ax=(double)a;
		ax*=2;
		ax/=n;
		
		m=0;
		for(i=0;i<n;i++){
			
			dx=ax-(double)ta[i];
			if(dx<=0){
				dx=0;
				m++;
			}
			tx[i]=100*(dx/(double)a);
		}

		ax=(double)a;
		for(i=0;i<n;i++){
			if(tx[i]>0){
				ax+=(double)ta[i];
			}
		}
		//ax*=2;
		ax/=(n-m);
		for(i=0;i<n;i++){
			
			dx=ax-(double)ta[i];
			if(dx<0){
				dx=0;
				m++;
			}
			tx[i]=100*(dx/(double)a);
		}

		printf("Case #%ld:",cas);
		for(i=0;i<n;i++){
			printf(" %.6lf",tx[i]);
		}
		printf("\n");
		//cout<<"Case #"<<cas<<": "<<wx<<endl;
	}



//	czas = clock() - czas;
//	printf("%lf\n",double(czas)/CLOCKS_PER_SEC);					

			
	return 0;

} 
