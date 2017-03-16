#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define ff first
#define ss second
using namespace std;

const int MAXN = 60;
long long n, m;
bool tab[MAXN][MAXN];

int main() {
    int t;
    cin >> t;
    int t2 = t;
    vector <pair <int, int> > v;
    while( t--) {
        cout << "Case #"<< t2-t<<": ";
        cin >> n;
        cin >> m;
        for(int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    tab[i][j] = 0;
                }
            }
        if( (long long)1<<(n-2) <   m ) {
            cout << "IMPOSSIBLE" << endl;
        }
        else {
            cout<<"POSSIBLE" << endl;
            long long pot = 0;
            long long liczba = m;
            while(liczba > 0) {
                liczba /=2;
                pot ++;
            }
            //cout<<pot;
            for(int i = 1; i <= pot; i++) {
                tab[i][n]=1;
                for(int j = i + 1; j <= pot; j++)
                    tab[i][j]=1;
            }
            liczba = m - (1<<(pot-1));
            //cout<<liczba;
            long long koniec = pot + 1;
            long long licznik = 2;
            while(liczba > 0) {
                if(liczba % 2 == 1) {
                    tab[licznik][koniec] = 1;
                    tab[koniec][n] = 1;
                }
                licznik++;
                liczba/=2;
            }
            for(int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    cout<<tab[i][j];
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
