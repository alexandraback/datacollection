#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define INF 999999999
#define EPS .000000001
#define mp make_pair
#define pb push_back
#define fs first
#define sc second

typedef long long LL;
typedef unsigned long long ULL;
typedef pair < int, int > II;
typedef pair < ULL, ULL > ULLULL;
typedef vector < int > VI;
typedef vector < II > VII;

VI a, b, c;

int main(){
    freopen("input_large.txt", "rt", stdin);
    freopen("output_large.txt", "wt", stdout);
    int T = 0;
    cin >> T;
    for(int sh = 0; sh < T; ++sh){
        int n = 0;
        cin >> n;
        a.resize(n);
        b.resize(n);
        c.resize(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i] >> b[i];
            c[i] = 0;
        }
        int now = 0, num = 0;
        bool ex = false;
        while(now < 2*n){
            int nm = -1, st = 0;
            for(int i = 0; i < n; ++i)
                if(b[i] <= now && 2-c[i] > st)
                    nm = i, st = 2-c[i];
            if(nm != -1){
                now += st;
                c[nm] += st;
                ++num;
            }
            else{
                for(int i = 0; i < n; ++i)
                    if(a[i] <= now && c[i] == 0 && b[i] > st)
                        nm = i, st = b[i];
                if(nm == -1){
                    printf("Case #%d: Too Bad\n", sh+1);
                    ex = true;
                    break;
                }
                now++;
                c[nm] = 1;
                ++num;
            }
        }
        if(!ex)printf("Case #%d: %d\n", sh+1, num);
    }
    return 0;
}
