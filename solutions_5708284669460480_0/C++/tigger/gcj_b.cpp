
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
ll s,c,i,k,j,n,m,z,b,l; 
ll t,cas,d,i1,a,i2,r,z1,dl;
double ax,dx,bx,cx,gx;
int ta[30];
string we,wex;

double ndok(double ax, int b){
	double zx;
	int i;

	zx=1.0;
	for(i=0;i<b;i++){
		zx*=ax;
	}
	return zx;
}


int main() {  
	//freopen( "c:\\wojtek\\uva\\uva\\debug\\t1.in", "rt", stdin); 
	
	//pi=2*acos(0.0); 
	//while(1){
	//vk.clear(); 
	//d=1000000007; 
	
		
	
	cin>>t;
	for(cas=1;cas<=t;cas++){

		cin>>k>>l>>s;
		CL(ta,0);
		cin>>we;

		for(i=0;i<k;i++){
			ta[we[i]-'A']++;
		}
		cin>>wex;
		m=0;
		ax=1.0;
		for(i=0;i<wex.size();i++){
			ax*=(double)ta[wex[i]-'A']/(double)k;
		}
		j=l;
		for(i=1;i<wex.size();i++){
			if(wex[i]==wex[0]){
				j=i;
				for(i1=i+1;i1<l;i1++){
					if(wex[i1]!=wex[i1-i]){
						j=l;
						break;
					}
				}
				if(j==i)
					break;
			}
		}
		if(ax==0.0){
			bx=ax;
			m=0;
		}

		else if(j==l){
			bx=0.0;
			dx=1.0-ax;
			dl=l;
			for(z=1;z<=s/l;z++){
				cx=ndok(ax,z)*ndok(dx,s/l-z);
				cx*=s-dl+1;
				bx+=cx*z;
				dl+=l;
			}
			m=s/l;
		}
		else {
			gx=1.0;
			for(i=l-j;i<wex.size();i++){
				gx*=(double)ta[wex[i]-'A']/(double)k;
			}
			bx=0.0;
			dx=1.0-ax;
			dl=0;
			for(z=1;z<=1+(s-l)/j;z++){
				cx=ndok(ax,z)*ndok(dx,(1+(s-l)/j)-z);
				cx*=s-l+1-dl;
				bx+=cx*z;
				ax*=gx;
				dx=1.0-ax;
				dl+=j;
			} 
			m=1+(s-l)/j;
		}
	//	printf("Case #%d: %.9lf\n",cas,(double)m-bx);
		cout<<setprecision(9);
		cout<<"Case #"<<cas<<": "<<(double)m-bx<<endl;
	}

	return 0;

} 


