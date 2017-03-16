#include <stdio.h>

int main(){
	int n, test=1, r, c, m, min, i, j, noBombsCount, noBombs, a, b;
	char table[51][51];
	scanf("%d", &n);
	while(n--){
		scanf("%d %d %d", &r, &c, &m);
		printf("Case #%d:\n", test++);
		noBombsCount=1;
		if (r<c) min=r;
		else min = c;
		noBombs = r*c - m;

		if(min==1){
			for(i=0; i<r; i++){
				for(j=0; j<c; j++){
					if (i==0 && j==0) {
						printf("c");
						noBombsCount++;
					}
					else if (noBombsCount <= noBombs) {
						printf(".");
						noBombsCount++;
					}
					else printf("*");
				}
				printf("\n");
			}
		}
		else if(min==2){
			if((noBombs==2)||
				( noBombs%2==1 && noBombs!=1 )//odds not 1
				){
				printf("Impossible\n");
				continue;
			}
			else{
				for(i=0; i<r; i++){
					for(j=0; j<c; j++){
						if (i==0 && j==0) {
							printf("c");
							noBombsCount++;
						}
						else if (noBombsCount <= noBombs &&
								i< noBombs/2 && j<noBombs/2){
							 printf(".");
							noBombsCount++;
						}		
						else printf("*");
					}
					printf("\n");
				}
			}
		}
		else if(r>=3&&c>=3){
			noBombsCount=0;
			// printf("r %d c%d noBombs %d\n", r, c, noBombs);
			
			if((noBombs==2)||
				( noBombs%2==1 && noBombs!=1 && noBombs < 9)//odds not 1, less than 9.
				){
				printf("Impossible\n");
			}
			else{
				for(i=0; i<r; i++){
					for(j=0; j<c; j++){
						table[i][j]='*';
					}
				}
				while (noBombsCount!=noBombs){
					table[0][0]='c';
					noBombsCount++; 
					if(noBombsCount==noBombs) break; //noBombs=1
					table[0][1]=table[1][0]=table[1][1]='.';
					noBombsCount+=3;
					if(noBombsCount==noBombs) break; //noBombs=4
					table[0][2]=table[1][2]='.';
					noBombsCount+=2;
					if(noBombsCount==noBombs) break; //noBombs=6
					table[2][0]=table[2][1]='.';
					noBombsCount+=2;
					if(noBombsCount==noBombs) break; //noBombs=8
					table[2][2]='.';
					noBombsCount+=1;
					break; //noBombs=9, go out of loop, no matter what.
				}
				i=2,j=2;
	//			printf("noBombsCount %d noBombs %d\n", noBombsCount, noBombs);
				while(noBombsCount!=noBombs){
					// printf("i %d j %d table[i][j] %c table[i-2][j] %c table[i-1][j] %c table[i-2][j+1] %c table[i-1][j+1] %c\n", 
					// 	i, j, table[i][j], table[i-2][j],table[i-1][j],table[i-2][j+1],table[i-1][j+1] );

					if(i==2 && j+1<c && table[i][j]=='.' &&
										table[i-2][j]=='.'&& 
					                    table[i-1][j]=='.'&&
					                    table[i-2][j+1]=='*'&& 
					                    table[i-1][j+1]=='*'){//in rows 0, 1 we need to change both.
						table[i][j]='*';
						table[i-2][j+1]='.';
						table[i-1][j+1]='.';
						noBombsCount+=1;
						// printf("cond 1 noBombsCount %d noBombs %d\n", noBombsCount, noBombs);
						continue;
					}
					else if(i==2 && j+1<c && table[i][j]=='*'&&
										     table[i-1][j+1]=='.'&& 
					                         table[i-2][j+1]=='.')
						{
						table[i][j]='.';
						j++;
						noBombsCount+=1;
						// printf("cond 2 noBombsCount %d noBombs %d\n", noBombsCount, noBombs);
						continue;
					}else if(i==2 && j>1 && table[i][j]=='*'&&
								     		table[i][j-1]=='.'&&
								     		table[i-1][j]=='.'&& 
					                 		table[i-2][j]=='.')
					{
						table[i][j]='.';
						noBombsCount+=1;
						// printf("cond 3 noBombsCount %d noBombs %d\n", noBombsCount, noBombs);
						continue;
					}
					else if(j+1==c && i+1<r && table[i][j]=='.'&&
									  table[i-1][j]=='.'){ //end of line. Jump to the next.
						j=0;
						i++;
						table[i][0]='.';
						table[i][1]='.';
						table[i-1][c-1]='*';
						noBombsCount+=1;
						// printf("cond 4 noBombsCount %d noBombs %d\n", noBombsCount, noBombs);
						continue;
					}
					else if(j==0 && table[i][0]=='.'&&
									table[i][1]=='.'&&
									table[i-1][c-1]=='*'){ //begin of the line
						table[i-1][c-1]='.';
						j++;
						noBombsCount+=1;
						// printf("cond 5 noBombsCount %d noBombs %d\n", noBombsCount, noBombs);
						continue;
					}
					else if(i>2 && j+1<c && table[i][j]=='.'&&
											table[i-1][j+1]=='.'&&
											table[i][j+1]=='*'){ //generic increment, not in row=2.
						table[i][j+1]='.';
						j++;
						noBombsCount+=1;
						// printf("cond 6 noBombsCount %d noBombs %d\n", noBombsCount, noBombs);
						continue;
					}
					if(i==r&&j==c) break;
				}
				for(i=0; i<r; i++){
					for(j=0; j<c; j++){
						printf("%c",table[i][j]);
					}
					printf("\n");
				}
			}
			
		}
	}
	return 1;
}