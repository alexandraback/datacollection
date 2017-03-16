int cs[31];
int ss[31];

void initArreglos(){
	
	cs[0]=-1;
	cs[1]=-1;
	cs[2]=2;
	cs[3]=2;
	cs[4]=2;
	cs[5]=3;
	cs[6]=3;
	cs[7]=3;
	cs[8]=4;
	cs[9]=4;
	cs[10]=4;
	cs[11]=5;
	cs[12]=5;
	cs[13]=5;
	cs[14]=6;
	cs[15]=6;
	cs[16]=6;
	cs[17]=7;
	cs[18]=7;
	cs[19]=7;
	cs[20]=8;
	cs[21]=8;
	cs[22]=8;
	cs[23]=9;
	cs[24]=9;
	cs[25]=9;
	cs[26]=10;
	cs[27]=10;
	cs[28]=10;
	cs[29]=-1;
	cs[30]=-1;
	
	ss[0]=0;
	ss[1]=1;
	ss[2]=1;
	ss[3]=1;
	ss[4]=2;
	ss[5]=2;
	ss[6]=2;
	ss[7]=3;
	ss[8]=3;
	ss[9]=3;
	ss[10]=4;
	ss[11]=4;
	ss[12]=4;
	ss[13]=5;
	ss[14]=5;
	ss[15]=5;
	ss[16]=6;
	ss[17]=6;
	ss[18]=6;
	ss[19]=7;
	ss[20]=7;
	ss[21]=7;
	ss[22]=8;
	ss[23]=8;
	ss[24]=8;
	ss[25]=9;
	ss[26]=9;
	ss[27]=9;
	ss[28]=10;
	ss[29]=10;
	ss[30]=10;

}

int maxCS(int x, int p){	
	if (cs[x] >= p) return cs[x];
	return -1;	
}

int maxSS(int x, int p){
	if (ss[x] >= p) return ss[x];
	return -1;	
}

#include <stdio.h>

int main(){

	initArreglos();

	int ndc;
	int caso;
	scanf("%d\n",&ndc);
	
	for(caso=0; caso<ndc; caso++){
		
		// LEER!
		int N, S, P, necesito;
		scanf("%d %d %d ",&N,&S,&P);
		necesito = S;
		
		// scores[i][0] score de la bailarina i
		// scores[i][1] max puntuacion que pudo haber obtenido sin sorpresa
		// scores[i][2] max puntuacion que pudo haber obtenido con sorpresa
		int scores[N][3];
		
		int pasan = 0;
		
		int i=0;
		for(;i<N;i++){
			
			if (i<(N-1)) scanf("%d ",&scores[i][0]);
			if (i==(N-1)) scanf("%d\n",&scores[i][0]);
			
			scores[i][1] = maxSS(scores[i][0], P);
 			//printf("B(%d)=%d MAX SCORE (SS) (%d) = %d\n",i,scores[i][0],P,scores[i][1]);
			
			scores[i][2] = maxCS(scores[i][0], P);
			//printf("B(%d)=%d MAX SCORE (CS) (%d) = %d\n",i,scores[i][0],P,scores[i][2]);			
		}
				
		// primero paso a todos los que pueda que solo pasan son sorpresa
		for(i=0;i<N;i++){			
			// optiene el score solo con sorpresa
			if (scores[i][2] >= 0 && scores[i][1] < 0) {
				if (necesito) {		
					pasan++;
					necesito--;
				} 
			}
		}
		
		for(i=0;i<N;i++){
			// optiene el score con o sin sorpresa
			if (scores[i][2] >= 0 && scores[i][1] >= 0) {
				pasan++;
				if (necesito) {
					necesito--;
				}
			}
			
			// optiene el score solo sin sorpresa
			if (scores[i][2]  < 0 && scores[i][1] >= 0) {
				pasan++;
			}
		}
		
		//printf("\nTotal con sorpresa = %d\nNecesito %d\n", S-necesito, S);
		if (necesito){
			printf("Case #%d: %d\n",caso+1,pasan);
		} else {
			printf("Case #%d: %d\n",caso+1,pasan);			
		}
		//printf("-------------------------------------------\n\n");
	}
	return 0;
}
