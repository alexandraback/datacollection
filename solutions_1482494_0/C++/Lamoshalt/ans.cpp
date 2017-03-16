#include <stdio.h>

int calTimes(int N, int *a, int *b);

void main()
{
	FILE *in, *out;
	int T, N;
	int a[1000], b[1000];
	int n,i,temp;

	in = fopen("B-small-attempt3.in","r");
	out = fopen("B-small-attempt3.out","w");

	fscanf(in,"%d",&T);
	
	for(n=1; n<=T; n++) {

		fscanf(in,"%d",&N);

		for(i=0; i<N; i++)
			fscanf(in,"%d %d",&a[i],&b[i]);

		temp = calTimes(N, a, b);
		
		if( temp > 0)		
			fprintf(out,"Case #%d: %d\n",n, temp);
		else
			fprintf(out,"Case #%d: Too Bad\n",n);
	}
}

int calTimes(int N, int *a, int *b)
{
	int marking[2][1000] = {0};
	int i, index, starts, second, plays, temp;

	starts = 0;
	second = 0;
	plays = 0;

	while(1) {

		//search 2star
		index = -1;
		for(i=0; i<N; i++) {
			if( !marking[1][i] && starts >= b[i] ) {
				marking[1][i] = 1;
				index = i;
				break;
			}
		}

		if( index >= 0 ) {

			if( marking[0][index] )
				starts++;
			else
				starts += 2;

			second++;
			plays++;

			if( second == N )
				break;
			else
				continue;
		}

		//search 1star
		index = -1;
		temp = 0;
		for(i=0; i<N; i++) {
			if( !marking[1][i] && !marking[0][i] && starts >= a[i] ) {

				if( temp < b[i] ) {
					index = i;
					temp = b[i];
				}
			}
		}

		if( index < 0 )
			return 0;
		
		marking[0][index] = 1;
		starts++;
		plays++;
	}

	return plays;
}