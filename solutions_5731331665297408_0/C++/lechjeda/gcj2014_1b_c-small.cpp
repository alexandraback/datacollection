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
#define N 10
#define M 7
#define GO graph[pos][i]

int jml,ej,kasus,a,b,st,par[N];
vector <int> graph[N];
string zip[N],jawab;
bool cek[N];
char s[M];

void dfs(int tot,int pos,string sem)
{
//    if (sem[4]=='1') cout << tot << " " << pos << " " << sem << endl;
    if (sem > jawab && jawab != "") return;
    if (tot==jml)
    {
        if (jawab=="") jawab = sem;
        else if (sem < jawab) jawab = sem;
    }
    else
    {
        //make a turn around
        //if (cnt[par[pos]][pos] < 2)
        if (cek[pos] && par[pos] != -1)
        {
            //cnt[par[pos]][pos]++;
            //cnt[pos][par[pos]]++;
            int y = par[pos];
            par[pos] = -1;
            dfs(tot,y,sem);
            par[pos] = y;
            //cnt[par[pos]][pos]--;
            //cnt[pos][par[pos]]--;
        }
        
        //go forward
        for (int i=0;i<graph[pos].size();i++)
        {
            if (cek[GO] || GO==par[pos]) continue;
            if (GO==st && par[pos]==st) continue;
            cek[GO] = true;
            if (par[GO] == -1) par[GO] = pos;
            if (GO==st) dfs(tot,GO,sem);
            else dfs(tot+1,GO,sem+zip[GO]);
            cek[GO] = false;
            par[GO] = -1;
        }
    }
}

int main()
{
//    freopen("C-small-attempt1.in","r",stdin);
//    freopen("c3.out","w",stdout);
    
    scanf("%d",&kasus);
    for (int z=1;z<=kasus;z++)
    {
        scanf("%d %d",&jml,&ej);
        for (int i=1;i<=jml;i++)
        {
            graph[i].clear();
            scanf("%s",s);
            zip[i] = s;
        }
        for (int i=1;i<=ej;i++)
        {
            scanf("%d %d",&a,&b);
            graph[a].PB(b);
            graph[b].PB(a);
        }
        
        jawab = "";
        memset(cek,0,sizeof(cek));
        memset(par,-1,sizeof(par));
        for (int i=1;i<=jml;i++)
        {
            st = i;
            cek[st] = true;
            dfs(1,i,zip[i]);
            cek[st] = false;
        }
        
        printf("Case #%d: %s\n",z,jawab.c_str());
    }
//    fclose(stdin);
//    fclose(stdout);
    return 0;
}
