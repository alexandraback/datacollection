#include<stdio.h>
const char inf[]="B-small-attempt1.in";
const char ouf[]="B-small-attempt1.out";
const int maxn=10000;
const int maxE=5;
const int INF=1<<30;

int T;
int n,E,R;
int a[maxn+10];

int f[maxn+1][maxE+1];

int ans;

void input(){    
    int i;
    scanf("%ld%ld%ld",&E,&R,&n);
    for(i=1;i<=n;i++)
	scanf("%ld",a+i);   
}

void work(){
    int i,j,k,now,next;
    for(i=0;i<=n;i++)
        for(j=0;j<=E;j++)
            f[i][j]=-INF;
    f[0][E]=0;
    for(i=0;i<n;i++){
        for(j=0;j<=E;j++){
            if(f[i][j]>=0){
                for(k=0;k<=j;k++){
                    now=f[i][j]+k*a[i+1];
                    next=j-k+R;
                    if(next>E)
                        next=E;
                    if(now>f[i+1][next])
                        f[i+1][next]=now;
                }
            }
        }
    }
    ans=0;
    for(i=0;i<=E;i++)
        if(f[n][i]>ans)
            ans=f[n][i];
}

void output(){
    printf("Case #%ld: %ld\n",T,ans);
}

int main(){
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    int totT;
    scanf("%ld",&totT);
    for(T=1;T<=totT;T++){
	input();
	work();
	output();
    }
    return 0;
}
