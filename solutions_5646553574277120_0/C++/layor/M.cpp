#include <stdio.h>
#include <set>
#include <string.h>
#include <vector>
#include <iostream>

int t,c,d,V;
int num[100];
bool ok[100];
int main(){
 freopen("C-small-attempt1.in","r",stdin);
    freopen("C-small-attempt1.out","w",stdout);
    scanf("%d",&t);
    for(int ca=1;ca<=t;ca++){
        scanf("%d%d%d",&c,&d,&V);
        memset(ok,0,sizeof ok);
        for(int i=0;i<d;i++) scanf("%d",&num[i]);
        int all=(1<<d);
        for(int i=0; i<all; i++){
            int v=0;
            for(int j=0;j<d;j++) if(i&(1<<j)){
                v+=num[j];
            }
            ok[v]=1;
        }
        std::vector<int>s;
        for(int i=1;i<=V;i++) if(!ok[i]){
            int tag=0;
            s.push_back(i);
        }
        int ans=100;
        int ss=s.size();
        if(ss==0){
            printf("Case #%d: %d\n",ca,0);continue;
        }
        std::vector<int>vv;
        for(int j=0;j<d;j++) vv.push_back(num[j]);
        for(int i=0;i<ss;i++){
            vv.push_back(s[i]);
            memset(ok,0,sizeof ok);
            all=(1<<vv.size());
            for(int j=0; j<all; j++){
                int v=0;
                for(int jj=0;jj<vv.size();jj++) if(j&(1<<jj)){
                    v+=vv[jj];
                }
                if(v<=V) ok[v]=1;
            }
            bool tag=0;
            for(int j=1;j<=V;j++) if(!ok[j]){
                tag=1;break;
            }
            if(!tag) {ans=i+1;break;}
        }
        printf("Case #%d: %d\n",ca,ans);
        //std::cerr<<ca<<std::endl;
    }
    return 0;
}
