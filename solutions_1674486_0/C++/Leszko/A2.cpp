#include<iostream>
#include<vector>
using namespace std;

int tab[1001];
int color[1001];
vector <int> G[1001];

bool DFS(int v)
{
    color[v]=1;
    
    for(int i=0; i<G[v].size(); i++)
    {
        if(color[G[v][i]])
            return true;
        
        if(DFS(G[v][i]))
            return true;
    }
    
    return false;


}

int main()
{
    ios_base::sync_with_stdio(0);
    
    int Z;
    cin >> Z;
    
    for(int z=1; z<=Z; z++)
    {
        int n;
        cin >> n;
        
        for(int i=0; i<=n; i++)
        {
            color[i]=0;
            tab[i]=0;
            G[i].clear();
        }
        
        for(int i=1; i<=n; i++)
        {
            int m;
            cin >> m;
            
            for(int j=0; j<m; j++)
            {
                int temp;
                cin >> temp;
                
                G[i].push_back(temp);
                tab[temp]++;
            }
        }
        
        bool flag=false;
        
        for(int i=1; i<=n; i++)
        {
            if(!tab[i])
            {
                for(int j=0; j<=n; j++)
                    color[j]=0;
                
                flag=DFS(i);
            }
            
            
            if(flag)
                break;
        }
        
        
        cout << "Case #" << z << ": ";
        
        if(flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
            
        
        
        
    }

return 0;
}
