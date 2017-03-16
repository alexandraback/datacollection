#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int N,M;
int zipSort[51];
int zip[51];
vector<int> allers[51];
//vector<int> retours[51];
int chemin[51];
int best[51];
int szChemin;
bool first;
int papa[51];

void majBest()
{
    for(int i = 0; i < N; i++)
    {
        if(first || zip[chemin[i]]<zip[best[i]])
            break;
        if(zip[chemin[i]]>zip[best[i]])
            return;
    }
    first = false;
    for(int i = 0; i < N; i++)
        best[i]=chemin[i];
}

void backtrack(int posB, int vu)
{
    if(szChemin==N)
    {
        majBest();
        return;
    }

    int pos=posB;
    while(pos!=-1)
    {
        for(int i = 0; i < allers[pos].size(); i++)
        {
            int next = allers[pos][i];
            if((vu & (1<<next)) != 0) continue;
            chemin[szChemin++]=next;
            papa[next]=pos;
            backtrack(next, vu|(1<<next));
            szChemin--;
            //papa[next]=0;
        }
        pos=papa[pos];
    }
}

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);

    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++)
    {
        scanf("%d%d", &N, &M);
        first=true;

        for(int i = 1; i <= N; i++)
        {
            scanf("%d", &zip[i]);
            zipSort[i]=zip[i];
            best[i-1]=0;
            allers[i].clear();
            //retours[i].clear();
        }
        sort(zipSort+1, zipSort+N+1);

        for(int i = 0; i < M; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            allers[a].push_back(b);
            allers[b].push_back(a);
            //retours[b].push_back(a);
        }

        for(int i = 1; i <= N; i++)
        {
            chemin[0]=i;
            papa[i]=-1;
            szChemin=1;
            backtrack(i, (1<<i));
        }

        printf("Case #%d: ",t);
        for(int i = 0; i < N; i++)
            printf("%d", zip[best[i]]);
        putchar('\n');
    }

    return 0;
}
