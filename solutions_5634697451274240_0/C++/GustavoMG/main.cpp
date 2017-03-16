#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int TC, tc;
string s, s2;
char cad[100 + 5];
int ans, aux;

int main() {
    freopen("i.in", "r", stdin);
    freopen("o.out", "w", stdout);
    scanf("%d", &TC);
    while(tc != TC) {
        scanf("%s", cad);
        s = cad;
        s2 = "";
        for(int i = 0; i < s.length(); i++) {
            s2 += '+';
        }
        ans = 0;
        while(s != s2) {
            if(s[0] == '+') {
                for(int i = 0; s[i] == '+'; i++) {
                    s[i] = '-';
                }
                ans++;
            }
            for(aux = s.length() - 1;s[aux] == '+'; aux--);
            reverse(s.begin(), s.begin() + aux + 1);
            for(int i = 0; i <= aux; i++) {
                if(s[i] == '+') {
                    s[i] = '-';
                } else {
                    s[i] = '+';
                }
            }
            ans++;
        }
        printf("Case #%d: %d\n", ++tc, ans);
    }
    fclose(stdin);
    fclose(stdout);
}
