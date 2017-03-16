
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
#include <fstream>
#include <iomanip>


using namespace std; 
 
#define ll long long
#define PB 		push_back
#define FOR(a,start,end) 	for(int a=int(start); a<int(end); a++)
#define INF 		int_MAX
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
int s,c,i,k,j,n,m,z,jx,z0,b,a0,b0,z1; 
int t,cas,i1,i2,i3;
vvi vvk,vvc;
vii vp,vp2;
pii p1,p2;
vector<pair<int,int> > vpk;
vs ve;
string wya,wyb;
vs vsl,vt;
vi vk,vk1,vk2,vm,vc;
int k1,k2,k3,p;
int a1,a2;
vector<int> vz,vz2;
int zx,d,d2,d1,a;

double bx,cx,ax,dx,kx,fx;


int main() {  
	//freopen( "c:\\wojtek\\uva\\uva\\debug\\t1.in", "rt", stdin); 
	
	//pi=2*acos(0.0);
	//while(1){
	//	vk.clear(); 
	//d=1000000007; 
	
	//cin>>t;
	scanf("%d",&t);

	for(cas=1;cas<=t;cas++){
		
		//cin>>cx>>fx>>dx;
		scanf("%lf%lf%lf",&cx,&fx,&dx);
		ax=dx/2;
		bx=2.0;
		kx=0.0;
		while(1){
			kx+=cx/bx;
			if(kx+dx/(bx+fx)<ax){
				ax=kx+dx/(bx+fx);
				bx+=fx;
			}
			else
				break;
		}

		//cout<<setprecision(7);
		//cout<<"Case #"<<cas<<": "<<setprecision(7)<<ax<<endl;
		printf("Case #%d: %.7lf\n",cas,ax);
	}



	return 0;

} 
