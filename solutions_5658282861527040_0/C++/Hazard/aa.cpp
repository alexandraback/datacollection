#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	FILE *in =fopen ("input.txt","r");
	FILE *out =fopen ("output.txt","w");
	int T;
	fscanf(in,"%d",&T);
	for(int t=1;t<=T;t++){
		int A,B,K;
		fscanf(in,"%d%d%d",&A,&B,&K);

		int ans=0;
		for(int i=0;i<A;i++){
			for(int j=0;j<B;j++){
				if((i&j) < K) ans ++;
			}
		}

		fprintf(out,"Case #%d: %d\n",t,ans);
	}
	return 0;
}