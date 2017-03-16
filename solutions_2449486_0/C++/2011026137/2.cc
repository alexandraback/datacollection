#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int a[106][106],num[105];
bool b1[106],b2[106];
void init(){
    memset(a,0,sizeof(a));
    memset(num,0,sizeof(num));
}
bool slove(int x,int n,int m){
    int i,j,s=0,s1=0,s2=0;
    memset(b1,0,sizeof(b1));
    memset(b2,0,sizeof(b2));
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++)
            if(a[i][j]!=x)
                break;
        if(j>m)
            b1[i]=1;
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++)
            if(a[j][i]!=x)
                break;
        if(j>n)
            b2[i]=1;
    }
    for(i=1;i<=n;i++)
        s1+=b1[i];
    for(i=1;i<=m;i++)
        s2+=b2[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i][j]==x){
                s++;
                a[i][j]++;
            }
    if(s1*m+s2*n-s1*s2==s)
        return 1;
    return 0;
}
int main(){
    freopen("out.out","w",stdout);
    int i,j,k,n,m,T;
    scanf("%d",&T);
    for(int ii=1;ii<=T;ii++){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++){
                scanf("%d",&a[i][j]);
                num[a[i][j]]++;
            }
        for(i=1;i<=100;i++)
            if(!slove(i,n,m))
                break;
        if(i==101)
            printf("Case #%d: YES\n",ii);
        else
            printf("Case #%d: NO\n",ii);
    }
    return 0;
}
