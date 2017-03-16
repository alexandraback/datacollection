#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long lint;

set<char> vowels;

bool check(char a)
{
    return vowels.find(a) == vowels.end();
}

int main()
{
    // freopen("a3.in", "r", stdin);
    // freopen("a3.out", "w", stdout);

    vowels.clear();
    vowels.insert('a');
    vowels.insert('e');
    vowels.insert('i');
    vowels.insert('o');
    vowels.insert('u');

    int t2;
    cin >> t2;
    for (int t1 = 1; t1 <= t2; ++t1) {
        printf("Case #%d: ", t1);

        string name;
        lint n;
        cin>>name>>n;

        int l = name.size();
        int cnt = 0;
        std::vector<lint> start;
        for (int i = 0; i < l; ++i)
        {
            if (check(name[i]))
            {
                cnt ++;
                if (cnt >= n)
                {
                    start.push_back(i - n + 1);
                }
            } else {
                cnt = 0;
            }
        }


        lint sum = 0;
        lint last = -1;
        for (int i = 0; i < start.size(); ++i)
        {
            sum += (start[i] - last) * (l-start[i] - n + 1);
            last = start[i];
        }
        cout<<sum;

        printf("\n");
    }
    
    return 0;
}
