#include <bits/stdc++.h>

#define fi(a,b,c) for(int a=b; a<=c; a++)


using namespace std;

string S1, S2, res1, res2;

int ans;

void duyet(string S1, string S2)
{
    string P1 = S1;
    string P2 = S2;
    fi(i, 0, (int)P1.size() -1)
        if (P1[i] == '?') {
            for (char x = '0' ; x<= '9'; x++)
                {
                    P1[i] = x;
                    duyet(P1, P2);
                }
            return;
        }
    fi(i, 0, (int)P2.size() -1)
        if (P2[i] == '?') {
            for (char x = '0' ; x<= '9'; x++)
            {
                P2[i] = x;
                duyet(P1, P2);
            }
            return;
        }
    int k1 = 0, k2 = 0;
    fi(i, 0, (int)P1.size() -1) k1 = k1 * 10 + (P1[i] - '0');
    fi(i, 0, (int)P2.size() -1) k2 = k2 * 10 + (P2[i] - '0');
    if (ans > abs(k1- k2)) {
        ans = abs(k1 - k2);
        res1 = P1; res2 = P2;
    }
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int tcase;
    cin >>tcase;
    fi(t, 1, tcase)
    {
        ans = 1000000;
        cin >> S1 >> S2;
        duyet(S1, S2);
        printf("Case #%d: ", t);
        cout <<res1 <<' '<<res2<<endl;
    }
}
