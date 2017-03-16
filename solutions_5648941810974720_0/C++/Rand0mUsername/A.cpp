// RandomUsername (Nikola Jovanovic)
// GCJ 2016 1B
// A

#include <bits/stdc++.h>
#define DBG false
#define debug(x) if(DBG) printf("(ln %d) %s = %d\n", __LINE__, #x, x);
#define lld long long
#define ff(i,a,b) for(int i=a; i<=b; i++)
#define fb(i,a,b) for(int i=a; i>=b; i--)
#define par pair<int, int>
#define fi first
#define se second
#define mid (l+r)/2
#define INF 1000000000
#define MAXN 2005

using namespace std;

int t;
char s[MAXN];
int cnt[1000];
vector<int> out;

void solve()
{
    // 0
    while(cnt['Z'] > 0)
    {
        out.push_back(0);
        cnt['Z']--;
        cnt['E']--;
        cnt['R']--;
        cnt['O']--;
    }
    // 2
    while(cnt['W'] > 0)
    {
        out.push_back(2);
        cnt['T']--;
        cnt['W']--;
        cnt['O']--;
    }
    // 6
    while(cnt['X'] > 0)
    {
        out.push_back(6);
        cnt['S']--;
        cnt['I']--;
        cnt['X']--;
    }
    // 4
    while(cnt['U'] > 0)
    {
        out.push_back(4);
        cnt['F']--;
        cnt['O']--;
        cnt['U']--;
        cnt['R']--;
    }
    // 1
    while(cnt['O'] > 0)
    {
        out.push_back(1);
        cnt['O']--;
        cnt['N']--;
        cnt['E']--;
    }
    // 8
    while(cnt['G'] > 0)
    {
        out.push_back(8);
        cnt['E']--;
        cnt['I']--;
        cnt['G']--;
        cnt['H']--;
        cnt['T']--;
    }
    // 3
    while(cnt['H'] > 0)
    {
        out.push_back(3);
        cnt['T']--;
        cnt['H']--;
        cnt['R']--;
        cnt['E']--;
        cnt['E']--;
    }
    // 5
    while(cnt['F'] > 0)
    {
        out.push_back(5);
        cnt['F']--;
        cnt['I']--;
        cnt['V']--;
        cnt['E']--;
    }
    // 7
    while(cnt['V'] > 0)
    {
        out.push_back(7);
        cnt['S']--;
        cnt['E']--;
        cnt['V']--;
        cnt['E']--;
        cnt['N']--;
    }
    // 9
    while(cnt['N'] > 0)
    {
        out.push_back(9);
        cnt['N']--;
        cnt['I']--;
        cnt['N']--;
        cnt['E']--;
    }
}

int main()
{
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    scanf("%d", &t);
    ff(tt, 1, t)
    {
        out.clear();
        ff(i, 'A', 'Z')
            cnt[i] = 0;

        scanf("%s", s);
        int n = strlen(s);
        ff(i, 0, n-1)
        {
           cnt[ s[i] ]++;
        }
        // cnt filled, let's go
        solve();
        // output
        sort(out.begin(), out.end());
        printf("Case #%d: ", tt);
        int sz = out.size();
        ff(i, 0, sz-1)
        {
            printf("%d", out[i]);
        }
        printf("\n");
    }
    return 0;
}