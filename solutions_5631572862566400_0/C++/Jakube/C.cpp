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
        vector<int> F(N);
        FOR(i, N)
        {
            int tmp;
            cin >> tmp;
            F[i] = tmp - 1;
        }

        // Possibility 1: Large cycle
        set<int> largest_cycle;


        FOR(start, N)
        {
            set<int> visited;
            int cur = start;
            while (!visited.count(cur))
            {
                visited.insert(cur);
                cur = F[cur];
            }

            if (cur == start && visited.size() > largest_cycle.size())
            {
                largest_cycle = visited;
            }
        }

        // Possibility 2: Chains ending in BFF-pair, possible combined to pairs of 2

        map<int, set<int>> chains;

        FOR(start, N)
        {
            set<int> visited;

            int cur = start;
            int last = -1;

            while (!visited.count(cur))
            {
                visited.insert(cur);
                last = cur;
                cur = F[cur];
            }

            if (last == F[cur])
            {
                if (!chains.count(cur) || chains[cur].size() < visited.size())
                {
                    chains[cur] = visited;
                }
            }
        }

        set<int> largest_chains;
        for (auto p : chains)
        {
            largest_chains.insert(p.second.begin(), p.second.end());
        }



        cout << "Case #" << t << ": ";
        /*for (auto i : largest_cycle)
            cout << " " << i;
        cout << endl;
        for (auto i : largest_chains)
            cout << " " << i;*/
        cout << max(largest_cycle.size(), largest_chains.size());
        cout << endl;
    }
}