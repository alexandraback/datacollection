#include <cstdio>

int T,cc;
char table[10][10];
int linex(int ind){
	char a[5];
	a[1] = 'X';
	a[2] = 'O';
	a[3] = 'T';
	
	int count[5];
	count[1] = count[2] = count[3] = 0;
	for(int i=1;i<=4;i++)  for(int j=1;j<=3;j++) if(table[ind][i] == a[j]) count[j]++;
	
	if(count[1] + count[3] == 4) return 1;
	if(count[2] + count[3] == 4) return 2;
	return 0;
}

int liney(int ind){
	char a[5];
	a[1] = 'X';
	a[2] = 'O';
	a[3] = 'T';
	
	int count[5];
	count[1] = count[2] = count[3] = 0;
	for(int i=1;i<=4;i++)  for(int j=1;j<=3;j++) if(table[i][ind] == a[j]) count[j]++;
	
	if(count[1] + count[3] == 4) return 1;
	if(count[2] + count[3] == 4) return 2;
	return 0;
}

int line1(){
	char a[5];
	a[1] = 'X';
	a[2] = 'O';
	a[3] = 'T';
	
	int count[5];
	count[1] = count[2] = count[3] = 0;
	for(int i=1;i<=4;i++)  for(int j=1;j<=3;j++) if(table[i][i] == a[j]) count[j]++;
	
	if(count[1] + count[3] == 4) return 1;
	if(count[2] + count[3] == 4) return 2;
	return 0;
}

int line2(){
	char a[5];
	a[1] = 'X';
	a[2] = 'O';
	a[3] = 'T';
	
	int count[5];
	count[1] = count[2] = count[3] = 0;
	for(int i=1;i<=4;i++)  for(int j=1;j<=3;j++) if(table[i][5-i] == a[j]) count[j]++;
	
	if(count[1] + count[3] == 4) return 1;
	if(count[2] + count[3] == 4) return 2;
	return 0;
}
int count(){
	int x = 0;
	for(int i=1;i<=4;i++) for(int j=1;j<=4;j++) if(table[i][j] == 'X' || table[i][j] == 'O' || table[i][j] == 'T') x++;
	return x;
}

void printwin(int ind){
	if(ind == 1) printf("X won\n");
	if(ind == 2) printf("O won\n");
	if(ind == 0){
		if(cc == 16) printf("Draw\n");
		else printf("Game has not completed\n");
	}	
}

int win;
int main(){
	freopen("output-A-large.txt","w",stdout);
	
	scanf("%d",&T);
	for(int _i=1;_i<=T;_i++){
		for(int i=1;i<=4;i++) scanf("%s",&table[i][1]);
		cc = count();
		win = 0;
		printf("Case #%d: ",_i);
		win = line1();
		if(win){
			printwin(win);
			continue;
		}
		win = line2();
		if(win){
			printwin(win);
			continue;
		}
				
		for(int i=1;i<=4;i++){
			if(linex(i) != 0){
				win = linex(i);
				break;
			}
			if(liney(i) != 0){
				win = liney(i);
				break;
			}
		}
		printwin(win);
	}
	return 0;
}