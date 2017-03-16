#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

FILE * fin = fopen("f:/cj/a.in","r");
FILE * fout = fopen("f:/cj/a.out","w");
#define ll long long


int setvisited(int idx ,int N, int * arr , int *v ) {
	for( int i = 0 ; i < N ; i++ ) {
		if( arr[idx*N+i] == 1 && i != idx) {
			v[i]++;
			if( v[i] >=2 ) {
				return 1;
			} else {
				if( setvisited(i,N,arr,v) ) {
					return 1;
				}
				
			}
		}
	}
	return 0 ;
};

int main () {

			
	int tc ;
	fscanf(fin,"%d",&tc);
	int t = 0 ;
	int *arr = new int[1000*1000];
	int *v = new int[1000];
	while( t < tc ) {
		t++ ;
		int N = 0 ;
		int M= 0 ;
		fscanf(fin,"%d",&N);
		memset(arr,0,4000000);
		memset(v,0,4000);
		int i = 0;
		for( i = 0 ; i < N ; i ++ ) {
							
			fscanf(fin,"%d",&M);
			for( int j =0 ; j < M ; j++ ) {
				int C=0;
				fscanf(fin,"%d",&C);
				arr[i*N+C-1]=1;
			}
			

		}
//		int i = 0;
		for( i = 0; i < N ; i ++ ) {
			memset(v,0,4000);
			if( setvisited(i,N,arr ,v ) ) {
				break;
			}
		}
		if( i == N ) {
			fprintf(fout,"Case #%d: No\n",t);
		} else {
			fprintf(fout,"Case #%d: Yes\n",t);
		}
		
				
	}

	delete(arr);
	fflush(fout);
	fclose(fout) ;
	fclose(fin);

	return 0 ;

}
