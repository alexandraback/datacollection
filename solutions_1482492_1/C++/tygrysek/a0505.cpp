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

//typedef int int 	ll;
typedef vector<int> 	vi;
typedef pair<int,int> 	pii;
typedef vector<pair<int,int> >	vpii;

int amax,i,k,i2,i1,r,k1,j,m,l,n,i3,j10,j2,j3,a1,a2,a3; 
int cas,c,a,k2,z,t,ng,b,p,s;
pair<int,int> p2;
int ta[2000];
vector<pair<int,int> > vp;
vector<int> va,vk1,vk2,vk3;
vector<vector<int> > vb;
vi vk,vh,vr;
double pi,dx,ax[3000],tx[3000];
double bx,cx,ax0,vx,tx0,bx1,cx1,ax2,z0,da,tx1;

int main() { 
	//freopen( "c:\\wojtek\\uva\\uva\\debug\\t1.in", "rt", stdin); 
	//	int czas=clock(); 
	//pi=2*acos(0.0);
	 
	
	scanf("%ld",&t);
	//cin>>t; 
	//CL(ta,0);

	

	for(cas=1;cas<=t;cas++){  
		scanf("%lf%ld%ld",&dx,&n,&a);
		//cin>>n;
		CL(ta,0);
		
		for(i=0;i<n;i++){
			scanf("%lf%lf",&tx[i],&ax[i]);
			
		}

		cx1=0;
		for(i=0;i<n;i++){
			if(ax[i]>=dx)
				break;
		}
		if(i>0&&i<n){
			bx=ax[i]-ax[i-1];
			cx=tx[i]-tx[i-1];
			bx1=dx-ax[i-1];
			cx1=tx[i-1]+cx*bx1/bx;		//czas na mecie
		}
		
		ax0=2*dx/(cx1*cx1);
		
		printf("Case #%ld:\n",cas);
		for(i=0;i<a;i++){
			scanf("%lf",&ax2);
			
			z0=0;
			vx=0;
			cx=0;
			for(j=0;j<n;j++){
				tx0=sqrt(2*(min(ax[j],dx))/ax2);
				
				da=sqrt(4*vx*vx+8*ax2*(min(ax[j],dx)-z0));
				tx1=(da-2*vx)/(2*ax2);
				tx1+=cx;
				
				if(tx1<min(tx[j],cx1)){
					cx=min(tx[j],cx1);
					vx+=sqrt(2*min(ax[j],dx)*ax2);
					z0=min(ax[j],dx);
					
				}
				if(ax[j]>=dx)
					break;
			}
			if(z0>0){
				
				da=sqrt(4*vx*vx+8*ax2*(dx-z0));
				tx0=(da-2*vx)/(2*ax2);
				tx0+=cx;
			}
			
			//if(ax2<ax0){
			
			//	tx0=sqrt(2*dx/ax2);
				printf("%.7lf\n",tx0);
			//}
			//else
			//	printf("%.7lf\n",cx1);
		}


		//cout<<"Case #"<<cas<<": "<<wx<<endl;
	}



//	czas = clock() - czas;
//	printf("%lf\n",double(czas)/CLOCKS_PER_SEC);					

			
	return 0;

} 
