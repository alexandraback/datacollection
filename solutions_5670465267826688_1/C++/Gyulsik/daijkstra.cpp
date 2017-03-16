#include <stdio.h>
#include <stdlib.h>

FILE *ifp;
FILE *ofp;
int T;
int L;
long long int X;
char *str;

int quaternion[5][5] = {0, 0, 0, 0, 0,
						0, 1, 2, 3, 4,
						0, 2, -1, 4, -3,
						0, 3, -4, -1, 2,
						0, 4, 3, -2, -1};

int process(int, int, int);
void output(int, int);

int main(void){
	int i, j;

	ifp = fopen("C-large.in", "r");
	ofp = fopen("output.txt","w");

	fscanf(ifp, "%d", &T);
	
	for(i=0;i<T;i++){
		fscanf(ifp, "%d %d", &L, &X);
		str = (char *)malloc(sizeof(char)*(L+1));
		fscanf(ifp, "%s", str);
		if(X>8){
			X%=4;
			X+=4;
		}
		output(i+1, process(0, 0, 2));
		free(str);
	}

	fclose(ifp);
	fclose(ofp);
	return 0;
}

int process(int l, int x, int cnt){
	int tmp=1;

	while(1){
		tmp = (tmp>0)?quaternion[tmp][str[l]-'g']:-quaternion[-tmp][str[l]-'g'];
		l++;
		if(l==L){
			l=0;
			x++;
		}

		if(tmp==cnt){
			cnt++;
			tmp=1;
		}
		
		if(x==X)
			break;
	}

	if(tmp==1 && cnt==5 && l==0 && x==X)
		return 1;

	return 0;
}

void output(int t, int res){
	fprintf(ofp, "Case #%d: %s\n", t, res?"YES":"NO");
}