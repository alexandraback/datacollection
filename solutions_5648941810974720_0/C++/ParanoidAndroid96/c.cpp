#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define FILE "file"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int INF = numeric_limits<int>::max();
const ll LLINF = numeric_limits<ll>::max();
const ull ULLINF = numeric_limits<ull>::max();
const double PI = acos(-1.0);

string s;
int n;
int letters[26];

string name[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
char let[] = {'Z', 'W', 'U', 'F', 'V', 'S', 'O', 'N', 'I', 'T'};
int order[] = {0, 2, 4, 5, 7, 6, 1, 9, 8, 3};

int getI(string s)
{
    for(int i = 0; i < 10; i++)
        if(s == name[i])
            return i;
}


void subtract(string s)
{
    for(char a: s)
        letters[a - 'A']--;
}

int main()
{
    freopen(FILE".in", "r", stdin);
    freopen(FILE".out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int tt = 1; tt <= T; tt++)
    {
        cin >> s;
        for(char a: s)
            letters[a - 'A']++;
        vector<string> ans;
        for(int i = 0; i < 10; i++)
        {
            while(letters[let[i] - 'A'])
            {
                ans.pb(name[order[i]]);
                subtract(name[order[i]]);
            }
        }
        vector<int> gg;
        for(string f: ans)
            gg.pb(getI(f));
        sort(all(gg));
        cout << "Case #" << tt << ": ";
        for(int i: gg)
            cout << i;
        cout << '\n';
    }
    return 0;
}
