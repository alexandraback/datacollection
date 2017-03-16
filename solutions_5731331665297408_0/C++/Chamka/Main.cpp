#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
using namespace std;

int main(){
    int test, testN, i, j, n, m, x, y;
    char s[100];
    int a[100];
    scanf("%d\n", &testN);
    for (test = 1; test <= testN; test++)
    {
        scanf("%d%d",&n,&m);
        vector<string> zip;
        for (i = 0; i < n; i++)
        {
            a[i] = i;
            scanf("%s", s);
            zip.push_back(s);
        }
        vector<vector<int> > graph(n);
        for (i = 0; i < m; i++)
        {
            scanf("%d%d", &x, &y);
            graph[x - 1].push_back(y - 1);
            graph[y - 1].push_back(x - 1);
        }
        string best(5 *n , '9');
        
        do
        {
            stack<int> ss;
            ss.push(a[0]);
            for (i = 1; i < n; i++)
            {
                while(!ss.empty())
                {
                    x = ss.top();
                    for (y = 0; y < graph[x].size(); y++)
                    if (graph[x][y] == a[i])
                    {
                        break;
                    }
                    if (y < graph[x].size())
                    {
                        ss.push(a[i]);
                        break;
                    }
                    else
                    {
                        ss.pop();
                    }
                }
                if (ss.empty()) break;
            }
            if (i >= n)
            {
                string t = "";
                for (i = 0; i < n; i++)
                t = t + zip[a[i]];
                //printf("%s\n", t.c_str());
                if (t < best) best = t;
            }
        }while(next_permutation(a, a + n));
        
        printf("Case #%d: %s\n", test, best.c_str());
    }
    return 0;
}
