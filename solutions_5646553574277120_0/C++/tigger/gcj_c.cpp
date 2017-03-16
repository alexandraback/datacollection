
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

#define INF 2000000000
#define FT first
#define SD second
#define PB push_back
#define ll long long
#define PB 		push_back
#define FOR(a,start,end) 	for(int a=int(start); a<int(end); a++)
//#define INF 		int_MAX
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
int s,c,i,k,j,n,m,z,b; 
int t,cas,d,i1,a,i2,r,v;
vi vk;
int ta[150];
int main() {  
	//freopen( "c:\\wojtek\\uva\\uva\\debug\\t1.in", "rt", stdin); 
	
	//pi=2*acos(0.0); 
	//while(1){
	//vk.clear(); 
	//d=1000000007; 
	
		
	
	cin>>t;
	for(cas=1;cas<=t;cas++){
		CL(ta,0);
		cin>>c>>d>>v;
		vk.clear();
		for(i=0;i<d;i++){
			cin>>a;
			if(a<=v)
				vk.push_back(a);
		}
		for(i=0;i<vk.size();i++){
			ta[vk[i]]=1;
		}
		for(i=vk.size()-2;i>=0;i--){

			for(j=v;j>vk[i];j--){
				if(ta[j]==1){
					ta[j+vk[i]]=1;
				}
			}
		}
		z=0;
		for(i=1;i<=v;i++){
			if(ta[i]==0){
				
				for(j=v;j>=1;j--){
					if(ta[j]==1){
						ta[j+i]=1;
					}
				}
				z++;
				ta[i]=1;
			}
		}


		cout<<"Case #"<<cas<<": "<<z<<endl;
	}

	return 0;

} 


