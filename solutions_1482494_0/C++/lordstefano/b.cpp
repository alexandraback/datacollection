#include<iostream>
#include<stack>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<map>
#include<numeric>
#include<sstream>
#include<cmath>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i = x; i<y; i++ )
#define FORV(it,A) for(vector<int>::iterator it = A.begin(); it!= A.end(); it++)
#define FORS(it,A) for(set<int>::iterator it = A.begin(); it!= A.end(); it++)
#define quad(x) (x) * (x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

#define inf 
#define N 1024

struct no{
    int a, b;
};

bool cmp (no x, no y){
    if (x.b != y.b) return x.b < y.b;
    return x.a > y.a;
}


no v[N];
int n;
int ja[N];
int main (){
    int t; cin >> t;
    f (test, 1, t+1){
        scanf("%d", &n);
        f (i, 0, n) scanf("%d %d", &v[i].a, &v[i].b);
        sort (v, v+n, cmp);
        clr (ja, 0);
        int topo = 0;
        int acc = 0;
        int ans = 0;
        while (1){
            bool flag = 0;
            f (i, 0, n) if (ja[i] == 1 && v[i].b <= acc){
                acc++; flag = 1; ja[i] =2;
                ans++;
            }
            if (flag) continue;
            while (topo < n && ja[topo] != 0) topo++;
            if (topo != n && v[topo].b <= acc){
                acc += 2; ja[topo] = 2;
                ans++;
                topo++;
            }
            else{
                flag = 0;
                for (int i = n-1; i >= 0; i--){
                    if (ja[i] == 0 && v[i].a <= acc){
                        acc++; ja[i] = 1; flag = true;
                        ans++;
                        break;
                    }
                }
                if (!flag) break;
            }
        }
        printf("Case #%d: ", test);
        if (acc == n*2) printf("%d\n", ans);
        else printf("Too Bad\n");

    }

	return 0;
}
