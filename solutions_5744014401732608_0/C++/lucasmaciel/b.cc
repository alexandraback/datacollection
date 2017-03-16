#include <bits/stdc++.h>
using namespace std;

int tab[51][51];

int powerlevel(long long m){
    int c = 0;
    for (long long p = 1; p <= m; p<<=1){
        c++;
    }
    return c-1;
}

int main(){
    int t, cases = 1;
    cin >> t;
    while (t--){
        long long m;
        int b;

        cin >> b >> m;

        for (int i = 0; i < b; i++)
            for (int j = 0; j < b; j++)
                tab[i][j] = (i == j-1);

        int comp = powerlevel(m);
        long long q = m - (1LL<<comp);

        //cout << "comp " << comp << endl;

        cout << "Case #" << cases++ << ": ";

        if (comp+2 == b && q == 0 || b > comp+2){

            for (int i = 0; i < comp+2; i++)
                for (int j = 0; j < i; j++)
                    tab[b-i-1][b-j-1] = 1;

            while (q){
                int id = powerlevel(q);
                //cout << id << endl;
                q -= (1LL<<id);
                tab[b-comp-3][b-id-2] = 1;
            }

            cout << "POSSIBLE" << endl;

            for (int i = 0; i < b; i++){
                for (int j = 0; j < b; j++)
                    cout << tab[i][j];
                cout << endl;
            }
        }
        else cout << "IMPOSSIBLE" << endl;

        
    }
    return 0;
}
