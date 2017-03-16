#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int A[300] , ans[50];

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    freopen("A-small-attempt0.in" , "r" , stdin);
    freopen("out.out" , "w" , stdout);

    int T , cc = 0;
    cin >> T;
    while(T--)
    {
        ++cc;
        string s;
        cin >> s;
        for(int i = 0;i < (int)s.size();++i)
            ++A[s[i]];


        for(int i = 0;i < A['Z'];++i)
        {
            --A['E'];
            --A['R'];
            --A['O'];
            ++ans[0];
        }
        A['Z'] = 0;
        for(int i = 0;i < A['X'];++i)
        {
            --A['S'];
            --A['I'];
            ++ans[6];
        }
        A['X'] = 0;


        for(int i = 0;i < A['G'];++i)
        {
            --A['E'];
            --A['I'];
            --A['H'];
            --A['T'];
            ++ans[8];
        }
        A['G'] = 0;

        for(int i = 0;i < A['W'];++i)
        {
            --A['T'];
            --A['O'];
            ++ans[2];
        }
        A['W'] = 0;

        for(int i = 0;i < A['H'];++i)
        {
            --A['T'];
            --A['R'];
            --A['E'];
            --A['E'];
            ++ans[3];
        }
        A['H'] = 0;


        for(int i = 0;i < A['S'];++i)
        {
            --A['E'];
            --A['V'];
            --A['E'];
            --A['N'];
            ++ans[7];
        }
        A['S'] = 0;

        for(int i = 0;i < A['U'];++i)
        {
            --A['F'];
            --A['O'];
            --A['R'];
            ++ans[4];
        }
        A['U'] = 0;

        for(int i = 0;i < A['F'];++i)
        {
            --A['I'];
            --A['V'];
            --A['E'];
            ++ans[5];
        }
        A['F'] = 0;

        for(int i = 0;i < A['O'];++i)
        {
            --A['N'];
            --A['E'];
            ++ans[1];
        }
        A['O'] = 0;

        for(int i = 0;i < A['I'];++i)
        {
            --A['N'];
            --A['N'];
            --A['E'];
            ++ans[9];
        }
        A['I'] = 0;

        cout << "Case #" << cc << ": ";
        for(int i = 0;i < 10;++i)
            for(int j = 0;j < ans[i];++j)
                cout << i;

        cout << "\n";
        memset(A , 0 , sizeof(A));
        memset(ans , 0 , sizeof(ans));

        cerr << "done    ->" << cc << "\n";
    }
    return 0;
}

