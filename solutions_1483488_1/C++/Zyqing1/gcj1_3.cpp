#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int length(int x){
    if(x==0) return 1;
    int ret=0;
    while(x>0){
        ret++;
        x/=10;
    }
    return ret;
}
int Rank(int x)
{
    int ret=1;
    while(x>0){
        ret*=10;
        x/=10;
    }
    return ret;
}
int main()
{
    //freopen("C-large.in","r",stdin);
    //freopen("C-large.out","w",stdout);
    int T,A,B;
    cin>>T;
    for(int cas=1;cas<=T;cas++){
        int ans=0,pt=0;
        cin>>A>>B;
        for(int i=A;i<B;i++){
            int len,r,n=i;
            int rep[10],num=0;
            len=length(n)-1;
            r=Rank(n/10);
            while(len--){
                int m=(n%10)*r+n/10;
                if(i<m && m<=B){
                    ans++;
                    rep[num++]=m;
                    for(int j=0;j<num-1;j++){
                        if(rep[j]==m){
                            ans--,num--;
                            break;
                        }
                    }
                    //printf("%d,%d\n",i,m);
                }
                n=m;
            }
        }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
