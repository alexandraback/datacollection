#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define NL '\n'
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pi 2.0*acos(0.0)
#define MOD 1000000007
#define MAX 100005

vector <char> v;
int a[100];

void go(char x, char ch, string s)
{
    while(a[ch] > 0)
    {
        for(int i = 0; i < s.size(); i++)
            a[ s[i] ]--;
        v.pb(x);
    }
}

void solve()
{
    go('0', 'Z', "ZERO");
    go('2', 'W', "TWO");
    go('6', 'X', "SIX");
    go('8', 'G', "EIGHT");
    go('3', 'H', "THREE");
    go('7', 'S', "SEVEN");
    go('4', 'R', "FOUR");
    go('5', 'F', "FIVE");
    go('1', 'O', "ONE");
    go('9', 'N', "NINE");
}

int main()
{
    //READ("A-small-attempt0.in");
    //WRITE("A-small-attempt0.out");
    std::ios_base::sync_with_stdio(0);
    int cases, caseno=0, n, i, j, k, cnt, sum;
    string s;

    cin >> cases;

    while(cases--)
    {
        cin >> s;

        mem(a,0);
        v.clear();

        n = s.size();

        for(i = 0; i < n; i++)
            a[ s[i] ]++;

        solve();

        sort(v.begin(),v.end());

        cout << "Case #" << ++caseno << ": ";

        for(i = 0; i < v.size(); i++)
            cout << v[i];

        cout << NL;
    }

    return 0;
}




