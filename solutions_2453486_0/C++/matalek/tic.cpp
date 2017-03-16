//Tic-Tac-Toe-Tomek
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <iostream>
#define REP(x,n) for (int x = 0; x < (n); ++x)
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
#define VAR(v,n) __typeof(n) v = (n)
#define FOREACH(i,c) for (VAR(i,(c).begin()); i!=(c).end(); ++i)
#define deb(a) a
using namespace std;
typedef long long int LL;
typedef vector<int> VI;
typedef pair <int,int> PII;
typedef vector< PII > VPII;

int main()
{
    int t, cnt1, cnt2, cnt3, res, cnt; //X,O,T
    cin >> t;
    string arr[4];

    REP(abc,t)
    {
        REP(i,4)
            cin >> arr[i];

        cnt = 0;
        res = -1; //0 - X, 1 - O

        REP(i,4)
        {
            cnt1 = cnt2 = cnt3 = 0;
            REP(j,4)
            {
                if(arr[i][j] != '.')
                    cnt++;
                switch (arr[i][j])
                {
                    case 'X':
                        cnt1++;
                        break;
                    case 'O':
                        cnt2++;
                        break;
                    case 'T':
                        cnt3++;
                        break;
                }

            }
            if(cnt1 + cnt3 == 4)
                res = 0;
            if(cnt2 + cnt3 == 4)
                res = 1;
        }

        REP(i,4)
        {
            cnt1 = cnt2 = cnt3 = 0;
            REP(j,4)
            {
                switch (arr[j][i])
                {
                    case 'X':
                        cnt1++;
                        break;
                    case 'O':
                        cnt2++;
                        break;
                    case 'T':
                        cnt3++;
                        break;
                }

            }
            if(cnt1 + cnt3 == 4)
                res = 0;
            if(cnt2 + cnt3 == 4)
                res = 1;
        }

        cnt1 = cnt2 = cnt3 = 0;
        REP(i,4)
        {
            switch (arr[i][i])
            {
                case 'X':
                    cnt1++;
                    break;
                case 'O':
                    cnt2++;
                    break;
                case 'T':
                    cnt3++;
                    break;
            }

        }

        if(cnt1 + cnt3 == 4)
            res = 0;
        if(cnt2 + cnt3 == 4)
            res = 1;

        cnt1 = cnt2 = cnt3 = 0;
        REP(i,4)
        {
            switch (arr[i][3-i])
            {
                case 'X':
                    cnt1++;
                    break;
                case 'O':
                    cnt2++;
                    break;
                case 'T':
                    cnt3++;
                    break;
            }

        }

        if(cnt1 + cnt3 == 4)
            res = 0;
        if(cnt2 + cnt3 == 4)
            res = 1;
        cout << "Case #" << abc+1 << ": ";
        switch(res)
        {
            case 0:
                cout << "X won\n";
                break;
            case 1:
                cout << "O won\n";
                break;
            case -1:
                if(cnt == 16)
                    cout << "Draw\n";
                else
                    cout << "Game has not completed\n";
                break;
        }

    }

    return 0;
}
