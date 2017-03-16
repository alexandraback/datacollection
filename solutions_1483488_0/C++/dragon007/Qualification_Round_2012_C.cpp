#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t;
    freopen("C-small-attempt0.in","r",stdin);
    freopen("3.out","w",stdout);
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        int a,b;
        int ans=0;
        int s[8];
        scanf("%d%d",&a,&b);
        for (int j=a;j<=b;j++){
            int k=j,l=0,m=0,ex=1,ex1=1,pq[8],ts=0;
            while (k>0) s[l++]=k%10,k/=10,ex1*=10;
            if (l==1) continue;
            for (int w=0;w<l;w++){
                m=m+s[w]*ex;
                ex*=10;
                ex1/=10;
                if (s[w]==0) continue;
                int k=m*ex1+j/ex;
                if (k>j && k<=b){
                    bool flag=false;
                    for (int tt=0;tt<ts;tt++)
                        if (pq[tt]==k){
                            flag=true;
                            break;
                        }
                    if (flag) continue;
                    pq[ts++]=k;
                    ans++;
                }
            }
        }
        printf("Case #%d: %d\n",i+1,ans);
    }
    return 0;
}
