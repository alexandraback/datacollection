#include <bits/stdc++.h>

using namespace std;

#define ALL(v) v.begin(),v.end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORR(I, A, B) for (int I = (A); I < (B); ++I)

const double EPS = 1e-4;
const long double PI = acos((long double)-1.0);
const long long int MOD = 1e9 + 7;

typedef long long int lint;
typedef long double ld;
lint powmod(lint a,lint b, lint mod) {lint res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

const int debug = 1;
template <typename T>
void DBG(vector<T> v){if(debug){for(T t:v)cout<<t<<"  ";cout<<endl;}}
template <typename T>
void DBG(T t){if(debug)cout<<t<<endl;}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int T;
    cin >> T;
    FORR(t, 1, T + 1)
    {
        int N;
        cin >> N;

        vector<vector<int>> v(2*N-1, vector<int>(N));
        FOR(i, 2*N-1)
            FOR(j, N)
                cin >> v[i][j];

        /*sort(ALL(v), [N](vector<int> &v1, vector<int> &v2){
            FOR(i, N)
            {
                if (v1[i] < v2[i])
                    return true;
                if (v1[i] > v2[i])
                    return false;
            }
            return true;
        });*/

        vector<int> cnts(2501, 0);
        for (auto V : v)
        {
            for (auto i : V)
            {
                cnts[i]++;
            }
        }

        //vector<int> out;


        cout << "Case #" << t << ":";
        FOR(i, 2501)
        {
            if (cnts[i] % 2)
                cout << " " << i;
        }
        cout << endl;
    }
}