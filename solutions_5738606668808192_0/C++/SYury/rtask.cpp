#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<complex>
#include<ctime>
#include<cmath>
#include<list>
#include<map>
#include<queue>
#include<string>
#include<cstring>
#include<climits>
#include<stack>

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

using namespace std;
typedef long long int lint;
typedef long double ldb;

int n, j;

lint finddiv(lint x){
    for(lint i = 2; i * i <= x; i++){
        if(x%i == 0)
            ret i;
    }
    ret 1ll;
}

int main(){
    n = 16; j = 50;
    freopen("output.txt", "w", stdout);
    lint hb = (1ll << (n));
    lint lb = (1ll << (n - 1)) + 1;
    printf("Case #1:\n");
    for(lint i = lb; i < hb; i += 2ll){
        if(j <= 0)
            break;
        lint num[11];
        bool good = true;
        F(j, 2, 11){
            num[j] = 0;
            lint cpow = 1ll;
            F(r, 0, n){
                if(i&(1ll << r))
                    num[j] += cpow;
                cpow *= j;
            }
            lint div = finddiv(num[j]);
            if(div == 1ll){good = false; break;}
            num[j] = div;
        }
        if(!good){continue;}
        j--;
        Df(r, n - 1, -1){
            if(i&(1ll << r))
                putc('1', stdout);
            else
                putc('0', stdout);
        }
        printf(" ");
        F(j, 2, 11)
            printf("%lld ",num[j]);
        printf("\n");
    }
    return 0;
}

