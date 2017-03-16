#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>

#define fo(a,b,c) for( a = ( b ); a < ( c ); ++ a )
#define fr(a,b) fo( a, 0, ( b ) )
#define fi(a) fr( i, ( a ) )
#define fj(a) fr( j, ( a ) )
#define fk(a) fr( k, ( a ) )

using namespace std;
int ni() { int a; scanf( "%d", &a ); return a; }
double nf() { double a; scanf( "%lf", &a ); return a; }
char sbuf[100005]; string ns() { scanf( "%s", sbuf ); return sbuf; }
long long nll() { long long a; scanf( "%lld", &a ); return a; }

int main()
{
    int i, j;
    int nbTestCases = 0;
    freopen ("D-large.in","r",stdin);
    freopen ("D-large.out","w",stdout);
    cin >> nbTestCases;

    fi(nbTestCases) {
        int cnt = ni();
        cout << "Case #" << i+1 << ": ";
        vector<float> kens;
        vector<float> naomis;
        fj(cnt)
            naomis.push_back(nf());
        fj(cnt)
            kens.push_back(nf());

        sort(naomis.begin(), naomis.end());
        sort(kens.begin(), kens.end());

        int deceivedWarPoints = 0;
        int n = 0, k = 0;
        while (n != cnt) {
            if (naomis[n] > kens[k]) {
                k++;
                deceivedWarPoints ++;
            }
            n++;
        }

        int warPoints = 0;
        n = 0, k = 0;
        while (n != cnt) {
            while (naomis[n] > kens[k] && k < cnt) {
                k++;
            }
            if (k >= cnt) {
                warPoints++;
                n++;
                continue;
            }
            if (naomis[n] < kens[k]) {
                k++;
            }
            n++;
        }


        cout << deceivedWarPoints << " " << warPoints << endl;
    }
    return 0;
}
