#include <iostream>
#include <set>
using namespace std;
int path[1002][1002];

bool traverse(set<int>& visited, int node, int n)
{
    if(visited.insert(node).second == false) return true;
    bool retval = false;
    for(int i=1; i<=n; ++i)
    {
        if(path[node][i]==1)
        {
            retval |=  traverse(visited, i, n);
        }
    }
    return retval;
}

int main()
{


    int T;
    cin>>T;
    int c =0;
    while(c<T)
    {

    for(int i=0; i<1002;++i)
    {
        for(int j=0; j<1002;++j)
        {
            path[i][j]=0;
        }
    }

        int n;
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            int in;
            cin>> in;
            for(int j=0; j<in; ++j)
            {
                int node;
                cin>>node;
                path[i][node] =1;
            }
        }
        bool bfound = false;
        for(int i =1; i<=n; ++i)
        {
           set<int> visited;
           if(traverse(visited, i, n) == true)
           {
               bfound = true;
               break;
           }
        }
        ++c;
        if(bfound)
            cout <<"Case #"<< c <<": " << "Yes"<<endl;
        else
            cout <<"Case #"<< c <<": " << "No"<<endl;
    }

}
