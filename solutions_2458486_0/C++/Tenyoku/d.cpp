#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int inkey[200];
vector<int> chest[200];
int bt[200];
int boxn[200];

bool opened[200];
int nkey[200];
bool used[200];
void open(int i)
{
    used[i] = 1;
    for(int j=0; j<n; ++j)
        if(bt[j]==i&&!opened[j])
            for(int k=0; k<chest[j].size(); ++k)
            {
                ++nkey[chest[j][k]];
                if(!used[chest[j][k]]) open(chest[j][k]);
            }
}
bool check()
{
    memset(used, 0, sizeof(used));
    for(int i=0; i<200; ++i)
        if(nkey[i]>0&&!used[i]) open(i);
    for(int i=0; i<200; ++i) if(boxn[i]>nkey[i]) return 0;
    return 1;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int cnt = 1; cnt<=T; ++cnt)
    {
        memset(inkey, 0, sizeof(inkey));
        memset(boxn, 0, sizeof(boxn));
        memset(opened, 0, sizeof(opened));
        for(int i=0; i<200; ++i) chest[i].clear();
        int k, tmp;
        scanf("%d %d", &k, &n);
        while(k-->0)
        {
            scanf("%d", &tmp);
            ++inkey[tmp-1];
        }
        for(int i=0; i<n; ++i)
        {
            scanf("%d %d", &bt[i], &k);
            --bt[i];
            ++boxn[bt[i]];
            while(k-->0)
            {
                scanf("%d", &tmp);
                chest[i].push_back(tmp-1);
            }
        }
        for(int i=0; i<200; ++i) nkey[i] = inkey[i];
        printf("Case #%d: ", cnt);
        if(check())
        {
            for(int kk=0; kk<n; ++kk)
                for(int i=0; i<n; ++i)
                    if(!opened[i]&&inkey[bt[i]]>0)
                    {
                        opened[i] = 1;
                        for(int j=0; j<200; ++j) nkey[j] = inkey[j];
                        --nkey[bt[i]];
                        --boxn[bt[i]];
                        for(int j=0; j<chest[i].size(); ++j)
                            ++nkey[chest[i][j]];
                        if(check())
                        {
                            printf("%d ", i+1);
                            --inkey[bt[i]];
                            for(int j=0; j<chest[i].size(); ++j)
                                ++inkey[chest[i][j]];
                            break;
                        }
                        else
                        {
                            opened[i] = 0;
                            ++boxn[bt[i]];
                        }
                    }
            puts("");
        }
        else puts("IMPOSSIBLE");
    }
    return 0;
}
