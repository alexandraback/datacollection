//Fruit of Light
//FoL CC
//Apple Strawberry

#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define For(i, n) for(int i = 0; i<(n); ++i)
#define ForEach(it, i) for(typeof i.begin() it = i.begin(); it!=i.end(); ++it)
#define eps 1e-9

typedef long long ll;
typedef pair<int, int> pii;

int A[247];

int extra(){
    int N = 0, X = 0;
    scanf("%d", &N);
    For(i,N) {
        scanf("%d", A+i);
        X+=A[i];
    }    
    For(i,N) {
        double b = 0.0, e = 1.0, m;
        while(e-b>eps){
            m = (b+e)*0.5;
            double suma = 0.0;
            double aspon = A[i]+X*m;
            For(j,N) if (A[j]<aspon) suma += double(aspon-A[j])/double(X);
            if (suma>1.0) e = m;
            else b = m;
        }
        printf(" %.6lf", 100.0*e);
    }
    printf("\n");
}

int main(){
    int T;
    scanf("%d",&T);
    For(i,T){
        printf("Case #%d:",i+1);
        extra();
    }
}
