#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
#include <deque>
#include <string>
#include <queue>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
    int T, t;
    cin >> T;
    for (t=0;t<T;++t)
    {
        int N,n;
        cin >> N;
        vector<vector<int> > diag(N+1);
        for (n=1;n<=N;++n)
        {
            int M,i,mi;
            cin >> M;
            for (i=0;i<M;++i)
            {
                cin >> mi;
                diag[n].push_back(mi);
            }
        }
        bool diamond = false;
        for (n=1;n<=N;++n)
        {
            set<int> graph;
            int i;
            for (i=0;i<(int)(diag[n].size());++i)
            {
                graph.insert(diag[n][i]);
            }
            while(!graph.empty()) {
                set<int>::iterator b = graph.begin();
                while((b!=graph.end())&&(diag[*b].empty())) {
                    ++b;
                }
                if (b==graph.end()) {
                    break;
                }
                int e = *b;
                graph.erase(b);

                for (i=0;i<(int)(diag[e].size());++i)
                {
                    if (! (graph.insert(diag[e][i])).second){
                        diamond = true;
                        goto OK;
                    }
                }
            }

        }
OK:
        cout << "Case #" <<t+1<<": "<<(diamond?"Yes":"No")<< endl;
    }

    return 0;
}
