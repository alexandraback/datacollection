#include <bits/stdc++.h>
#define rep(a,b) for(int a = 0; a < b; a++)

using namespace std;
typedef long long ll;


bool kraw[100][100];
bool laczy[100];

inline void para(int a, int b)
{
    kraw[a-1][b-1] = 1;
}

void czysc()
{
    rep(i, 100)
    {
        laczy[i] = 0;
        rep(j, 100) kraw[i][j] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    int kt = 1;
    ll b, m;
    while(kt <= t)
    {
        cin >> b >> m;
        cout << "Case #" << kt << ": ";
        czysc();

        if(m >= (1 << (b-1))) cout << "IMPOSSIBLE";
        else
        {
            cout << "POSSIBLE\n";
            int k = b;
            ll licz = 0;
            while(k > 1){
                para(1, k);
                if(k == b){
                        licz++;
                    laczy[0] = true;
                }
                if(licz == m) break;
                int k2 = b;
                while(k2 >= k+1)
                {
                    para(k, k2);
                    if(k2 == b || laczy[k2-1]){
                            licz++;
                        laczy[k-1] = true;
                    }
                    if(licz == m) break;
                    k2--;
                }
                if(licz == m) break;
                k--;
            }
            rep(i, b)
            {
                rep(j, b) cout << kraw[i][j];
                cout << "\n";
            }
        }
        cout << "\n";
        kt++;
    }
}
