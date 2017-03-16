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
    // freopen("a2.in", "r", stdin);
    // freopen("a2.out", "w", stdout);

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
        int n;
        cin>>name>>n;

        int l = name.size();
        int cnt = 0;
        std::vector<int> start;
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


        double sum = 0;
        int last = -1;
        for (int i = 0; i < start.size(); ++i)
        {
            sum += 1.0 * (start[i] - last) * (l-start[i] - n + 1);
            last = start[i];
        }
        cout<<sum;

        printf("\n");
    }
    
    return 0;
}
