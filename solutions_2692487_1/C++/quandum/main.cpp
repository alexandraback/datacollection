#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 103
using namespace std;
int n,a,t[maxn],res;
int f[maxn],m[maxn];
int getmax(int a,int b){if (a>b) return a; return b;}
int getmin(int a,int b){if (a<b) return a; return b;}
void process(){
    sort(t,t+n);  int i,j;
    if (a<=1){res=n;return;}
    for (i=n;i>0;i--) t[i]=t[i-1];
    t[0]=a; m[0]=a; f[0]=0;
    for (i=1;i<=n;i++){
        m[i]=m[i-1]; f[i]=f[i-1];
        while (m[i]<=t[i]){
            f[i]++;     m[i]=(m[i]*2)-1;
        }
        m[i]+=t[i];
    }
    res=f[n];
    for (i=1;i<=n;i++) res=getmin(res,f[i-1]+(n-i+1));
}
int main(){
    freopen("A-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    int test,ntest,i;     scanf("%d",&ntest);
    for (test=1;test<=ntest;test++){
        scanf("%d%d",&a,&n);
        for (i=0;i<n;i++) scanf("%d",&t[i]);
        process();
        if (test>1) printf("\n");
        printf("Case #%d: %d",test,res);
    }
    fclose(stdin);              fclose(stdout);
	return 0;
}
