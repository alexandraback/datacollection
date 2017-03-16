#include <bits\stdc++.h>
#include <inttypes.h>
using namespace std;
typedef long long ll;
template <class T> T sqr(T x) { return x*x; }

int T,N,J;
int X[50];
int primes[10] = {2,3,5,7,11, 13,17,19,23,29};

ll finddiv(int b){
    for(int i=0; i<10; i++){
        int p = primes[i];
        int rem = 0;
        for(int i=0; i<N; i++)
            rem = (rem*b + X[i])%p;
        if (rem == 0)
            return p;
    }
    return 0;
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

    X[0] = 1; X[N-1] = 1;
    printf("Case #1:\n");
    int found = 0;
    while(1){
        vector<int> divs;
        bool jamcoin = 1;
        for(int b = 2; b<=10 && jamcoin; b++){
            int div = finddiv(b);
            if (!div){
                jamcoin = 0;
            }
            else
                divs.push_back(div);
        }
        if (jamcoin){
            found++;
            for(int i=0; i<N; i++)
                printf("%d",X[i]);
            for(int div: divs)
                printf(" %d", div);
            printf("\n");
        }
        if (found == J)
            break;
        addone(X+1, N-2);
    }
	return 0;
}



