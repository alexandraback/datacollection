#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <set>
#include <stack>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FE(a,b) for(__typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PII pair<int, int>
#define x first
#define y second

using namespace std;

int t, n;
double S[210];
double p, k, x, s, r;

bool check(double w, int i){
    s = 0;
    r = S[i] + x*w/100.0;
    FWD(j,0,n)
        s += max(0.0, r - S[j]);
    return s >= x;
}

int main(){
	scanf("%d", &t);
	FWD(ttt,1,t+1){
		scanf("%d", &n);
		printf("Case #%d: ", ttt);
        x = 0;
		FWD(i,0,n){
            scanf("%lf", &S[i]);
            x += S[i];
		}
		FWD(i,0,n){
            p = 0;
            k = 100;
            FWD(g,0,100){
                if(check((p+k)/2.0, i)/2.0)
                    k = (p+k)/2.0;
                else
                    p = (p+k)/2.0;
            }
            printf("%.6lf ", p);
		}
		printf("\n");
	}
	return 0;
}
