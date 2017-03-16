#include<stdio.h>
const char inf[]="B-large.in";
const char ouf[]="B-large.out";
const int maxn=10000;

int T;
int n,E,R;
int a[maxn+10];

long long list[maxn+10];
long long val[maxn+10];

long long ans;

void input(){    
    int i;
    scanf("%ld%ld%ld",&E,&R,&n);
    for(i=1;i<=n;i++)
	scanf("%ld",a+i);   
}

void work(){
    int i,j,k,s,t;
    long long rest,offset,now,tmp;
    t=0;s=1;rest=E;offset=0;ans=0;
    for(i=1;i<=n;i++){
        list[++t]=i;
        val[t]=rest;
        while((t>s) && (a[list[t]]>=a[list[t-1]])){
            t--;
            list[t]=list[t+1];
            val[t]=val[t+1];
        }
        if(rest-offset+R>E){
            now=rest-offset+R-E;
            while(now>0){
                if(now>=val[s]-offset){
                    tmp=val[s]-offset;
                    offset+=tmp;
                    now-=tmp;
                    ans+=tmp*a[list[s]];
                    s++;
                }else{
                    ans+=now*a[list[s]];
                    offset+=now;
                    now=0;
                }
            }
        }
        rest+=R;
    }
    rest-=R;
    while(rest>offset){
        if(rest-offset>=val[s]-offset){
            tmp=val[s]-offset;
            offset+=tmp;
            ans+=tmp*a[list[s]];
            s++;
        }else{
            ans+=(rest-offset)*a[list[s]];
            offset=rest;
        }
    }
}

void output(){
    printf("Case #%ld: %I64d\n",T,ans);
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
