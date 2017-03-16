#include <stdio.h>
#include <algorithm>
using namespace std;

int A,B; double P[100005],F[100005],K,X;

int main()
{
	int T,Case=0;
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
	int i;

	scanf ("%d",&T); while (T--){
		scanf ("%d %d",&A,&B); X = B + 2; K = 1;
		for (i=1;i<=A;i++) scanf ("%lf",&P[i]);
		for (i=A+1;i<=B;i++) P[i] = 1;
		F[0] = 1;
		for (i=1;i<=B;i++) F[i] = F[i-1] * P[i];

		for (i=0;i<=A;i++){
			K = F[i] * (A - i + B - i + 1) + (1 - F[i]) * (A - i + B - i + 1 + B + 1);
			X = min(K,X);
		}

		printf ("Case #%d: %.8lf\n",++Case,X);
	}
}