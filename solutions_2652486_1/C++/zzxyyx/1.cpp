#include<stdio.h>
#include<algorithm>
int a[10],r,n,m,k;
bool jud(int a1,int a2,int a3,int x){
    if(x==1||x==a1||x==a2||x==a3)return 1;
    if(a1*a2==x||a1*a3==x||a2*a3==x||a1*a2*a3==x)return 1;
    return 0;
}

int main(){
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
    int i,j,u,v;
    scanf("%d",&i);
    puts("Case #1:");
    scanf("%d%d%d%d",&r,&n,&m,&k);
    while(r--){
        for(i=0;i<k;i++)scanf("%d",&a[i]);
        for(int i1=2;i1<=m;i1++)
            for(int i2=i1;i2<=m;i2++)
                for(int i3=i2;i3<=m;i3++){
                    for(i=0;i<k;i++)
                        if(!jud(i1,i2,i3,a[i]))
                            break;
                    if(i==k){printf("%d%d%d\n",i1,i2,i3);i1=i2=i3=m+10;}
                }
        }
    return 0;
}
