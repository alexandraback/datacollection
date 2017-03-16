#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define debug(args...) {vector<string> _v = split(#args, ','); err(_v.begin(), args); puts("");}
vector<string> split(const string& s, char c) {vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.emplace_back(x); return move(v);}
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) {cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; err(++it, args...);}

#define pb push_back
#define mp make_pair
#define all(x)  (x).begin(),(x).end()
#define tr(c, it)   for(auto it=c.begin(); it!=c.end(); it++)
#define clr(a, b)   memset(a, b, sizeof(a))

int T;

string dd[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int cnt[33];
bool find_it;
string ans;

void dfs(int count, string tmp)
{
    if(count == 0)
    {
        ans = tmp;
        find_it = true;
        return;
    }

    if(count < 0)
        return;

    for(int i=0; i<=9; i++)
    {
        bool ok = true;
        if(find_it) return;

        for(int j=0; j<dd[i].size(); j++)
        {
            int ch = dd[i][j] - 'A';
            if(cnt[ ch  ] == 0)
            {
                ok = false;
                break;
            }
        }

        if(ok == false)
            continue;

        string new_tmp = tmp;
        new_tmp += '0' + i;

        for(int j=0; j<dd[i].size(); j++)
        {
            int ch = dd[i][j] - 'A';
            cnt[ch] --;
        }

        dfs(count - dd[i].size(), new_tmp);

        for(int j=0; j<dd[i].size(); j++)
        {
            int ch = dd[i][j] - 'A';
            cnt[ch] ++;
        }
    }

}

int main()
{
#ifdef LOCAL
    //freopen("in", "r", stdin);

    //freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt1.in", "r", stdin);
    //freopen("A-large.in", "r", stdin);
    freopen("out", "w", stdout);
#endif

    int cas = 1;
    cin >>T;

    while(T--)
    {
        string a;
        cin >> a;

        clr(cnt, 0);
        for(int i=0; i<a.size(); i++)
        {
            cnt[a[i] - 'A'] ++;
        }

        cout << "Case #" << cas++ << ": ";

        string tmp = "";
        ans = "";
        find_it = false;
        dfs(a.size(), tmp);

        cout << ans << endl;
    }

    return 0;
}
