#include <iostream>
#include <fstream>
#include <set>
#include <cstdlib>
#include <array>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    ifstream cin("B-small-attempt0.in");
    ofstream cout("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    for (int case_num = 1; q; q--, case_num++)
    {
        cout << "Case #" << case_num << ": ";
        int a, b, k, ans = 0;
        cin >> a >> b >> k;
        for (int i = 0; i < a; i++)
            for (int j = 0; j < b; j++)
                if ((i & j) < k)
                    ans++;
        cout << ans;
        cout << '\n';
    }
    return 0;
}
