#include<cstdio>
#include<iostream>
using namespace std;

int in[205];
double tta[205],ttb[205];
bool flag[205];

int main (){
    freopen("a.l.in","r",stdin);
    freopen("a.l.out","w",stdout);
    int cas,c;
    double key;
    scanf("%d",&cas);
    for(c=1;c<=cas;c++){
        int n,sum=0,qq,num,i;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            flag[i]=1;
            scanf("%d",&in[i]);
            sum+=in[i];
        }
        qq=sum;
        num=n;
        for(i=1;i<=n;i++)
            ttb[i]=double(in[i])/sum;
        key=2.0/n;
        for(i=1;i<=n;i++){
            if(key<=ttb[i]){
                tta[i]=0;
                flag[i]=0;
                num--;
                qq-=in[i];
            }
        }
        key=(0.0+sum+qq)/num;
        for(i=1;i<=n;i++)
            if(flag[i])
                tta[i]=(key-in[i])/sum;
        printf("Case #%d:",c);
        for(i=1;i<=n;i++)
            printf(" %.6lf",tta[i]*100);
        printf("\n");
    }
    return 0;
}
