#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<set>
using namespace std;
#define ll long long
ll ans;
int f[10000000];
int n;
string s;

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    int ts, ks, i, j;
    cin >> ts;
    for (ks =0 ; ks < ts; ks++){
        cin >> s >> n;
        j = 0;
        ans = 0;
        for (i = 0; i < s.length(); i++){
            if ((s[i] == 'a') || (s[i] == 'e') || (s[i] == 'i') || (s[i] == 'o') || (s[i] == 'u')){
               j = 0;
            }
            else {
                 j++;
            }
                 if (j >= n)
                    f[i] = i - n + 1;
                 else if (i == 0)
                      f[i] = -1;
                      else f[i] = f[i - 1];
            ans = ans + (ll)(f[i] + 1);
        }
        cout << "Case #" << ks + 1 << ": " << ans << endl;
    }
    return 0;
}
