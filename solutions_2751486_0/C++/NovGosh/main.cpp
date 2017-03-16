#include <cstdio>
#include <fstream>
#include <iostream>

#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <vector>
#include <bitset>
#include <string>
#include <cstring>
#include <algorithm>

#include <ctime>
#include <cstdlib>
#include <cassert>

#define pb push_back
#define mp make_pair
#define sz(A) (int) (A).size()

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eputs(A) fputs((A), stderr)

#define sqr(A) ((A) * (A))
#define x first
#define y second
  
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair <int, int> pii;

const int N = (int) 1e6 + 1;
const string L = "aeiou";
 
int t, n, len, cnt[N];
bool a[N], good[N];
char s[N];
LL ans;

int get (int l, int r)
{
    return cnt[r] - cnt[l];
}

bool test (char c)
{
    for (int i = 0; i < sz(L); i++)
        if (c == L[i])
            return false;
    return true;
}

int main () 
{
    #ifdef DEBUG
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    #endif
    
    scanf("%d", &t);
    for (int T = 0; T < t; T++) {
        memset(good, 0, sizeof(good));
        memset(a, 0, sizeof(good));

        scanf("%s %d", s, &n);        
        int len = strlen(s);

        for (int i = 0; i < len; i++) {
            a[i] = test(s[i]);    
            cnt[i + 1] = cnt[i] + a[i];
        }
        
        for (int i = 0; i <= len - n; i++) {
            if (get(i, i + n) == n)
                good[i] = true;
        }

        ans = 0;
        for (int i = 0, j = 0; i < len; i++) {
            while (j < i || j < len && !good[j])
                j++;

            if (j == len)
                continue;

            int first = j + n - 1;
            ans += len - first;
        
            //eprintf("pos = %d, good = %d, first = %d, last = %d, += %d\n", i, j, first, len, len - first);
        }

        printf("Case #%d: %I64d\n", T + 1, ans);
        //cerr << endl << endl;
    }

    return 0; 
}

