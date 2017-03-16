#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;
const int N = 1000005;
int t,cas=0;
char str[N];
int n;
bool flag[150]={0};
int main(){
    //freopen("A-small-attempt1.in","r",stdin);
    //freopen("out.txt","w",stdout);
    flag['a']=flag['e']=flag['i']=flag['o']=flag['u']=true;
    scanf("%d",&t);
    while(t--){
        scanf("%s%d",str,&n);
        int h=0,t=0;
        int l=strlen(str);
        LL ans=0;
        for(int i=0;i<l;i++){
            h=max(h,i);
            if(t-h<n){
                while(h<l&&t<l&&t-h<n){
                    h=t;
                    while(h<l&&flag[str[h]]) h++;
                    t=h;
                    while(t<l&&!flag[str[t]]) t++;
                }
                if(t-h<n) break;
            }
            ans+=l-1-(h+n-1)+1;
        }
        printf("Case #%d: %lld\n",++cas,ans);
    }
    return 0;
}