#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

map<int,int> ma;
vector<int> st[1200000];
int a[30];
int n,nn;

bool check(int id,int sta){
    for (int i=0;i<st[id].size();++i)
        if ((sta&st[id][i])==0){
            int fi=0;
            for (int j=0;j<n;++j)
                if (sta&(1<<j)){
                    if (fi==0) fi=1;
                    else printf(" ");
                    printf("%d",a[j]);
                }
            puts("");
             fi=0;
            for (int j=0;j<n;++j)
                if (st[id][i]&(1<<j)){
                    if (fi==0) fi=1;
                    else printf(" ");
                    printf("%d",a[j]);
                }
            puts("");        
            return true;
        }
    st[id].push_back(sta);
    return false;
}
            
int main(){
    
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    
    int _,cas=0;
    scanf("%d",&_);
    while (_--){
        ma.clear();
        for (int i=0;i<1200000;++i) st[i].clear();
        nn=0;
        
        printf("Case #%d:\n",++cas);
        scanf("%d",&n);
        
        int sum=0;
        for (int i=0;i<n;++i) scanf("%d",&a[i]);
        
        int ans=-1;
        for (int sta=1;sta<(1<<n)-1;++sta){
            int tmp=0;
            for (int i=0;i<n;++i)
                if ((1<<i) & sta) tmp+=a[i];
            if (ma.find(tmp)==ma.end()) ma[tmp]=(++nn);
            else{
                int id=ma[tmp];
                if (check(id,sta)){ 
                    ans=0;
                    break;
                }   
            }
        }
        if (ans==-1) puts("Impossible");
    }
    return 0;
}
        
