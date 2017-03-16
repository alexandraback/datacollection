#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int ct = 1; ct <= T; ct++)
    {
        int tot = 0;
        int M = 0;

        int lg;
        cin >> lg;
        string s;
        cin >> s;

        for(int i = 0; i < lg+1; i++)
        {
            M = max(M, i-tot);
            tot += s[i]-'0';
        }

        cout << "Case #" << ct << ": " << M << endl;
    }
    return 0;
}
