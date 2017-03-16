#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
#define X first
#define Y second
#define mk make_pair
#define pb push_back
#define ms(a, x) memset(a, x, sizeof(a))
#define Rep(i, n) for(int i = 0; i < int(n); i ++)
#define all(x) (x).begin(), (x).end()
#define bit(n) ((1)<<(n))
#define W << " " <<
const int MOD = (int) 1e9 + 7;
const ll base = 31;
const double eps = 1e-3, pi = acos((double) -1);
void MAIN();
int main(){
    //freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    //ios:: sync_with_stdio(false); cin.tie(0);
    MAIN();
    return 0;
}


void MAIN(){
    printf("Case #1:\n");
    Rep(x, 500){
        char *s = new char[64];
        s[0] = s[15] = s[16] = s[31] = '1';
        Rep(i, 14){
            if(x & bit(i)) s[i+1] = s[i+17] = '1';
            else s[i+1] = s[i+17] = '0';
        }
        printf("%s", s);

        for(int i = 2; i <= 10; i ++){
            ll ans = 1;
            Rep(j, 16) ans = ans*i;
            ans += 1;
            printf(" %lld", ans);
        }
        printf("\n");
    }
}
