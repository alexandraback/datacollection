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

int t, k, s, c;

lint getpow(int a, int x){
    lint res = 1ll;
    while(x > 0){
        res = res * a;
        x--;
    }
    ret res;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d", &t);
    F(i, 0, t){
        scanf("%d%d%d", &k, &c, &s);
        printf("Case #%d: ", i + 1);
        if(c == 1){
            if(s < k)
                printf("IMPOSSIBLE");
            else
                F(j, 1, k + 1)
                    printf("%d ", j);
            printf("\n");
            continue;
        }
        lint block = getpow(k, c - 1);
        int sz = k/2 + k%2;
        if(sz > s){printf("IMPOSSIBLE\n"); continue;}
        lint cpos = 0ll;
        for(int i = 0; i < (k - k%2); i += 2){
            printf("%lld ", cpos + i + 2);
            cpos += block + block;
        }
        if(k % 2 == 1){
            printf("%lld", block * k);
        }
        printf("\n");
    }
    ret 0;
}
