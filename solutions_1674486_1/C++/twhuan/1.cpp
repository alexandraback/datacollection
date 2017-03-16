#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iomanip>
#include <sstream>

using namespace std;

bool dfs(int i, vector<set<int> >& adj, vector<bool> & marked) {
     if ( marked[i])
        return true;
     set<int>& aset = adj[i];
     for (set<int>::iterator it = aset.begin();
                it != aset.end(); it++)
     {
          //cout << "traverse " << i << "->" << *it << endl;
         if (dfs(*it, adj, marked))
            return true;
     }
     marked[i] = true;
     return false;
}

int main ()
{
    int N, T, M, tmp;
    cin >> T;
    std::string line;
    vector<set<int> > adj;
    vector<bool> marked;
    bool found;
    for (int i =0; i < T; i++)
    {
        adj.clear();
        marked.clear();
        found = false;
        cin >> N;
        for (int j = 0; j< N; j++)
        {
            set<int> aset;
            cin >> M;
            for (int k=0; k<M; k++)
            {
                cin >> tmp;
                aset.insert(tmp-1);
            }
            adj.push_back(aset);
        }
        cout << "Case #" << i+1 << ": "; 
        for (int j=0; j < adj.size(); j++)
        {
            marked.clear();
            for (int k=0; k<adj.size();k++)
            {
                marked.push_back(false);
            }
            if (dfs(j, adj, marked))
            {
               cout << "Yes" << endl;
               found = true;
               break;
            }

        }
        if (!found)
        {
           cout << "No" << endl;
        }
    }
    return 0;
}
