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
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    //ios:: sync_with_stdio(false); cin.tie(0);
    MAIN();
    return 0;
}



void MAIN(){
    int tc; scanf("%d", &tc);
    char *s = new char[128];
    for(int cs = 1; cs <= tc; cs ++){
        scanf("%s", s);
        int n = strlen(s);
        int cnt = 1;
        for(int i = 1; i < n; i ++) if(s[i] != s[i-1]) cnt ++;
        if(s[n-1] == '+') cnt --;
        printf("Case #%d: %d\n", cs, cnt);
    }
}
