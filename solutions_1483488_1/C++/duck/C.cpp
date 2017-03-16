#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	int ca,A,B,i,ans,s,d,q,r,t[7],j,k,flag;

	freopen( "in.txt", "r", stdin );
	freopen( "out.txt", "w", stdout );
	scanf("%d\n", &ca);
	for (int ci = 1; ci <= ca; ++ci) {
		printf("Case #%d: ", ci);
		scanf("%d%d",&A,&B);
		ans = 0;
		for (i = A ; i <= B ; ++i){
			j = 0;
			for (k = 0; k <= 6  ; ++k)
			{
				t[k]=0;
			}
			t[j] = i;
			j++;
			s = log10(double(i))+1;
			//printf("s = %d,",s);
			for (d = 1;d < s; d++)
			{
				q = pow( 10,double( d ));
				//printf("q = %d",q);
				if (i % q != 0 && i/q != 0)
				{
					r = (i % q) * pow(10,double (s - d)) + i / q;
					flag = 0;
					for (k = 0; k <= 6 ; ++k){ if(r == t[k]) flag = 1;}
					if (r >= A && r <= B && flag == 0) {ans++;t[j] = r;j++;};
				}
			}
		}
		printf("%d",ans/2);
		printf("%c",'\n');
	}
	return 0;
}