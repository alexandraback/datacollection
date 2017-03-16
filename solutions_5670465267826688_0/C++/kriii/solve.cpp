#include <stdio.h>
#include <algorithm>
using namespace std;

int quat[5][5] = {{0,0,0,0,0},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};
int mult(int a, int b)
{
	return quat[abs(a)][abs(b)] * a / abs(a) * b / abs(b);
}
int tr(char a)
{
	if (a == 'i') return 2;
	if (a == 'j') return 3;
	if (a == 'k') return 4;
	return -1;
}

int L,l[10010],r[10010]; long long X;
char S[10010];

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
	int Test; scanf ("%d",&Test); for (int Case=1;Case<=Test;Case++){
		printf ("Case #%d: ",Case);

		scanf ("%d %lld",&L,&X);
		scanf ("%s",S+1);

		l[0] = 1;
		for (int i=1;i<=L;i++) l[i] = mult(l[i-1],tr(S[i]));
		r[L+1] = 1;
		for (int i=L;i>=1;i--) r[i] = mult(tr(S[i]),r[i+1]);

		bool good = false;
		int all = l[L];
		int conall = 1;
		for (int i=0;i<X%4;i++) conall = mult(conall,all);

		if (conall == -1){
			for (int i=1;i<=L;i++) for (int j=1;j<=L;j++){
				long long st = L * X + 1, ed = -1;
				if (l[i] == 2) st = i;
				else if (mult(all,l[i]) == 2) st = L + i;
				else if (mult(-1,l[i]) == 2) st = L*2 + i;
				else if (mult(-all,l[i]) == 2) st = L*3 + i;
				if (r[j] == 4) ed = L*(X-1) + j;
				else if (mult(r[j],all) == 4) ed = L*(X-2) + j;
				else if (mult(r[j],-1) == 4) ed = L*(X-3) + j;
				else if (mult(r[j],-all) == 4) ed = L*(X-4) + j;
				if (st + 1 < ed) good = 1;
			}
		}
		puts(good?"YES":"NO");
	}

	return 0;
}