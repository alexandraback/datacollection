#include <iostream>
#include<vector>
#include<math.h>
#include <set>
#include <unordered_map>
using namespace std;

const int MAX=1000;
int uNum,vNum;
int g[MAX][MAX];
int linker[MAX];
bool used[MAX];
bool dfs(int u)
{
    int v;
    for(v=0;v<vNum;v++){
        if(g[u][v]&&!used[v])
        {
            used[v]=true;
            if(linker[v]==-1 || dfs(linker[v]))
            {
                linker[v]=u;
                return true;
            }
        }
    }
    return false;
}
int hungary()
{
    int res=0;
    int u;
    memset(linker,-1,sizeof(linker));
    for(u=0;u<uNum;u++)
    {
        memset(used,0,sizeof(used));
        if(dfs(u)){
            res++;
        }
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    for(int k=0;k<t;k++){
        int s;
        cin >> s;
        set<string> first;
        set<string> second;
        vector<pair<string, string> > storage;
        for(int a = 0; a<s; a++){
            string temp;
            cin >> temp;
            first.insert(temp);
            string temp2;
            cin >> temp2;
            second.insert(temp2);
            storage.push_back({temp, temp2});
        }
        uNum = (int)first.size();
        vNum = (int)second.size();
        unordered_map<string, int> umap1;
        unordered_map<string, int> umap2;
        int i=0;
        for(string temp : first){
            umap1[temp]=i;
            i++;
        }
        i=0;
        for(string temp : second){
            umap2[temp]=i;
            i++;
        }
        for(auto pairs : storage){
            g[umap1[pairs.first]][umap2[pairs.second]]=1;
        }
        int maxMatch = hungary();
        //cout << maxMatch << endl;
        int result = (int)storage.size()-(uNum+vNum-maxMatch);
        cout << "Case #"<<k+1<< ": " << result << endl;
        for(int i=0;i<MAX;i++){
            for(int j=0;j<MAX;j++){
                g[i][j]=0;
            }
        }
        uNum=0;
        vNum=0;
    }
    return 0;
}