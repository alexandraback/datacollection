#include <stdio.h>
#include <algorithm>
using namespace std;

int T,C,A,B,U,CHK[10000200]; long long CNT;

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
	int i,j,p,s;

	scanf ("%d\n",&T); while (T--){
		scanf ("%d %d",&A,&B); CNT = 0;
		for (i=0;i<=10000000;i++) CHK[i] = 0;
		for (i=2,p=10;i<8;i++,p*=10){
			for (j=p;j<p*10;j++) if (CHK[j] == 0){
				s = j; U = 0;
				while (CHK[s] == 0){
					CHK[s] = 1;
					if (A <= s && s <= B) U++;
					do{ s = (s % p) * 10 + (s / p); }while (s / p == 0);
				}
				CNT += U * (U - 1) / 2;
			}
		}
		printf ("Case #%d: %lld\n",++C,CNT);
	}

	return 0;
}