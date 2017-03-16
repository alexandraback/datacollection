#include <iostream>
#include <vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>
#define mp(a,b) make_pair(a,b)
#define xx first
#define yy second
using namespace std;
typedef long long LL;
typedef double db;
char c[1006][22],d[1006][22];
int ch[22*20][26];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t,N=0;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            scanf("%s",c[i]);
            scanf("%s",d[i]);
        }
        int p=1<<n;
        int ans=0;
        for(int i=1;i<p;i++){
            int f=0;
            int s=0;
            for(int j=0;j<n;j++){
                if((i&(1<<j))==0){
                    s++;
                    int x=0,y=0;
                    for(int w=0;w<n;w++){
                        if((i&(1<<w))){
                            if(x==0&&strcmp(c[j],c[w])==0){
                                x=1;
                            }
                            if(y==0&&strcmp(d[j],d[w])==0){
                                y=1;
                            }
                            if(x==1&&y==1) break;
                        }
                    }
                    if(x==0||y==0){
                        f=1;
                        break;
                    }
                }
            }
            if(f==0){
                ans=max(ans,s);
            }
        }
        printf("Case #%d: %d\n",++N,ans);
    }
}