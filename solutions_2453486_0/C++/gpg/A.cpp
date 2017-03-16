#include <stdio.h>

int main(){
	int n;
	char buffer[16][16];
	int Xc,Oc,Tc;
	scanf("%d",&n);
	for(int i= 0;i<n;i++){
		int j;
		for(j = 0;j<4;j++){
			scanf(" %s ",buffer[j]);
		}
		for(j = 0;j<4;j++){
			Xc = Oc = Tc = 0;		
			for(int k = 0;k<4;k++){
				switch(buffer[j][k]){
					case '.':
						break;
					case 'X':
						Xc++;
						break;
					case 'O':
						Oc++;
						break;
					case 'T':
						Tc++;
						break;
					default:
						fprintf(stderr,"ERROR %c\n",buffer[j][k]);
						break;
				}
			}

			if(Xc+Tc == 4 || Oc+Tc == 4)
				break;
			Xc = Oc = Tc = 0;		
			for(int k = 0;k<4;k++){
				switch(buffer[k][j]){
					case '.':
						break;
					case 'X':
						Xc++;
						break;
					case 'O':
						Oc++;
						break;
					case 'T':
						Tc++;
						break;
					default:
						fprintf(stderr,"ERROR %c\n",buffer[k][j]);
						break;
				}
			}
			if(Xc+Tc == 4 || Oc+Tc == 4)
				break;
			Xc = Oc = Tc = 0;		
			for(int k = 0;k<4;k++){
				switch(buffer[k][k]){
					case '.':
						break;
					case 'X':
						Xc++;
						break;
					case 'O':
						Oc++;
						break;
					case 'T':
						Tc++;
						break;
					default:
						fprintf(stderr,"ERROR %c\n",buffer[k][k]);
						break;
				}
			}
			if(Xc+Tc == 4 || Oc+Tc == 4)
				break;
			Xc = Oc = Tc = 0;		
			for(int k = 0;k<4;k++){
				switch(buffer[k][3-k]){
					case '.':
						break;
					case 'X':
						Xc++;
						break;
					case 'O':
						Oc++;
						break;
					case 'T':
						Tc++;
						break;
					default:
						fprintf(stderr,"ERROR %c\n",buffer[k][k]);
						break;
				}
			}
			if(Xc+Tc == 4 || Oc+Tc == 4)
				break;

		}
		printf("Case #%d: ",i+1);
		if(j == 4){
			int pc = 0;
			for(j =0;j<4;j++)
				for(int k = 0;k<4;k++)
					if(buffer[j][k] == '.')
						pc++;
			if(pc == 0)
				printf("Draw");
			else 
				printf("Game has not completed");
		}
		else if(Xc+Tc == 4)
			printf("X won");
		else if(Oc+Tc == 4)
			printf("O won");
		
		printf("\n");
	}


	return 0;
}
