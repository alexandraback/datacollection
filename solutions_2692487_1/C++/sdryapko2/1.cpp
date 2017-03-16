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
#define gcd(a,b) __gcd((a),(b))
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
int n,a[111111],tt;
long long k,f[111][111];
int main(){                 
        freopen("input.txt","r",stdin);      
        freopen("output.txt","w",stdout); 
        scanf("%d",&tt);
        for (int t=1;t<=tt;t++) {
        	scanf("%d%d",&k,&n);
        	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        	sort(a+1,a+n+1);
        	memset(f,255,sizeof(f));
        	f[0][0]=k;
        	a[0]=0;
        	int flag=-1;
        	for (int i=0;i<=n;i++) for (int j=0;j<=n;j++) {
        		if (i&&f[i-1][j]>a[i]&&f[i-1][j]>0) {
        			f[i][j]=max(f[i][j],f[i-1][j]+a[i]);
        			flag=i;
        		}
        		if (j&&i) f[i][j]=max(f[i][j],f[i-1][j-1]);
        		if (j>0&&f[i][j-1]>0) {
        			if (f[i][j-1]*2-1<=a[i]||flag==i) f[i][j]=max(f[i][j],f[i][j-1]*2-1); 
        		        else {
        		        	f[i][j]=max(f[i][j],f[i][j-1]*2-1+a[i]);
        		      		flag=i;
        		        }
        		}
        	//	cout<<i<<' '<<j<<' '<<f[i][j]<<endl;
        	}
        	for (int i=0;i<=n;i++) if (f[n][i]>0) 
        	{		
  	   		printf("Case #%d: %d\n",t,i);
  	   		break;
  	   	}
        }
       	return 0;
}
