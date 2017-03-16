#include <bits/stdc++.h>
#define fore(i,j,k) for(int i = j;i<k;i++)
#define forr(i,j,k) for(int i = j;i>k;i--)
#define LL long long

using namespace std;

int n,m;

int main () {
    ios_base :: sync_with_stdio(false);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin >> t;

    fore(tc,1,t+1){
        cout << "case #" << tc << ": ";
        LL n,m;
        cin >> n >> m;

        int g[6][6] = {0};

        LL mx = 1,pw = n-2;
        fore(i,0,pw)
            mx *= 2;
       // cout << mx << " is mx \n";


        if(m > mx){
            cout << "IMPOSSIBLE\n";
            continue;
        }

        fore(i,1,n)
            fore(j,i+1,n)
                g[i][j] = 1;

        m--;
        g[0][n-1] = 1;

        LL bit = 1;
        forr(i,n-2,0){
            if(bit & m)
                g[0][i] = 1;
            else g[0][i] = 0;

            bit *= 2;
        }

        cout << "POSSIBLE\n";
        fore(i,0,n){
            fore(j,0,n)
                cout << g[i][j];
            cout << endl;
        }
    }



    return 0;
}

/// flaw = orders are indeed not in order
