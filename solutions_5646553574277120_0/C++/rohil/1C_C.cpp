#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iomanip>
#include <sstream>
#include <cassert>

using namespace std;

void prologue()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    FILE *fp = freopen("/Users/-RooneY-/Desktop/src/input", "r", stdin);
    FILE *fpw = freopen("/Users/-RooneY-/Desktop/src/output", "w", stdout);
}

int C, D, V;
int visited[32];

bool Okay(const vector<int>& d, int& cannot_first)
{
    int n = (int)d.size();

    memset(visited, 0, sizeof(visited));
    
    for (int i = 1; i < (1 << n); ++i)
    {
        int sum = 0;
        
        for (int j = 0; j < n; ++j)
        {
            if (i&(1 << j))
            {
                sum += d[j];
            }
        }
        
        if (sum <= V)
            visited[sum] = 1;
    }
    
    for (int i = 1; i <= V; ++i)
    {
        if (visited[i] == 0)
        {
            cannot_first = i;
            return false;
        }
    }
    
    return true;
}

int main()
{    
    prologue();
    
    int t;
    cin >> t;
    
    for (int test = 1; test <= t; ++test)
    {
        vector<int> d;
        cin >> C >> D >> V;
        assert(C == 1);
        
        for (int i = 0; i < D; ++i)
        {
            int temp;
            cin >> temp;
            d.push_back(temp);
        }
        
        int ans = 0;
        
        while (true)
        {
            int first = 0;
            
            if (Okay(d, first))
                break;
            else
            {
                assert(first != 0);
                
                d.push_back(first);
                ans++;
            }
        }
        
        cout << "Case #" << test << ": " << ans << endl;
    }
    
    return 0;
}