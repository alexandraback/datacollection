#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
char c[10005];
int s[10005];
int a[5][5];
typedef long long LL;
int get(char c){
    if(c=='1') return 1;
    if(c=='i') return 2;
    if(c=='j') return 3;
    return 4;
}
int suan(int n,int m){
    int s=a[abs(n)][abs(m)];
    if(n*m<0) s=-s;
    return s;
}
int main()
{
    int i,j,t,n,N=0;
    LL m;
    cin>>t;
    for(i=1;i<=4;i++) a[1][i]=i;
    a[2][2]=-1;
    a[2][3]=4;
    a[2][4]=-3;
    a[3][2]=-4;
    a[3][3]=-1;
    a[3][4]=2;
    a[4][2]=3;
    a[4][3]=-2;
    a[4][4]=-1;
    for(i=2;i<=4;i++) a[i][1]=i;
    while(t--){
        cin>>n>>m;
        printf("Case #%d: ",++N);
        scanf("%s",c);
        s[0]=get(c[0]);
        for(i=1;i<n;i++){
            int p=get(c[i]);
            s[i]=suan(s[i-1],p);
        }
        if(s[n-1]==-1&&m%2==0){
            printf("NO\n");
            continue;
        }
        if(s[n-1]==1||s[n-1]!=-1&&(m%4!=2)){
            printf("NO\n");
            continue;
        }
        int x=-1,y=-1;
        for(i=0;i<n;i++){
            if(s[i]==2&&x==-1){
                x=i;
            }
            if(s[i]==4){
                y=i;
            }
        }
        int f=0;
        if(x==-1){
            for(i=0;i<n;i++){
                int p=s[n-1];
                for(j=0;j<3&&j<m;j++){
                    int q;
                    q=suan(p,s[i]);
                    if(q==2){
                        if(x==-1) x=(j+1)*n+i;
                        else if(x>(j+1)*n+i) x=(j+1)*n+i;
                    }
                    p=suan(p,s[n-1]);
                }
            }
        }
        if(y==-1){
            for(i=0;i<n;i++){
                int p=s[n-1];
                for(j=0;j<3&&j<m;j++){
                    int q;
                    q=suan(p,s[i]);
                    if(q==4){
                        y=max(y,(j+1)*n+i);
                    }
                    p=suan(p,s[n-1]);
                }
            }
        }
        if(x==-1||y==-1) f=1;
        else{
            if(x>=y){
                if(s[n-1]==1){
                    int p=(x-y)/n;
                    p++;
                    if(y/n+1+p>m){
                        f=1;
                    }
                }
                else if(s[n-1]==-1){
                    int p=(x-y)/(2*n);
                    p++;
                    if(y/n+1+2*p>m){
                        f=1;
                    }
                }
                else{
                int p=(x-y)/(4*n);
                p++;
                if((y/n+1)+4*p>m){
                    f=1;
                }
                }
            }
        }
        if(f) printf("NO\n");
        else printf("YES\n");
    }
}
