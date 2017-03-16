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
int tt,n,x,y,a[1111][1111];
double ans=0;
void dfs(int k,int x,int y,double ver) {
	if (k>n) return;
	//cout<<k<<' '<<x<<' '<<y<<' '<<ver<<endl;
	if (y) {
		if (a[x-1][y-1]) {
			if (a[x+1][y-1]) {
				a[x][y]=1;
				if (x-60==::x&&y==::y) ans=ans+ver;
				dfs(k+1,60,60,ver);
				a[x][y]=0;
				return;
			}
			dfs(k,x+1,y-1,ver);
			return;
		}
		if (a[x+1][y-1]) {
			dfs(k,x-1,y-1,ver);
			return;
	        }
	}
	if (a[x][y-2]) {
		dfs(k,x-1,y-1,ver/2);
		dfs(k,x+1,y-1,ver/2);
		return;
	}
	if (y==0) {
		a[x][y]=1;
		if (x-60==::x&&y==::y) ans=ans+ver;
		dfs(k+1,60,60,ver);
		a[x][y]=0;
		return;
        }
        dfs(k,x,y-1,ver);
}
int main(){                                                     
        freopen("input.txt","r",stdin);      
        freopen("output.txt","w",stdout); 
        scanf("%d\n",&tt);
        for (int t=1;t<=tt;t++) {
        	scanf("%d%d%d\n",&n,&x,&y);
        	ans=0;
        	dfs(1,60,60,1.0);
        	printf("Case #%d: %.8lf\n",t,ans);
        }
       	return 0;
}
