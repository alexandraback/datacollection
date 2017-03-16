#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define ll long long
#define ull long long
#define inf 1000000007
#define mod 1000000007
#define DBG(x) cerr<<#x<<"="<<x<<"\n";
#define FOREACH(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define N 10005

int b[10][10],ne[10][10],pr[10][10],a[N],f[N],h[N];
vi v[10];
int main()
{
    freopen("input.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T,i,j,k,m=8,ca=0,n;
    map<char,int>g;
    g['i']=2,g['j']=3,g['k']=4;
    for(i=1;i<=8;i++)b[1][i]=i;
    b[2][1]=2,b[2][2]=5,b[2][3]=4,b[2][4]=7;
    b[2][5]=6,b[2][6]=1,b[2][7]=8,b[2][8]=3;
    b[3][1]=3,b[3][2]=8,b[3][3]=5,b[3][4]=2;
    b[3][5]=7,b[3][6]=4,b[3][7]=1,b[3][8]=6;
    b[4][1]=4,b[4][2]=3,b[4][3]=6,b[4][4]=5;
    b[4][5]=8,b[4][6]=7,b[4][7]=2,b[4][8]=1;
    for(i=5;i<=8;i++)
        for(j=1;j<=8;j++)b[i][j]=b[i-4][j]>4?b[i-4][j]-4:b[i-4][j]+4;
    for(int s=1;s<=8;s++)
        for(i=1;i<=8;i++)
            for(j=1;j<=8;j++)
                if(b[i][j]==s)ne[s][i]=j,pr[s][j]=i;
    scanf("%d",&T);
    while(T--){
        ll K;
        cin>>n>>K;
        getchar();
        for(i=0;i<n;i++){
            char c;scanf("%c",&c);
            a[i]=g[c];
        }
        for(i=1;i<=8;i++)v[i].clear();
        f[0]=a[0];v[a[0]].pb(0);
        for(i=1;i<n;i++)f[i]=b[f[i-1]][a[i]],v[f[i]].pb(i);
        h[n-1]=a[n-1];
        for(i=n-2;i>=0;i--)h[i-1]=b[a[i]][h[i+1]];
        int s=f[n-1],x=s;
        int cnt=1,p[11];
        while(x!=1)cnt++,x=b[x][s];
        p[0]=1;
        for(i=1;i<=cnt;i++)p[i]=b[p[i-1]][s];
        int ok=0;
        for(int l=0;l<=cnt&&l<=K;l++){
            int x=ne[2][p[l]];
            //cerr<<l<<" "<<x<<".(x).";
            if(v[x].size()==0)continue;
            for(int r=0;r<=cnt&&r+l<K;r++){
                int y=pr[4][p[r]];
                //cerr<<r<<" "<<y<<".(y).\n";
                if(v[y].size()==0)continue;
                if(l+r+1==K){
                    if(s!=5)continue;
                    if(v[x][0]<v[y][v[y].size()-1]){ok=1;break;}
                }
                else{
                    int z=(K-l-r-2)%cnt;
                    z=b[ne[s][x]][p[z]];
                    z=b[z][pr[s][y]];
                    if(z==3){
                        ok=1;break;
                    }
                }
            }
            if(ok)break;
        }
        printf("Case #%d: %s\n",++ca,ok?"YES":"NO");
    }
    return 0;
}