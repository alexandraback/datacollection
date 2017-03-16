#include <iostream>
#include <stdio.h>
#include <algorithm>
#define ll long long
#define maxn 100010
using namespace std;
int d[5][5]={
    {0,0,0,0,0},
    {0,1,2,3,4},
    {0,2,-1,4,-3},
    {0,3,-4,-1,2},
    {0,4,3,-2,-1}
};
int change(char x){
    switch(x)
    {
        case '1':return 1;break;
        case 'i':return 2;break;
        case 'j':return 3;break;
        case 'k':return 4;break;
    }
    return 0;
}
char str[maxn];
int a[maxn],pre[maxn],last[maxn];
int op(int x,int y){
    int tx=x>0?x:-x;
    int ty=y>0?y:-y;
    if(x*y>0)
    return d[tx][ty];
    return -d[tx][ty];
}
int mut(int x,int n){
    int tmp=1;
    while(n--){
        tmp=op(tmp,x);
    }
    return tmp;
}
int getop(int l,int r){
    int tmp=mut(last[r+1],3);
    return op(last[l],tmp);
}
bool check(int n,ll num,int ord){

    int st,mid,ed;
    for(int i=0;i<4;i++){
        st=mut(ord,i);
        for(int j=0;j<4;j++){
            ed=mut(ord,j);
                for(int x=0;x<=n;x++){
                    if(op(st,pre[x])==2){
                        for(int y=1;y<=n+1;y++){
                            if(op(last[y],ed)==4){
                                //下面两种情况
                                if(x+1<=y-1&&(num>=i+j+1&&(num%4==(i+j+1)%4))){
                                    if(getop(x+1,y-1)==3)
                                    return true;
                                }
                                for(int k=0;k<4;k++){
                                    mid=mut(ord,k);
                                    if(op(op(last[x+1],mid),pre[y-1])==3){
                                        if(num>=i+j+k+2&&(num%4==(i+j+k+2)%4))
                                        return true;
                                    }
                                }

                            }
                        }
                    }
                }

        }
    }
    return false;
}
int main(){
    freopen("dd.in","r",stdin);
    freopen("out.txt","w+",stdout);
    int ncase,T=0;
    scanf("%d",&ncase);
    while(ncase--){
        printf("Case #%d: ",++T);
        int L;
        ll x;
        cin>>L>>x;
        scanf("%s",str+1);
        for(int i=1;i<=L;i++){
            a[i]=change(str[i]);
        }
        pre[0]=1;
        for(int i=1;i<=L;i++){
            pre[i]=op(pre[i-1],a[i]);
        }
        last[L+1]=1;
        for(int i=L;i>=1;i--){
            last[i]=op(a[i],last[i+1]);
        }
        if(check(L,x,pre[L]))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
