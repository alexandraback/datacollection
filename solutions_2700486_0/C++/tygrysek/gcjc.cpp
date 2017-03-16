
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

int i,k,j,n,r,c,i1,m,s,g,b0; 
int cas,a,b,z,w,d,h,t,d1,k1;
int amin,amax,bmin,bmax;

double p,tp[1000],dx;

vii vp;
vvii vz; 
pii p1,p2;
 
string we,we1,we2,wex;
vi vk,va,vb;
vvi vvt;
vs tt;


int main() { 
//	freopen( "c:\\wojtek\\uva\\uva\\debug\\dictionary.txt", "rt", stdin); 
	//	int czas=clock(); 
	//pi=2*acos(0.0);

	//d=1000000007;  
	 
	cin>>t;
	
	for(cas=1;cas<=t;cas++){
		cin>>n>>a>>b; 
		for(i=0;i<1000;i++)
			tp[i]=0.0;
		p=0.0;
		if((a+b)%2==0){
			d=a+b+1;
			d=(d+1)/2;
			k=d*(2+4*(d-1))/2;
			if(k<=n)
				p=1.0;
			else {

				d1=d-1;
				k1=d1*(2+4*(d1-1))/2;
				if(k1>=n)
					p=0.0;
				else {
					if(a==0&&k>n)
						p=0.0;
					else {

						k=n-k1;
						tp[0]=0.5;
						k--;
						dx=0.5;
						z=1;
						c=0;
						for(i=0;i<k;i+=2){
							for(j=min(z,b);j>=0;j--){
								if(j==c)
									tp[j]+=(1-tp[j])*dx;
								else 
									tp[j]=tp[j-1]*dx;
							
							}
							if(i+1<k){

								tp[c]=1.0;
								c++;
								z++;
								for(j=min(z,b);j>=0;j--){
								//	if(j==c)
									//	tp[j]+=(1-tp[j])*dx;
								//	else
										tp[j]=tp[j-1]*dx;
							
								}
							
							
							
							}
						}

					}
					p=tp[b];
				}
			} 



		}
		printf("Case #%d: %lf\n",cas,p);
		//cout<<"Case #"<<cas<<": "<<p<<endl;
	
	
	}

	
		
//	czas = clock() - czas;
//	printf("%lf\n",double(czas)/CLOCKS_PER_SEC);					

			
	return 0;

} 
