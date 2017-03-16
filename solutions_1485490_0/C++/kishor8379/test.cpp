#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

FILE * fin = fopen("f:/cj/a.in","r");
FILE * fout = fopen("f:/cj/a.out","w");


long long g_ans = 0 ;

long long Matchbox(long long tot, long long *Ni,long long *Mi,long long pN,long long pM, int in, int im,int N, int M ) {
	if( in >= N || im >= M) {
		if( g_ans < tot ) {
			g_ans = tot ;
		}
		return tot;
	}

	if( Ni[in*2+1] == Mi[im*2+1] ) {
		if( Ni[in*2]-pN < Mi[im*2]-pM ) {
			tot += Ni[in*2]-pN ;
			
			pM+= Ni[in*2]-pN ;
			in+=1;
			pN =0;

		} else if( Ni[in*2]-pN == Mi[im*2]-pM ) {
			tot += Mi[im*2]-pM ;
					
			in+=1;
			pN =0;
			im+=1;
			pM =0;

		}else {
			tot += Mi[im*2]-pM ;
			
			pN+= Mi[im*2]-pM ;
			im+=1;
			pM =0;
		}
		
		Matchbox(tot,Ni,Mi,pN,pM,in,im,N,M);
	
	} else {
		Matchbox(tot,Ni,Mi,0,pM,in+1,im,N,M);
		Matchbox(tot,Ni,Mi,pN,0,in,im+1,N,M);
	
	}

		
	
};

int main () {

			
	int tc ;
	fscanf(fin,"%d",&tc);
	int t = 0 ;
	long long * Ni = new long long[ 201 ];
	long long * Mi = new long long[ 201 ];

	while( t < tc ) {
		t++ ;
		int N = 0 ;
		int M= 0 ;
		g_ans=0;
		fscanf(fin,"%d%d",&N,&M);
		memset(Ni,0,1608);
		memset(Mi,0,1608);

		for( int i = 0 ; i < 2*N ; i++ ) {

			fscanf(fin,"%lld",&Ni[i]);
			printf(" i = Ni = %lld",Ni[i]);
			
		}
		for( int i = 0 ; i < 2*M ; i++ ) {
			fscanf(fin,"%lld",&Mi[i]);
		}
		long long tot = 0 ;
		Matchbox(tot,Ni,Mi,0,0,0,0,N,M);
	
		fprintf(fout,"Case #%d: %lld\n",t,g_ans);
		
		
				
	}

	
	fflush(fout);
	fclose(fout) ;
	fclose(fin);

	return 0 ;

}
