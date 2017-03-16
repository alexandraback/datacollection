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


int main()
{
	#ifndef ONLINE_JUDGE
	ifstream cin("A-large(1).in");
	//ifstream cin("input.txt");
	ofstream cout("output.txt");
	#endif

	ll i,j,n,c,k,f,t0,T;
	ll a[200],A;
	cin>>T;
	fon(t0,T){
		ll r,t,r1=0;
		cin>>A>>n;fon(i,n)cin>>a[i];
		sort(a,a+n);

		ll A2=A;
		for(i=0;i<n&&A2>a[i];++i)A2+=a[i];
		if(i>=n)cout<<"Case #"<<t0+1<<": "<<0<<endl;
		else{
			if(A2>1){
				ll h=0,A22,lmin=n-i;
				for(j=i;j<n;++j)if(A2<=a[j]){
					for(;A2<=a[j];h++)
						A2=2*A2-1;
					for(A22=A2,k=j;k<n&&a[k]<A22;++k)
						A22+=a[k];
					if(h+n-k<lmin)lmin=h+n-k;
					A2+=a[j];
				}else A2+=a[j];
				cout<<"Case #"<<t0+1<<": "<<lmin<<endl;
			}else cout<<"Case #"<<t0+1<<": "<<n<<endl;
		}
	}
	re 0;
}