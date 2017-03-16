
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
#define FOR(a,start,end) 	for(ll a=ll(start); a<ll(end); a++)
#define INF 		int_MAX
#define SORT(a) 	sort(a.begin(),a.end())
#define CL(a,x) 		memset(a,x,sizeof(a))
#define REP(a,x)	for(ll a=0;a<x;a++)
#define REP1(a,x)	for(ll a=1;a<=x;a++)
#define MP 		make_pair
#define vi vector<ll>
#define vvi vector<vector<ll> >
#define vii vector<pair<ll,ll> >
#define vvii vector<vector<pair<ll,ll> > >
#define pii pair<ll,ll>
#define vs vector<string>
ll s,c,i,k,j,n,m,z,jx,z0,b,a0,b0,z1,c2; 
ll t,cas,i1,i2,i3,c0;
vvi vvk,vvc;
vii vp,vp2;
pii p1,p2;
vector<pair<ll,ll> > vpk;
vs ve;
string wy,wyb,we;
vs vsl,vt;
vi vk,vk1,vk2,vm,vc;
ll k1,k2,k3,p;
ll a1,a2;
vector<ll> vz,vz2;
ll zx,d,d2,d1,a,r,c1;
vector<pair<char,ll> > vkc;
vector<vector<pair<char,ll> > > vvkc;
char zn;
double dx,ax;
ll ta[80],tb[80],tc[80];

ll gcd(ll a, ll b){
	ll k,m;

		if(a>b){
			k=a;
			a=b;
			b=k;
		}
		k=b%a;
		if(k==0)
            return a;
		else {
			while(k!=0){
				m=k;
				b=a;
				a=k;
				k=b%a;
			}
			return m;
		}
}

int main() {  
	freopen( "c:\\wojtek\\uva\\uva\\debug\\b0.in", "rt", stdin); 
	
	//pi=2*acos(0.0);
	//while(1){
	//	vk.clear(); 
	//d=1000000007; 
	 
	cin>>t;
	//scanf("%d",&t); 

	for(cas=1;cas<=t;cas++){

		cin>>we;
	
		i=0;
		a=0;
		k=we.size();
		while(we[i]!='/'){
			a*=10;
			a+=we[i]-'0';
			i++;
		}
		b=0;
		i++;
		while(i<k){
			b*=10;
			b+=we[i]-'0';
			i++;
		}

		k=gcd(a,b);
		a/=k;
		b/=k;
		d=1;
		z=0;
		while(d<b){
			d*=2;
			z++;
		}
		
		while(a>1){
			a/=2;
			z--;
		}
		if(d==b){
			cout<<"Case #"<<cas<<": "<<z<<endl;
		}
		else {
			cout<<"Case #"<<cas<<": impossible"<<endl;
		}
		

	}
	 


	return 0;

} 
