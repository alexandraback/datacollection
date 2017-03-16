#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define rep(I,N) for(int (I) = 0; (I) < (N); (I)++)

typedef pair<int,int> pii;
typedef long long ll;

#define MAXN 1000007
int getRev(int x){
    int res = 0;
    while(x){
        res *= 10;
        res += x % 10;
        x/=10;
    }
    return res;
}
int tab[MAXN];
bool found[MAXN];
void val(int x){
    tab[getRev(x)] = min(tab[getRev(x)], tab[x]+1);
    tab[x+1] = min(tab[x+1], tab[x] + 1);
}
int main(){
    int t;
    rep(i, 1000001)
        tab[i] = i;
    for(int i = 1; i <= 1000000; i++)
        val(i);
    scanf("%d",&t);
    rep(testId,t){
        printf("Case #%d: ", testId+1);
        int n; scanf("%d",&n);
        printf("%d\n", tab[n]);
    }
}
