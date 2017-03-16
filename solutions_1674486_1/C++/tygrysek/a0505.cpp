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
		vb.clear();
		a=0;
		vk.clear();
		for(i=0;i<=n;i++){
			vb.push_back(vk);
		}
		va.clear();
		for(i=1;i<=n;i++){
			scanf("%ld",&m);
			if(m==0)
				va.push_back(i);
			for(j=0;j<m;j++){
				scanf("%ld",&b);
				vb[b].push_back(i);
			}
			
		}

		z=0;
		for(i=0;i<va.size();i++){
			
			vk1.clear();
			vk2.clear();
			vk1.push_back(va[i]);
			while(vk1.size()>0){
				for(j=0;j<vk1.size();j++){
					for(i1=0;i1<vb[vk1[j]].size();i1++){
						if(ta[vb[vk1[j]][i1]]==i+1){
							z=1;
							break;
						}
						else {
							ta[vb[vk1[j]][i1]]=i+1;
							vk2.push_back(vb[vk1[j]][i1]);
						}
					}
					if(z==1)
						break;
				}
				if(z==1)
					break;
				vk1=vk2;
				vk2.clear();
			}
			if(z==1)
				break;
		}
		if(z==1)
			printf("Case #%ld: Yes\n",cas);
		else
			printf("Case #%ld: No\n",cas);
		//cout<<"Case #"<<cas<<": "<<wx<<endl;
	}



//	czas = clock() - czas;
//	printf("%lf\n",double(czas)/CLOCKS_PER_SEC);					

			
	return 0;

} 
