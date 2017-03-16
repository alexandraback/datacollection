#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
char d[8][8];
vector<string> a;
int help()
{
	int i, j;
	
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (!(d[i][j] == 'X' || d[i][j] == 'T')) break;
		}
		if (j >= 4) return 0;
	}
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (!(d[j][i] == 'X' || d[j][i] == 'T')) break;
		}
		if (j >= 4) return 0;
	}
	for (i = 0; i < 4; i++) {
		if (!(d[i][i] == 'X' || d[i][i] == 'T')) break;
	}
	if (i >= 4) return 0;
	for (i = 0; i < 4; i++) {
		if (!(d[i][3-i] == 'X' || d[i][3-i] == 'T')) break;
	}
	if (i >= 4) return 0;
	
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (!(d[i][j] == 'O' || d[i][j] == 'T')) break;
		}
		if (j >= 4) return 1;
	}
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (!(d[j][i] == 'O' || d[j][i] == 'T')) break;
		}
		if (j >= 4) return 1;
	}
	for (i = 0; i < 4; i++) {
		if (!(d[i][i] == 'O' || d[i][i] == 'T')) break;
	}
	if (i >= 4) return 1;
	for (i = 0; i < 4; i++) {
		if (!(d[i][3-i] == 'O' || d[i][3-i] == 'T')) break;
	}
	if (i >= 4) return 1;
	
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (d[i][j] == '.') return 3;
		}
	}
	return 2;
}
int main()
{
	FILE *in=fopen("input.txt","r");
	FILE *out=fopen("output.txt","w");
	int t, T, i;
	
	a.clear();
	a.push_back("X won");
	a.push_back("O won");
	a.push_back("Draw");
	a.push_back("Game has not completed");
	fscanf(in,"%d",&T);
	for (t = 1; t <= T; t++) {
		printf("Case #%d: ",t);
		fprintf(out,"Case #%d: ",t);
		for (i = 0; i < 4; i++)
			fscanf(in,"%s",d[i]);
		fprintf(out,"%s\n",a[help()].c_str());
	}
	fclose(in);
	fclose(out);
	return 0;
}