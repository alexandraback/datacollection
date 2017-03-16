#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <fstream>
#include <vector>
using namespace std;
#define fon(i,n) for(i=0;i<n;++i)
#define re return
#define ll long long
#pragma comment(linker, "/stack:64000000")
const double EPS = 1E-9;const int INF = 1000000000;const ll INF64 = (ll)1E9,IK=(ll)1E18;const double PI = 3.1415926535897932384626433832795;
//typedef struct{int a;}tpo;typedef map<double,tpo> tmap;

ll bp(ll n,ll r0,ll t){
	if(2*r0*n+2*n*n-n>t)--n;
	ll l=n,r=INF64;
	ll d1=0,d2=9,k;for(k=r0;k>0;k/=10)d1++;

	while(d1+d2>19){r/=10;d2--;}
//	r=IK/r0;
	while(r-l>1){
		ll s=(r+l)/2;
		ll fs=2*r0*s+2*s*s-s;
		if(fs>t)r=s;
		else l=s;
	}
	ll or=2*r0*r+2*r*r-r;
	if(or<=t)re r;
	if(2*r0*l+2*l*l-l>t)re 0;
	re l;
}
int main()
{
	#ifndef ONLINE_JUDGE
	ifstream cin("A-large.in");
	//ifstream cin("input.txt");
	ofstream cout("output.txt");
	#endif

	ll i,j,n,c,k,f,t0,T;
	int *a=new int[2000000];
	cin>>T;
	fon(t0,T){
		ll r,t,r1=0;
		cin>>r>>t;
		//++r;
		/*ll D=(2*r-1)*(2*r-1)+4*2*t;
		double dd=sqrt((double)D);//if(dd*dd!=D)dd++;
		ll sum=(-(2*r-1)+dd)/4;
		if(2*r*sum+2*sum*sum-sum>t){while(2*r*sum+2*sum*sum-sum>t)sum--;}
		else if(2*r*(sum+1)+2*(sum+1)*(sum+1)-(sum+1)<=t)sum++;
		*/
		double n0=-(2*r-1)/(2*t);
		if(n0<0)n0=0;
		cout<<"Case #"<<t0+1<<": "<<bp((n0),r,t)<<endl;
	}
	re 0;
}