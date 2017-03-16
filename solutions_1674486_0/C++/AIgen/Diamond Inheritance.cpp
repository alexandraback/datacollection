#include<iostream>
using namespace std;

    int t, n;
    int cur_case = 1;
    
    int graph[1005][12];
    int degree[1005];
    
    bool tree_child[1005][1005];
    int num_children[1005];
    int tree_child_adj_list[1005][1005];    
    
    bool visited[1005];

    int scan_v (int ver);
    int check_update(int ver1, int ver2);

int main()
{   
    cin>>t;
    
    while(cur_case <= t)
    {
        cin>>n;
        
        int i,j,k;
        
        for(i=1;i<=n;++i)
        {
            cin>>degree[i];
            for(j=0;j<degree[i];++j)
                cin>>graph[i][j];
            visited[i] = 0;
            num_children[i] = 0;
            for(j=1;j<=n;++j)
                tree_child[i][j] = 0;
        }
        
        bool out_val = 0;
        for(i=1;i<=n;++i)
        {
            if(visited[i] == 1)continue;
            
            else 
            {
                int flag = scan_v(i);
                if(flag == 1)
                {
                    cout<<"Case #"<<cur_case<<": Yes\n";
                    out_val = 1;
                    break;
                }
            }
        }
        if(out_val == 0)
        {
            cout<<"Case #"<<cur_case<<": No\n";
        }
        
        cur_case ++;
    }
    return 0;
}
    
int scan_v (int ver)
{
    int i;
    
    visited[ver] = 1;
    
    for(i=0;i<degree[ver];++i)
    {
        int cur_ver = graph[ver][i];
        
        if(check_update(ver,cur_ver))
        {
            return 1;
        }
        else {}
        
        if(visited[cur_ver] == 1)
        {
            int j;
            for(j=0;j<num_children[cur_ver];++j)
            {
                int cur_child = tree_child_adj_list[cur_ver][j];
                if(check_update(ver,cur_child)) return 1;
            }
        }
        else
        {
            int flag = scan_v (cur_ver);
            
            if(flag == 1)return 1;
            else
            {
                int j;
                for(j=0;j<num_children[cur_ver];++j)
                {
                    int cur_child = tree_child_adj_list[cur_ver][j];
                    if(check_update(ver,cur_child)) return 1;
                }
            }
        }
    }
    return 0;
}

int check_update(int ver1, int ver2)
{
    if(tree_child[ver1][ver2] == 1)
    {
        return 1;
    }
    else
    {
        tree_child[ver1][ver2] = 1;
        tree_child_adj_list[ver1][num_children[ver1]] = ver2;
        num_children[ver1]++;
        return 0;
    }
}
