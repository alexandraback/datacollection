#include <bits/stdc++.h>
#define MA(a,b) ((a)>(b)?(a):(b))
#define MI(a,b) ((a)<(b)?(a):(b))
#define AB(a) (-(a)<(a)?(a):-(a))
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pob pop_back
#define ep 0.00000001
#define pi 3.1415926535897932384626433832795
#define na(x) ((x)<P?(x):(x)-P)
using namespace std;
int main() {
    freopen("B1","r",stdin);
	freopen("ans.txt","w",stdout);
	int T;
	cin>>T;
	int n,k,A,S;
	int a[10000];
	int test=0;
	while (T--){
        scanf("%d",&n);
        for (int i=0;i<=1000;i++) a[i]=0;
        A=0;
        for (int i=1;i<=n;i++){
            scanf("%d",&k);
            a[k]++;
            A=MA(A,k);
        }
        n=A;
        S=0;
        for (int i=1;i<=n;i++){
            S=0;
            for (int j=i+1;j<=n;j++)
            S+=((j+i-1)/i-1)*a[j];
            A=MI(A,S+i);
        }
        printf("Case #%d: %d\n",++test,A);
	}
	return 0;
}
