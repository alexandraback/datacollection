//This code was writen by Alexander Dryapko (sdryapko)
#include<sstream>
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>                             	
#include<set>               
#include<string>
#include<string.h>  
#define gcd(a,b) __gcd((a),(b));
#define sqr(a) ((a)*(a))
#define odd(a) ((a)&1)
#define pw2(x) (1ll<<(x))
#define F first
#define S second
const int maxi=2000000000;              
const int maxq=1000000000;
const double eps=1e-10;       
const double pi=3.1415926535897932;
const double inf=1e+18;
const int mo=1000000007;

using namespace std;
double p[1111111],f[1111111];
int t,a,b;
int main(){                 
        freopen("input.txt","r",stdin);      
        freopen("output.txt","w",stdout); 
        cin>>t;
        for (int tt=1;tt<=t;tt++) {
        	scanf("%d%d",&a,&b);
        	for (int i=1;i<=a;i++) cin>>p[i];
               
                double _min=inf;
          	f[0]=1;
           	for (int i=1;i<=a;i++) f[i]=f[i-1]*p[i];
        
           	for (int i=1;i<=a+1;i++) {
           		double ans=f[i-1]*((a-i+1)+(b-i+1)+1);
          // 		cout<<ans<<endl;
           		ans=ans+(1-f[i-1])*((a-i+1)+(b-i+1)+b+2);
           		_min=min(_min,ans);
           	}
           	_min=min(_min,(double)b+2);
           	cout.precision(8);
           	cout<<"Case #"<<tt<<": "<<_min<<endl;
        }           		
       	return 0;
}
