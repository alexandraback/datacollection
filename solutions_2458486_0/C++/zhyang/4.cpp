#include<iostream>
#include<vector>
using namespace std;

int keycnt[50];
bool ok[1<<20+5];
bool vis[50];
vector<int> chesskey[50];
int numkey, numchess;
int require[50];
bool solve;
int path[50];

bool dfs(int cur, int remain)
{
    if(cur == numchess)
    {
        solve = true;
        return true;
    }
    
    if(!ok[remain])
        return false;
    
    for(int i = 0; i < numchess; ++i)
    {
        if(remain & (1<<i) && keycnt[require[i]] > 0)
        {
            keycnt[require[i]]--;
            for(int j = 0; j < chesskey[i].size(); ++j)
                keycnt[chesskey[i][j]]++;
            
            path[cur] = i;
            if(dfs(cur+1, remain^(1<<i)))
                return true;
            ok[remain^(1<<i)] = false;
            
            for(int j = 0; j < chesskey[i].size(); ++j)
                keycnt[chesskey[i][j]]--;
            keycnt[require[i]]++;
        }
    }
    return false;
}

int main()
{
    freopen("c:\\4.txt","r",stdin);
    freopen("c:\\4-out.txt","w",stdout);
    int T;
    cin>>T;
    for(int caseIndex = 1; caseIndex <= T; ++caseIndex)
    {
        solve = false;
        memset(ok, true, sizeof(ok));
        memset(keycnt, 0, sizeof(keycnt));
        cin>>numkey>>numchess;
        for(int i = 0; i < numkey; ++i)
        {
            int a;
            cin>>a;
            keycnt[a]++;
        }
        for(int j = 0; j < numchess; ++j)
        {
            chesskey[j].clear();
            cin>>require[j];
            int a, b;
            cin>>a;
            for(int k = 0; k < a; ++k)
            {
                cin>>b;
                chesskey[j].push_back(b);
            }
        }
        
        dfs(0, (1<<numchess)-1);
        cout<<"Case #"<<caseIndex<<":";
        if(solve)
        {
            for(int i = 0; i < numchess; ++i)
                cout<<" "<<path[i]+1;
        }
        else
            cout<<" IMPOSSIBLE";
        cout<<endl;
    }
    return 0;
}
