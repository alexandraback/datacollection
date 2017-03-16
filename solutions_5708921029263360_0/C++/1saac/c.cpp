#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
using namespace std;

struct node{
    int x,y,z;
};

bool CheckNode(node a,node b){
    if(a.x==b.x&&a.y==b.y) return false;
    if(a.x==b.x&&a.z==b.z) return false;
    if(a.z==b.z&&a.y==b.y) return false;
    return true;
}

int vis[30];


int main(){
    //freopen("C-small-attempt1 (1).in","r",stdin);
    //freopen("C-small-attempt1 (1).out","w",stdout);
    int T,ca=0;
    int J,P,S,K;
    int i,j,k,l;
    scanf("%d",&T);
    while(T--){
        ca++;
        scanf("%d%d%d%d",&J,&P,&S,&K);
        vector<node> ans;
        if(K>=3){
            for(i=1;i<=J&&i<=K;i++){
                for(j=1;j<=P&&j<=K;j++){
                    for(k=1;k<=S&&k<=K;k++){
                        node tmp;
                        tmp.x=i;tmp.y=j;tmp.z=k;
                        ans.push_back(tmp);
                    }
                }
            }
        }
        if(K<=2){
            memset(vis,0,sizeof(vis));
            vector<node> tt;
            for(i=1;i<=J;i++){
                for(j=1;j<=P;j++){
                    for(k=1;k<=S;k++){
                        node tmp;
                        tmp.x=i;tmp.y=j;tmp.z=k;
                        int cnt=0;
                        for(l=0;l<ans.size();l++){
                            if(!CheckNode(ans[l],tmp)){
                                cnt++;
                                if(cnt>=K) break;
                            }
                        }
                        if(l==ans.size()){
                            ans.push_back(tmp);
                        }
                    }
                }
            }
        }
        printf("Case #%d: %d\n",ca,ans.size());
        for(i=0;i<ans.size();i++){
            printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].z);
        }
    }
    return 0;
}
