
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
string wy,wyb;
vs vsl,vt;
vi vk,vk1,vk2,vm,vc;
int k1,k2,k3,p;
int a1,a2;
vector<int> vz,vz2;
int zx,d,d2,d1,a,r;



int main() {  
	//freopen( "c:\\wojtek\\uva\\uva\\debug\\c0.in", "rt", stdin); 
	
	//pi=2*acos(0.0);
	//while(1){
	//	vk.clear(); 
	//d=1000000007; 
	
	cin>>t;
	//scanf("%d",&t); 

	for(cas=1;cas<=t;cas++){
		
		cin>>r>>c>>m;

		a=min(r,c);
		b=max(r,c);
		z=0;
		if((m+1==r*c)||(m==0)){
			z=2;
			a1=1;
			d=r*c-m-1;
			cout<<"Case #"<<cas<<":"<<endl;
			for(i=0;i<r;i++){
				for(j=0;j<c;j++){
					if(a1==1){
						cout<<"c";
						a1--;
					}
					else if(d>0){
						cout<<".";
						d--;
					}
					else
						cout<<"*";
				}
				cout<<endl;
			}
		}

		else if(a==1){
			d=r*c-m-1;
			a1=1;
			z=2;
			cout<<"Case #"<<cas<<":"<<endl;
			for(i=0;i<r;i++){
				for(j=0;j<c;j++){
					if(a1==1){
						cout<<"c";
						a1--;
					}
					else if(d>0){
						cout<<".";
						d--;
					}
					else
						cout<<"*";
				}
				cout<<endl;
			}
		}
		else if(a==2){
			if((m%2==0)&&(r*c-m>2)){
				z=1;
				wy.clear();
				wy.assign(c,'*');
				vt.clear();
				vt.assign(r,wy);
				d=r*c-m;
				
					
					
						if(d%2==0){
							z=1;
							if(d<=2*c){
								for(j=0;j<d/2;j++){
									vt[0][j]='.';
									vt[1][j]='.';
								}
							}
							else {
								for(i=0;i<d/c;i++){
									for(j=0;j<c;j++){
										vt[i][j]='.';
									}
								}
							}

							vt[0][0]='c';
						}
			}		
		}
		else {
			wy.clear();
			wy.assign(c,'*');
			vt.clear();
			vt.assign(r,wy);
			d=r*c-m;
			if(d==4||d==6||d>=8){
				z=1;
				if(d<=2*c){
					
						for(j=0;j<d/2;j++){
							vt[0][j]='.';
							vt[1][j]='.';
						}
					
						if(d%2==1){
							vt[0][d/2-1]='*';
							vt[1][d/2-1]='*';
							for(j=0;j<3;j++){
								vt[2][j]='.';
							}
						}
						vt[0][0]='c';
					
					

				}
				else {
					for(i=0;i<d/c;i++){
						for(j=0;j<c;j++){
							vt[i][j]='.';
						}
					}
					for(j=0;j<d%c;j++)
						vt[i][j]='.';
					if(d%c==1){
						if(d/c>2){
							vt[i][1]='.';
							vt[d/c-1][c-1]='*';
						}
						else {
							vt[0][c-1]='*';
							vt[1][c-1]='*';
							vt[i][1]='.';
							vt[i][2]='.';
						}
					}
					vt[0][0]='c';
				}
			}
		}
		if(z==0){
		
			//printf("Case #%d:\n",cas);
			cout<<"Case #"<<cas<<":"<<endl;
			cout<<"Impossible"<<endl;
		}
		else if(z==1){
			cout<<"Case #"<<cas<<":"<<endl;
			for(i=0;i<r;i++){
				for(j=0;j<c;j++){
					cout<<vt[i][j];
				}
				cout<<endl;
			}
		}


	}



	return 0;

} 
