#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int P = 1000000007;
int test, n, v[27], orr[27], next[27], last[27], c[101], same[27];
string str, str1[101];
bool b[27], bbe[27], mid[27], head[27], be[27];

bool check(string str){
    memset(last, 255, sizeof(last));
    for (int i = 0; i < str.size(); i++)
    {
        if (last[str[i] - 'a'] != -1 && last[str[i] - 'a'] != i - 1)
           return false;
        last[str[i] - 'a'] = i;
    }
    return true;
}
            
int main(){
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    scanf("%d", &test);
    for (int uu = 1; uu <= test; uu++)
    {
        memset(be, false, sizeof(be));
        memset(mid, false, sizeof(mid));
        memset(v, 0, sizeof(v));
        //memset(a, 0, sizeof(a));
        memset(orr, 0, sizeof(orr));
        memset(same, 0, sizeof(same));
        memset(next, 255, sizeof(next));
        memset(head, true, sizeof(head));
        printf("Case #%d: ", uu);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) cin >> str1[i];
        bool ok = true;
        for (int i = 1; i <= n; i++)
        {
            str = str1[i];
            if (str[0] == str[str.size() - 1]) 
               ++same[str[0] - 'a'];
            if (!check(str))
            {
               ok = false;
               break;
            }
            int L = 0, R = str.size() - 1;
            for (; L < str.size(); L++)
                if (str[L] != str[0]) break;
            for (; R >= 0; R--)
                if (str[R] != str[str.size() - 1]) break;
            if (L <= R) 
               for (int j = L; j <= R; j++)
                   mid[str[j] - 'a'] = true;
            memset(b, false, sizeof(b));
            for (int j = 0; j < str.size(); j++)
                   b[str[j] - 'a'] = true;
            for (int j = 0; j < 26; j++)
                if (b[j]) ++orr[j];
            if (str[0] != str[str.size() - 1])
            {
               int S = str[0] - 'a', 
                   T = str[str.size() - 1] - 'a';
               if (next[S] != -1)
               {
                  ok = false;
                  break;
               }
               next[S] = T;
            }
            be[str[0] - 'a'] = true;
        }
        if (ok)
        for (int i = 0; i < 26; i++)
            if (orr[i] > 1 && mid[i])
            {
               ok = false;
               break;
            }
        int total = 0;
        if (ok)
        {
           for (int i = 0; i < 26; i++)
               if (next[i] != -1) ++v[next[i]];
           for (int i = 0; i < 26; i++)
               if (v[i] > 1) 
               {
                  ok = false;
                  break;
               }
           int k = 0;
           for (int i = 0; i < 26; i++)
               if (!v[i]) 
               {
                  c[++k] = i;
                  if (be[i]) ++total;
               }
           for (int l = 1; l <= k; l++)
           {
               int m = c[l];
               if (next[m] != -1)
                  if (!--v[next[m]]) c[++k] = next[m];
           }
           if (k != 26)
              ok = false;
        }
        if (!ok) printf("0\n");
        else
        {
            long long ans = 1;
            for (int i = 1; i <= total; i++) ans *= i, ans %= P;
            for (int i = 0; i < 26; i++)
                for (int j = 1; j <= same[i]; j++)
                    ans *= j, ans %= P;
            cout << ans << endl;
        }
    }
}
         
           
        
        
                
