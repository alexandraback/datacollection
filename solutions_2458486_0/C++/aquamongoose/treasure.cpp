// Bill Cooperman (aquamongoose)
// Google Code Jam Qualification Round
// Problem D
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

const int MAXN = 22;
const int KEYS = 200;

int N;
int need[MAXN];
vector <int> get[MAXN];
vector <int> solution;
bool v[1 << MAXN];

bool rec(int done, vector <int>& keys)
{
    if (v[done]) return false;
    v[done] = true;
    if (done == (1 << N)-1) return true;
    for (int i=0; i<N; i++)
    {
        if (!(done & (1 << i)) && keys[need[i]])
        {
            keys[need[i]]--;
            for (int j=0; j<KEYS; j++)
                keys[j] += get[i][j];
            solution.push_back(i+1);
            done |= (1 << i);

            if (rec(done, keys))
                return true;

            done ^= (1 << i);
            solution.pop_back();
            for (int j=0; j<KEYS; j++)
                keys[j] -= get[i][j];
            keys[need[i]]++;
        }
    }
    return false;
}

int main()
{
    int T; cin >> T;
    for (int kase=1; kase<=T; kase++)
    {
        memset(v, 0, sizeof(v));
        memset(need, 0, sizeof(need));
        solution.clear();
        for (int i=0; i<MAXN; i++)
        {
            get[i].clear();
            get[i].resize(KEYS);
        }

        cout << "Case #" << kase << ": ";
        int K; cin >> K >> N;
        vector <int> start(KEYS);
        for (int i=0; i<K; i++)
        {
            int x; cin >> x;
            start[x]++;
        }
        for (int i=0; i<N; i++)
        {
            cin >> need[i];
            int ki;
            cin >> ki;
            for (int j=0; j<ki; j++)
            {
                int x; cin >> x;
                get[i][x]++;
            }
        }
        if (rec(0, start))
        {
            for (int i=0; i<N; i++)
                cout << solution[i] << ' ';
            cout << endl;
        }
        else
            cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
