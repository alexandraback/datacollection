#include <stdio.h>

int b, m, g[10][10];
int count, flag[10];

void generate_graph (int code){
	for (int i=1; i<=b; i++)
		for (int j=1; j<=b; j++)
			g[i][j] = 0;

	for (int x=1; x<b; x++){
		for (int y=1; y<=b; y++){
			if (x != y){
				if (code%2 == 1) g[x][y] = 1;
				code /= 2;
			}
		}
	}
}

void count_possib (int v){
	flag[v] = 1;
	
	if (v == b)
		count++;
	else{
		for (int i=1; i<=b; i++){
			if (g[v][i] && flag[i]==0)
				count_possib(i);
		}
	}
	
	flag[v] = 0;
}

int main(){
	int t;
	bool ans;
	
	scanf ("%d", &t);
	
	for (int k=1; k<=t; k++){
		scanf ("%d %d", &b, &m);
		
		ans = false;
		for (int s=0; s<=( 1<<( (b-1)*(b-1) ) ) && !ans; s++){
			generate_graph(s);
			for (int i=1; i<=b; i++)
				flag[i] = 0;
				
			count = 0;
			count_possib(1);
			
			if (count == m) ans = true;
		}
		
		printf ("Case #%d: ", k);
		if (ans) printf ("POSSIBLE\n");
		else printf ("IMPOSSIBLE\n");
		
		if (ans){
			for (int i=1; i<=b; i++){
				for (int j=1; j<=b; j++)
					printf ("%d", g[i][j]);
				printf ("\n");
			}
		}
	}
}