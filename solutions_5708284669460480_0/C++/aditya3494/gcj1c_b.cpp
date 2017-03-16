#include <bits/stdc++.h>

using namespace std;
typedef long long lli;

vector<string> v;
string keybrd;
string trgt;
int lps[101];
char txt[101];
char pat[101];

lli gcd(lli a, lli b)
{
    if(a == 0) {
        return b;
    } else {
        return gcd(b%a, a);
    }
}

lli exp(lli b, lli n, lli MOD)
{
    lli ans = 1;
    while(n > 0) {
        if(n&1) ans = (ans * b) % MOD;
        n >>= 1;
        b = (b * b) % MOD;
    }
    return ans;
}


int K, S, L;

void func(string str, int len)
{
    if(len == S) {
        v.push_back(str);
        return;
    } else {
        for(int i = 0;i < K;i++) {
            string str2 = str+keybrd[i];
            func(str2, len+1);
        }
    }
}

void buildlps()
{
    lps[0] = 0;
    int k = 0;
    int len = strlen(pat);

    for(int i = 1;i < len;i++) {
        while(k > 0 && pat[k] != pat[i]) {
            k = lps[k-1];
        }

        if(pat[k] == pat[i]) {
            k++;
        }

        lps[i] = k;
    }
}

int kmp()
{
    int len = strlen(txt);
    int found = strlen(pat);
    int ans = 0;

    int q = 0;
    for(int i = 0;i < len;i++) {
        while(q > 0 && pat[q] != txt[i]) {
            q = lps[q-1];
        }

        if(pat[q] == txt[i]) {
            q++;
        }
        if(q == found) {
            ans++;
            q = lps[q-1];
        }
    }

    return ans;
}

int main()
{
    freopen("f2.in", "r", stdin);
    freopen("f2out.txt", "w", stdout);

    int t;
    cin >> t;
    for(int kase = 1;kase <= t;kase++) {
        v.clear();
        cin >> K >> L >> S;
        cin >> keybrd;
        cin >> trgt;
        func("", 0);
        strcpy(pat, trgt.c_str());
        int maxx = 0;
        int tot = 0;
        for(int i = 0;i < v.size();i++) {
            strcpy(txt, v[i].c_str());
            buildlps();
            int f = kmp();
            tot += f;
            maxx = max(maxx, f);
        }

        printf("Case #%d: %0.8lf\n", kase, maxx - (1.0 * tot)/v.size());
    }

    return 0;
}

