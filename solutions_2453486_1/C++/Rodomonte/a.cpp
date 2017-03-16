// Qualification Round
// Problem A

#import <stdio.h>

char a[4][5];
int main(){
	bool f,ic;
	int T,t, i,j;
	FILE *fi = fopen("../Google/al.in","r"),
		*fo = fopen("../Google/al.out","w");
	fscanf(fi,"%d\n",&T);
	for(t = 1; t <= T; t++){
		fprintf(fo,"Case #%d: ",t);
		f = ic = false;
		// Rows
		for(i = 0; i < 4; i++){
			fscanf(fi,"%s",a[i]);
			if(f) continue;
			if((a[i][0]=='X'||a[i][0]=='T')&&(a[i][1]=='X'||a[i][1]=='T')
					&&(a[i][2]=='X'||a[i][2]=='T')&&(a[i][3]=='X'||a[i][3]=='T')){
				fprintf(fo,"X won\n");
				f = true;
			}else if((a[i][0]=='O'||a[i][0]=='T')&&(a[i][1]=='O'||a[i][1]=='T')
					&&(a[i][2]=='O'||a[i][2]=='T')&&(a[i][3]=='O'||a[i][3]=='T')){
				fprintf(fo,"O won\n");
				f = true;
			}else if(a[i][0]=='.'||a[i][1]=='.'||a[i][2]=='.'||a[i][3]=='.')
				ic = true;
		}
		if(f) continue;
		// Columns
		for(i = 0; i < 4; i++){
			if(f) continue;
			if((a[0][i]=='X'||a[0][i]=='T')&&(a[1][i]=='X'||a[1][i]=='T')
					&&(a[2][i]=='X'||a[2][i]=='T')&&(a[3][i]=='X'||a[3][i]=='T')){
				fprintf(fo,"X won\n");
				f = true;
			}else if((a[0][i]=='O'||a[0][i]=='T')&&(a[1][i]=='O'||a[1][i]=='T')
					&&(a[2][i]=='O'||a[2][i]=='T')&&(a[3][i]=='O'||a[3][i]=='T')){
				fprintf(fo,"O won\n");
				f = true;
			}
		}
		if(f) continue;
		// Diags
		if((a[0][0]=='X'||a[0][0]=='T')&&(a[1][1]=='X'||a[1][1]=='T')
				&&(a[2][2]=='X'||a[2][2]=='T')&&(a[3][3]=='X'||a[3][3]=='T')){
			fprintf(fo,"X won\n");
			continue;
		}else if((a[0][0]=='O'||a[0][0]=='T')&&(a[1][1]=='O'||a[1][1]=='T')
				&&(a[2][2]=='O'||a[2][2]=='T')&&(a[3][3]=='O'||a[3][3]=='T')){
			fprintf(fo,"O won\n");
			continue;
		}
		if((a[0][3]=='X'||a[0][3]=='T')&&(a[1][2]=='X'||a[1][2]=='T')
				&&(a[2][1]=='X'||a[2][1]=='T')&&(a[3][0]=='X'||a[3][0]=='T')){
			fprintf(fo,"X won\n");
			continue;
		}else if((a[0][3]=='O'||a[0][3]=='T')&&(a[1][2]=='O'||a[1][2]=='T')
				&&(a[2][1]=='O'||a[2][1]=='T')&&(a[3][0]=='O'||a[3][0]=='T')){
			fprintf(fo,"O won\n");
			continue;
		}
		if(ic){
			fprintf(fo,"Game has not completed\n");
			continue;
		}
		fprintf(fo,"Draw\n");
	}
	fclose(fi); fclose(fo);
	return 0;
}
