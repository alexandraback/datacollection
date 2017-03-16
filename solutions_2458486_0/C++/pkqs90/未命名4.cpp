#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#define  ll  long long
#define  pb  push_back
using namespace std;
bool flag[1048999],FLAG;
int t,k,n,x,y,key[201],id[25],ans[25];
vector<int>e[25];
void init(){
     memset(key,0,sizeof(key));
     memset(id,0,sizeof(id));
     memset(flag,0,sizeof(flag));
     for(int i=1;i<=n;i++)e[i].clear();
     FLAG=false;
}
void go(int num,int status){
     //cout<<num<<' '<<status<<endl;
     if(FLAG||flag[status])return;
     if(num==n){
        for(int i=1;i<=n;i++)
           printf("%d%c",ans[i],i==n?'\n':' ');
        FLAG=true;
        return;
     }
     bool f=false;
     for(int i=1;i<=n;i++)if(!(status&(1<<(i-1)))&&key[id[i]]){
        ans[num+1]=i,key[id[i]]--;
        for(int j=0,l=e[i].size();j<l;j++)key[e[i][j]]++;
        go(num+1,status|(1<<(i-1)));
        for(int j=0,l=e[i].size();j<l;j++)key[e[i][j]]--;
        key[id[i]]++,f=true;
     }
     flag[status]=true;
}
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin>>t;
    for(int p=1;p<=t;p++){
       cin>>k>>n;
       init();
       for(int i=1;i<=k;i++){
          cin>>x;key[x]++;
       }
       for(int i=1;i<=n;i++){
          cin>>id[i]>>y;
          for(int j=1;j<=y;j++){
             cin>>x;e[i].pb(x);
          }
       }
       printf("Case #%d: ",p);
       go(0,0);
       if(!FLAG)printf("IMPOSSIBLE\n");
    }
    //system("pause");
    return 0;
}
