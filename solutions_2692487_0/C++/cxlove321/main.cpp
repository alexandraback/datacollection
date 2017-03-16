#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define LL long long
#define eps 1e-6
using namespace std;
int t,cas=0,m,n,a[100];
int cnt[1024];
int main(){
    //freopen("A-small-attempt0.in","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<1024;i++)
        cnt[i]=cnt[i>>1]+(i&1);
    while(t--){
        scanf("%d%d",&m,&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        int ans=1<<20;
        for(int s=0;s<(1<<n);s++){
            vector<int>v;
            for(int j=0;j<n;j++){
                if(!(s&(1<<j)))
                    v.push_back(a[j]);
            }
            int temp=cnt[s],p=m;
            for(int i=0;i<v.size();i++){
                if(p>v[i])
                    p+=v[i];
                else{
                    if(p-1==0){
                        temp=1<<20;
                        break;
                    }
                    temp++;
                    p+=p-1;
                    i--;
                }
            }
            ans=min(temp,ans);
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}