#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    int T;
    cin >> T;
    for(int t=0; t<T; t++)
    {
        int a,n;
        cin >> a >> n;
        priority_queue<int> motes;
        for(int i=0; i<n; i++)
        {
            int m;
            cin >> m;
            motes.push(-m);
        }
        int minSteps(n);
        for(int i=0; i<n; i++)
        {
            while(!motes.empty() && -motes.top()<a)
            {
                a += -motes.top();
                motes.pop();
            }
            if(minSteps > i+motes.size())
                minSteps = i+motes.size();
            a += a-1;
        }
        cout << "Case #" << t+1 << ": " << minSteps << endl;
    }
}
