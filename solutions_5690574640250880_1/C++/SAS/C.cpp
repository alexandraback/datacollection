#include<stdio.h>
#include<stdlib.h>

char map[60][60];
int R,C,M;

int E;
void printMap(){
	map[0][0] = 'c';
	int count = 0;
	for(int i=0;i<R;i++){
		printf("%s\n", map[i]);
		for(int j=0;j<C;j++){
			if(map[i][j] == '.' || map[i][j] == 'c')
				count++;
		}
	}
	if(count != E)fprintf(stderr, "Not equal\n");
}

void init(char c){
	for(int i=0;i<60;i++)for(int j=0;j<60;j++)map[i][j] = c;
}
void initMap(char c){
	for(int i=0;i<R;i++)for(int j=0;j<C;j++)map[i][j] = c;
}

int findSize(int empty, int &rr, int &cc){
	for(int r=2;r<=R;r++){
		for(int c=2;c<=C;c++){
			int remain_empty = empty - 2 * (r + c - 2);
			if(remain_empty < 0)continue;
			if(remain_empty <= (r - 2) * (c - 2)){
				rr = r;
				cc = c;
				return remain_empty;
			}
		}
	}
	return -1;
}
int main(){
	int T;
	scanf("%d",&T);
	for(int ca = 1; ca <= T; ca++){
		scanf("%d %d %d",&R, &C, &M);
		init(0);
		
		int empty = R * C - M;
		E = empty;

		printf("Case #%d:\n",ca);

		if(M == 0){
			initMap('.');
			printMap();
			continue;
		}
		if(empty == 1){
			initMap('*');
			printMap();
			continue;
		}


		if((R == 1 || C == 1) ){
			initMap('*');
			if(R == 1){
				for(int i=0;i<empty;i++)map[0][i] = '.';
			}else if(C == 1){
				for(int i=0;i<empty;i++)map[i][0] = '.';
			}
			printMap();
			continue;
		}
		if(((R == 2 || C == 2) && M % 2 == 1) ||
		    empty == 2 || empty == 3 || empty == 5 || empty == 7){
			printf("Impossible\n");
			continue;
		}

		int rr = 0;
		int cc = 0;
		int remain_empty = findSize(empty,rr,cc);
		if(remain_empty == -1)fprintf(stderr,"remain_empty == -1(%d %d %d)\n", R,C,M);
		initMap('*');
		for(int i=0;i<2;i++){
			for(int j=0;j<rr;j++)map[j][i] = '.';
			for(int j=0;j<cc;j++)map[i][j] = '.';
		}
		for(int i=0;i<remain_empty;i++){
			int r = i % (cc - 2);
			int c = i / (cc - 2);
			map[ 2 + c][2 + r] = '.';
		}
		printMap();
		
	}
	return 0;
}
