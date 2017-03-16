#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<utility>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<cmath>
using namespace std;
#define PB push_back
#define PPB pop_back
#define MP make_pair
#define LL long long
#define ULL unsigned long long
#define fs first
#define sc second
#define pii pair<int,int>
#define pll pair<LL,LL>
#define ppii pair< pii,int >
#define big 2000000000
#define N 105
#define M 30

int kasus,pjg,jml,p,puter[M],pjgbr[N],jawab;
char ar[N][N],br[N][N],las;
bool valid,cek[M];

void trim()
{
    for (int i=0;i<jml;i++)
    {
        pjg = strlen(ar[i]);
        p = 1;
        br[i][0] = ar[i][0];
        for (int j=1;j<pjg;j++)
        {
            if (ar[i][j]==ar[i][j-1]) continue;
            br[i][p] = ar[i][j];
            p++;
        }
        pjgbr[i] = p;
    }
}

bool cek_validitas()
{
    memset(cek,0,sizeof(cek));
    //yang ada di tengah nggak boleh berkali2
    for (int i=0;i<jml;i++)
    {
        for (int j=1;j<pjgbr[i]-1;j++)
        {
            if (cek[br[i][j]-'a']) return false;
            cek[br[i][j]-'a'] = true;
        }
    }
    //yang udah di tengah, ga boleh di pinggir
    for (int i=0;i<pjg;i++)
        if (cek[br[i][0]-'a'] || cek[br[i][pjgbr[i]-1]-'a'])
            return false;
    
    return true;
}

int main()
{
//    freopen("B-small-attempt0.in","r",stdin);
//    freopen("b.out","w",stdout);
    
    scanf("%d",&kasus);
    for (int z=1;z<=kasus;z++)
    {
        memset(ar,0,sizeof(ar));
        memset(br,0,sizeof(br));
        
        scanf("%d",&jml);
        for (int i=0;i<jml;i++) scanf("%s",ar[i]);
        trim();
        jawab = 0;
        //valid = cek_validitas();
        
        printf("Case #%d: ",z);
        /*if (!valid) printf("0\n");
        else
        {
        }*/
        for (int i=0;i<jml;i++) puter[i] = i;
        do
        {
            valid = true;
            memset(cek,0,sizeof(cek));
            las = 'A';
            for (int i=0;i<jml && valid;i++)
            {
                for (int j=0;j<pjgbr[puter[i]];j++)
                {
                    if (las==br[puter[i]][j]) continue;
                    if (cek[br[puter[i]][j]-'a']) {valid = false; break;}
                    cek[br[puter[i]][j]-'a'] = true;
                    las = br[puter[i]][j];
                }
            }
            if (valid) jawab++;
        } while (next_permutation(puter,puter+jml));
        printf("%d\n",jawab);
    }
    
//    fclose(stdin);
//    fclose(stdout);
    return 0;
}
