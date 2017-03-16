#include <bits\stdc++.h>
using namespace std;
typedef long long ll;
template <class T> T sqr(T x) { return x*x; }

int T,N,J;
int X[50];
int primes(int N, int* &pp){
    bool* sieve = new bool[N+1];
    memset(sieve,1,N+1);

    int nrprimes = 0;
    int r = sqrt(N);
    for(int i=2; i<=N; i++)
        if (sieve[i]){
            nrprimes++;
            if (i<=r)
                for(int j = i*i; j<=N; j+=i)
                    sieve[j] = 0;
        }


    pp = new int[nrprimes];
    int pos = 0;
    for(int i=2; i<=N; i++)
        if (sieve[i])
            pp[pos++] = i;

    delete[] sieve;
    return nrprimes;
}

ll finddiv(ll n){
    if (n%2==0) return 2;
    for(ll d = 3; d*d<=n; d++){
        if (n%d==0) return d;
    }
    return 0;
}

ll interpret(int* X, int b){
    ll B = b;
    ll res = 0;
    for(int i=0; i<N; i++)
        res = B*res + X[i];
    return res;
}

void addone(int* X, int n){
    int c = 0;
    X[n-1]++;
    for(int i=n-1; i>=0; i--)
    {
        int u = X[i]+c;
        X[i] = u%2;
        c = u/2;
    }
}

int main(){
	#ifdef LOCAL_PROJECT
		freopen("d:\\src\\CppProjects\\stdin","r",stdin);
		freopen("d:\\src\\CppProjects\\stdout","w",stdout);
	#endif
    scanf("%d%d%d", &T, &N, &J);
    int* pp;
    primes(1<<(N/2), pp);
    vector<ll> sols;
    X[0] = 1; X[N-1] = 1;
    printf("Case #1:");
    int found = 0;
    for(int x = (1<<N) + 1; x< 1<<(N+1); x+=2){
        ll n;
        bool jamcoin = 1;
        vector<ll> divs;
        for(int b = 2; b<=10 && jamcoin; b++){
            n = interpret(X,b);
            int div = finddiv(n);
            if (!div){
                jamcoin = 0;
                //printf("\n --- fail at %d",b);
            }
            else
                divs.push_back(div);
        }
        if (jamcoin){
            found++;
            printf("\n%I64d ", n);
            for(ll div: divs)
                printf("%I64d ", div);
        }
        if (found == J)
            break;
        addone(X+1, N-2);
    }
	return 0;
}



