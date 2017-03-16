#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;


typedef vector< vector< int > > Graph;


bool dfs(int n, const Graph & g)
{
    for(int i = 0; i < n; i++)
    {
        int * m = new int[n];
        memset(m, 0, n * sizeof(int));
        vector< int > stack;
        stack.push_back(i);
        while(stack.size())
        {
            int ndx = stack.back();
            stack.pop_back();
            m[ndx] ++;
            if(i != ndx && m[ndx] >= 2)
            {
                delete[] m;
                return true;
            }
            const vector< int > & node = g[ndx];
            for(vector< int >::const_iterator iter = node.begin(); iter != node.end(); iter++)
            {
                if(*iter != ndx)
                    stack.push_back(* iter);
            }
        }
        delete[] m;
    }
    return false;
}


int main()
{
    int T;
    cin >> T;
    for(int k = 1; k <= T; k++)
    {
        Graph g;
        int N;
        cin >> N;
        g.resize(N);
        for(int n = 0; n < N; n++)
        {
            vector< int > & node = g[n];
            int M;
            cin >> M;
            for(int m = 0; m < M; m++)
            {
                int tmp;
                cin >> tmp;
                node.push_back(tmp - 1);
            }
        }
        
        bool b = dfs(N, g);
        cout << "Case #" << k << ": " << (b ? "Yes" : "No") << endl;
    }
    return 0;
}
