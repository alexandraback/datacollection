#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include <assert.h>
#include <numeric>
using namespace std;

#define MOD 1000000007
#define mp make_pair
#define pb push_back
typedef long long LL;
char  s1[107][107];
int n;
char s2[1000000];
bool booln[27];
int jiqi[27];
int jimo[27];
bool vis[107];
int link[107];
int same[27];
int gg[107];
int qq[107],mm[107];
int same2[27];
int main(){
    freopen("a.in","r",stdin);
   freopen("a.out","w",stdout);
    int casen;scanf("%d",&casen);

    for(int casei=1;casei<=casen;casei++){
        scanf("%d",&n);
        bool tell=0;
             LL ans=1;
        memset(jiqi,0,sizeof(jiqi));
        memset(jimo,0,sizeof(jimo));
        memset(vis,0,sizeof(vis));
       memset(same2,0,sizeof(same2));
        int ans2=0;
        for (int i=0;i<27;i++) same[i]=-1;
        for (int i=0;i<107;i++) {gg[i]=i;link[i]=-1;}
        for (int i=0;i<n;i++){
            scanf("%s",s1[i]);
            memset(booln,0,sizeof(booln));
            int j=0;int old=-1;
            while (j<strlen(s1[i])){
                int tmp=s1[i][j]-'a';
                if (tmp!=old){
                    if (booln[tmp]){tell=1;}
                    else{
                        booln[tmp]=1;
                        old=tmp;
                    }
                }
                j++;
            }
            int qi=s1[i][0]-'a',mo=s1[i][strlen(s1[i])-1]-'a';
           // printf("%d %d %d\n",i,qi,mo);
            qq[i]=qi;mm[i]=mo;
            jiqi[qi]++;
            jimo[mo]++;
            if (qi==mo){
                if (same[qi]!=-1){
                    link[same[qi]]=i;
                    vis[same[qi]]=1;
                    gg[i]=gg[same[qi]];
                    same[qi]=i;
                    same2[qi]++;
                  //  jiqi[qi]--;
                 //   jimo[mo]--;
                }else{
                    same[qi]=i;
                    same2[qi]++;
                }
            }
        }
        int st=-1;
        int ansn=0;
    //  printf("ok %d\n",tell);
        while (1){
            bool ok=1;
            for (int i=0;i<n;i++){
                if (vis[i]==0){
                    for (int j=0;j<n;j++) if (vis[j]==0&&i!=j&&mm[j]==qq[j]){
                        if (mm[j]==qq[i]){
                           // printf("link %d %d\n",j,i);
                            ok=0;
                            vis[j]=1;
                            link[j]=gg[i];
                            gg[i]=gg[j];
                            qq[i]=qq[j];
                        }
                    }
                    for (int j=0;j<n;j++) if (vis[j]==0&&i!=j){
                        if (mm[j]==qq[i]){
                          //  printf("link %d %d\n",j,i);
                            ok=0;
                            vis[j]=1;
                            link[j]=gg[i];
                            gg[i]=gg[j];
                            qq[i]=qq[j];
                        }
                    }
                }
            }
            if (ok) break;
        }
        int cnt=0;
        for (int i=0;i<n;i++) if (vis[i]==0) {
         //  printf("jjj%d  %d\n",i,gg[i]);
            ansn++;
            int tmp=gg[i];
            for (int j=0;j<strlen(s1[tmp]);j++) s2[cnt++]=s1[tmp][j];
            while(link[tmp]!=-1){

                tmp=link[tmp];
                for (int j=0;j<strlen(s1[tmp]);j++) s2[cnt++]=s1[tmp][j];
            }
        }
        s2[cnt++]=0;
       // printf("%s\n",s2);

         int j=0;int old=-1;
         memset(booln,0,sizeof(booln));
         while (j<strlen(s2)){
                int tmp=s2[j]-'a';
                if (tmp!=old){
                    if (booln[tmp]){tell=1;}
                    else{
                        booln[tmp]=1;
                        old=tmp;
                    }
                }
                j++;
        }
        if (!tell){
            for (int j=0;j<27;j++)
            for (int i=1;i<=same2[j];i++) ans=ans*i%MOD;
            for (int i=1;i<=ansn;i++) ans=ans*i%MOD;

        }else ans=0;
       // printf("%s\n",s2);
        printf("Case #%d: %lld\n",casei,ans);
    }

}
