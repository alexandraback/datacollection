#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std ;

#define MAXN 1000

vector<vector<int> >ed;
int ns[MAXN+5];
int best[MAXN+5][MAXN+5];
int n;

int solve(int ind,int to)
{
    if (ind==to)return 1;
    if (best[ind][to]!=-1)return best[ind][to];
    int ret=0;
    int c,c2;
    for (c=0;c<ns[ind];c++)
        ret+=solve(ed[ind][c],to);
    return best[ind][to]=min(10,ret);
}

int main()
{
    FILE *in=fopen("diamond.in","r");
    freopen("diamond.out","w",stdout);
    int c,c2;
    int tests;
    fscanf(in,"%d",&tests);
    for (int test=1;test<=tests;test++)
    {
        memset(best,-1,sizeof(best));
        ed.clear();
        fscanf(in,"%d",&n);
        ed.resize(n);
        for (c=0;c<n;c++){
            fscanf(in,"%d",&ns[c]);
            ed[c].resize(ns[c]);
            for (c2=0;c2<ns[c];c2++){
                fscanf(in,"%d",&ed[c][c2]);
                ed[c][c2]--;
            }
        }
        printf("Case #%d: ",test);
        for (c=0;c<n;c++)
            for (c2=0;c2<n;c2++)
            {
                int ways=solve(c,c2);
                if (ways>=2){
                    printf("Yes\n");
                    goto barra;
                }
            }
        printf("No\n");
        barra:continue;
    }
    
 
//    system("pause");
    return 0;
}
