#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define N 1000
using namespace std;
struct emp {
	int x,y;
};
emp my[N];
int n,m,k,cnt,maxx;
int a[N*N];
char mo[N],ta[N],b[N];
double ans;
int f(){
    int i,j,x,y;
    x=0;
    y=k-m+1;
    for(i=0;i<y;i++){
        for(j=0;j<m;j++){
            if(ta[j]!=b[i+j]) break;
        }
        x+=(j==m)?1:0;
    }
    return x;
}
void make_ans(int ct){
    int i;
    if(ct>=k){
        a[cnt++]=f();
        maxx=maxx>a[cnt-1]?maxx:a[cnt-1];
        return;
    }
    for(i=0;i<n;i++){
        b[ct]=mo[i];
        make_ans(ct+1);
    }
}
void solve(){
    int i;
    cnt=0;
    maxx=0;
    make_ans(0);
    ans=0.0;
    for(i=0;i<cnt;i++) ans +=(maxx-a[i]);
    ans=ans/cnt;
}

int main(){
	int i,tn;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&tn);
	for(i=1;i<=tn;i++){
        scanf("%d %d %d",&n,&m,&k);
        scanf("%s %s",mo,ta);
		solve();
		printf("Case #%d: %lf\n",i,ans);
	}
	return 0;
}
