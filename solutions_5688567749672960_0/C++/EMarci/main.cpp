#include <iostream>

using namespace std;

int T;

long long n;

long long le[15];
long long pot[15];

int jn;
int je[14];

int main()
{
    pot[0] = 1;
    for(int i=1; i<=14; i++) {
        pot[i] = pot[i-1]*10ll;
    }

    le[0] = 0;
    for(int i=1; i<=14; i++) {
        le[i] = le[i-1] + (pot[(i+1)/2] + pot[i/2] - 1);
    }
    pot[0] = 0;

    cin >> T;

    for(int t=1; t<=T; t++) {
        cin >> n;

        if(n <= 20) {
            cout << "Case #" << t << ": " << n << endl;
            continue;
        }

        long long nn = n;
        jn = 0;
        while(nn > 0) {
            je[jn++] = nn%10;
            nn /= 10;
        }

        if(n == pot[jn-1]) {
            cout << "Case #" << t << ": " << le[jn-1] << endl;
            continue;
        }

        long long sol = le[jn-1];

        long long sol2 = 1ll<<60;

        for(int j=1; j<jn;j ++) {
            long long nv = n % pot[j];
            if(!nv) {
                nv = pot[j];
                je[j]--;
                int jj = j;
                while(je[jj] < 0) {
                    je[jj] = 9;
                    jj++;
                    je[jj]--;
                }

                long long ne = 0ll;
                for(int i=j; i<jn; i++) {
                    ne = (ne*10ll) + je[i];
                }

                sol2 = min(sol2, ne+nv);

                je[j]++;
                jj = j;
                while(je[jj] == 10) {
                    je[jj] = 0;
                    jj++;
                    je[jj]++;
                }
                continue;
            }

            long long ne = 0ll;
            for(int i=j; i<jn; i++) {
                ne = (ne*10ll) + je[i];
            }

            sol2 = min(sol2, ne+nv);
        }

        sol += min(sol2, n-pot[jn-1]);

        cout << "Case #" << t << ": " << sol << endl;
    }

    return 0;
}
