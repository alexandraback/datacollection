#include <stdio.h>
#include <algorithm>
using namespace std;

int N,X,Y;

void input()
{
	scanf ("%d %d %d",&N,&X,&Y);
	if (X < 0) X = -X;
}

double comb[1000][1000];
double proc()
{
	int k = 0, d = 0, c, left, right, i;
	while (1){
		k += 4 * d + 1;
		if (N == k){
			if ((X + Y) / 2 <= d) return 1;
			return 0;
		}
		if (N < k){
			if ((X + Y) / 2 < d) return 1;
			if ((X + Y) / 2 > d) return 0;
			c = N - k + 4 * d + 1;
			double ans = 0;
			for (i=0;i<=c;i++){
				right = i;
				left = c - right;
				if (right > d * 2) left += right - d * 2;
				if (left > d * 2) left = d * 2;

				if (left-1 >= Y) ans += comb[c][i];
			}
			for (right=0;right<c;right++) ans /= 2;
			return ans;
		}
		d++;
	}
	return -1;
}

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int Test,Case=1;

	int i,j;

	for (i=0;i<1000;i++){
		comb[i][0] = comb[i][i] = 1;
		for (j=1;j<i;j++) comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
	}

	scanf ("%d",&Test); while (Test--){
		input();
		double a = proc();
		printf ("Case #%d: %.10lf\n",Case++,a);
	}

	return 0;
}