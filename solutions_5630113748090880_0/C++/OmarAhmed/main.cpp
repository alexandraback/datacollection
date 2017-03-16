#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n ,vis[2555],t,a;
int main()
{
    //freopen("in.txt","r",stdin);
       // freopen("out.txt","w",stdout);
scanf("%d",&t );

for(int tt=1;tt<=t;tt++){

scanf("%d",&n);
int lim=2*n;
for(int i=1;i<lim;i++){
    for(int j=0;j<n;j++){
        scanf("%d",&a);
        vis[a]++;
    }

}
vector<int>ans;
for(int i=1;i<=2500;i++){
    if(vis[i]>0&&vis[i]&1){
        ans.push_back(i);
    }
    vis[i]=0;
}


 printf("Case #%d:",tt);
 for(int i=0;i<n;i++){
    printf(" %d",ans[i]);
 }
 printf("\n");
 }
    return 0;
}
