#include <bits\stdc++.h>
#include <inttypes.h>
using namespace std;
typedef long long ll;
template <class T> T sqr(T x) { return x*x; }

int T;
int Ks[1000], Cs[1000], Ss[1000];

ll ppow(int x, int n){
    ll res = 1;
    ll q = x;
    while(n){
        if (n%2)
            res *= q;
        q = q*q;
        n /= 2;
    }
    return res;
}

void solve(int testi){
    int K,C,S;
    K = Ks[testi]; C = Cs[testi]; S = Ss[testi];
    printf("Case #%d: ", testi+1);
    for(ll x = 1; x <= K; x++)
        printf("%I64d ", x);
    printf("\n");
}

int main(){
	#ifdef LOCAL_PROJECT
		freopen("d:\\src\\CppProjects\\stdin","r",stdin);
		freopen("d:\\src\\CppProjects\\stdout","w",stdout);
	#endif
    scanf("%d", &T);
    for(int i=0; i<T; i++)
        scanf("%d%d%d",Ks+i, Cs+i, Ss+i);
    for(int i=0; i<T; i++)
        solve(i);
	return 0;
}



