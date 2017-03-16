#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

int main()
{
    int T;
    cin >> T;
    for (int t=1; t<=T; t++)
    {
        int smax;
        string s;
        cin >> smax >> s;
        int numFriends = 0, partSum = 0;
        for (int i=0; i<=smax; i++)
        {
            numFriends = max(numFriends, i-partSum);
            partSum += s[i]-'0';
        }
        printf("Case #%d: %d\n", t, numFriends);
    }
}
