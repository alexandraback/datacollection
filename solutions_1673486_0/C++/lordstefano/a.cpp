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
#define N 200000

double v[N], p[N];

int main (){
    int A, B;
    int t;
    cin >> t;
    f (test, 1, t+1){
        cin >> A >> B;
        f (i, 0, A) scanf("%lf", &p[i]);
        v[0] = p[0];
        f (i, 1, A) v[i] = v[i-1]*p[i];
        double ans = 1e9;
        f (i, 0, A){
            double esp = (v[i])*(A-i-1.+B-i-1+1)+(1.-v[i])*(A-i-1.+B-i-1.+B+2);
            ans = min (ans, esp);
        }
        ans = min (ans, B+2.);
        printf("Case #%d: %lf\n", test, ans);

    }

	return 0;
}
