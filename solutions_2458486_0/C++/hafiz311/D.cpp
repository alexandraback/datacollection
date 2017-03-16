#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <math.h>
#include <stack>
#include <list>


#define pb push_back
#define SZ 407
using namespace std;

typedef long long Long;

vector<int>key[SZ+7];
int need[SZ+7];
bool Possib[(1<<20)][27];

int n;
int K,arr[SZ+7];


int dp[(1<<20)];
int vis[(1<<20)],True;
int ans[SZ+7];



int back(int bit,int pos)
{
    if(vis[bit]==True) return dp[bit];
    dp[bit] = 0; vis[bit] = True;
    //printf("visited %d\n",bit);
    if(bit==(1<<n)-1) {
        dp[bit] = 1;
        for(int i=0;i<n;i++) printf(" %d",ans[i]);
        printf("\n");

        return 1;
    }

    for(int i=0;i<n;i++) {
        if((bit&(1<<i))==0) {
            if(Possib[bit][i]) {

                //printf("here %d %d\n",bit,i+1);
                ans[pos] = i + 1 ;
                int pp = back(  ( bit | (1<<i) ) , pos + 1 );
                if(pp==1) {
                    dp[bit] = 1;
                    return 1;
                }
            }
        }
    }
    return 0;

}



int Cnt[SZ+7];
int Color[SZ+7];



int main()
{
    //freopen("in.txt","rt",stdin);
    freopen("D.in","rt",stdin);
    freopen("D.out","wt",stdout);
    int tst,cas;
    scanf("%d",&tst);
    for(cas=1;cas<=tst;cas++) {
        scanf("%d%d",&K,&n);

        for(int i = 1; i <= K ;i++) scanf("%d",&arr[i]);


        for(int i=0;i<n;i++) {
            scanf("%d",&need[i]);
            key[i].clear();
            int v;
            scanf("%d",&v);
            while(v--) {
                int u;
                scanf("%d",&u);
                key[i].pb(u);
            }

        }

        int tu;


        for(int i=0;i<(1<<n);i++) {
            True++;
            for(int j=1;j<=K;j++) {
                if(Color[arr[j]]!=True) {
                    Color[arr[j]] = True;
                    Cnt[arr[j]] = 1;
                }
                else Cnt[arr[j]]++;
            }


            for(int j=0;j<n;j++) {
                if(((1<<j)&i)==0) ;
                else {


                    for(int k=0;k<key[j].size();k++) {
                        tu = key[j][k];
                        if(Color[tu]!=True) Color[tu] = True, Cnt[tu] = 1;
                        else Cnt[tu]++;
                    }



                    if(Color[need[j]]!=True) Color[need[j]] = True, Cnt[need[j]]=-1;

                    else Cnt[need[j]]--;

                }
            }







            for(int j=0;j<n;j++) {


                if(Color[need[j]]==True&&Cnt[need[j]]>0) Possib[i][j] = true;
                else Possib[i][j] = false;

                //if(i==2) printf("%d : %d %d\n",j,need[j],Cnt[need[j]]);

            }

        }

        True++;
        printf("Case #%d:",cas);
        int xx = back(0,0);
        if(xx==0) printf(" IMPOSSIBLE\n");




    }
    return 0;
}
