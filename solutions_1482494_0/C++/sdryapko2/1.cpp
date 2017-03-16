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
int  a[55555],tt,b[55555],n;
bool one[55555],two[55555];
int main(){                 
        freopen("input.txt","r",stdin);      
        freopen("output.txt","w",stdout); 
        scanf("%d",&tt);
        for (int t=1;t<=tt;t++) {
        	scanf("%d\n",&n);
        	for (int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
                for (int i=1;i<=n;i++) one[i]=0,two[i]=0;
                int kol=0;
          	for (int it=1;it<=3000;it++) {
        		bool flag=false;
        		for (int i=1;i<=n;i++) if (two[i]==false&&kol>=b[i]) 
        		{
        			if (one[i]) kol++; else kol+=2;
        			two[i]=true;
        			one[i]=true;
        			flag=true;
        			break;
        		}
        		if (flag) {
        			bool ok=true;
        			for (int i=1;i<=n;i++) if (!two[i]) ok=false;
        			if (ok) {
        				printf("Case #%d: %d\n",t,it);
        				break;
        			}
        			continue;
        		}
        		int nom=-1;
        		int ma=0;
        		for (int i=1;i<=n;i++) if (one[i]==false&&kol>=a[i]&&b[i]>ma) {
        			ma=b[i];
        			nom=i;
        		}
        		if (nom>0) {
        			flag=true;
        			one[nom]=true;
        			kol++;
        	 	}
        		if (flag) {
       				bool ok=true;
        			for (int i=1;i<=n;i++) if (!two[i]) ok=false;
        			if (ok) {
        				printf("Case #%d: %d\n",t,it);
        				break;
        			}
        			continue;
        		}
        		if (flag==false) {
        			
        			printf("Case #%d: Too Bad\n",t);
        			break;
        		}
        	}
        }			

       	return 0;
}
