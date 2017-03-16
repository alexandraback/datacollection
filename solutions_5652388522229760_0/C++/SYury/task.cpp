#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<cstring>
#include<cassert>
#include<ctime>
#include<vector>
#include<list>
#include<stack>
#include<deque>
#include<queue>
#include<map>
#include<utility>
#include<set>
#include<algorithm>

using namespace std;
typedef long long lint;
typedef long double ldb;

const int inf = 1000000000;
const int maxe = 300010;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define pb push_back
#define rs resize
#define mk make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return

int n, t;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d", &t);
    F(i, 0, t){
        scanf("%d", &n);
        bool was[10];
        int tw = 0;
        memset(was, 0, 10 * sizeof(bool));
        lint wh = 0;
        F(j, 1, 1001){
            lint curr = n * 1ll * j;
            while(curr > 0){
                int c = curr%10;
                if(!was[c]){was[c] = true; tw++;}
                curr/=10;
            }
            if(tw == 10){wh = n * 1ll * j; break;}
        }
        printf("Case #%d: ", i + 1);
        if(tw < 10)
            printf("INSOMNIA\n");
        else
            printf("%lld\n", wh);
    }
    ret 0;
}
