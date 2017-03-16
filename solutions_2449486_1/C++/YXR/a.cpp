#include <iostream>
#include <cstdio>
#include <cstring>
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int n,m,ca,ok,ma;
int a[200][200];
int b[200][200];
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d\n",&ca);
	fo(ii,1,ca){
		ok=0;
		printf("Case #%d: ",ii);
		scanf("%d %d\n",&n,&m);
		fo(i,1,n) fo(j,1,m) scanf("%d",&a[i][j]);
		memset(b,0,sizeof(b));
		fo(i,1,n) {
			ma=0;
			fo(j,1,m){
				if (a[i][j]>ma) ma=a[i][j];
			}
			fo(j,1,m) if(a[i][j]>=ma) b[i][j]=1;
		} 
		fo(j,1,m) {
			ma=0;
			fo(i,1,n){
				if (a[i][j]>ma) ma=a[i][j];
			}
			fo(i,1,n) if(a[i][j]>=ma) b[i][j]=1;
		} 
		fo(i,1,n) {
			fo(j,1,m) if (b[i][j]==0) ok=1;
		} 
		if (ok==1) printf("NO\n");
		else printf("YES\n");
	}
}
