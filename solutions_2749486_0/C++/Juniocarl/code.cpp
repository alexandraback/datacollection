#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstring>
using namespace std;

struct _c{
	int x;
	int y;
	char mov;
	int cont;
	int padre;
};

int ini = 0,fin=0;

_c cola[100000];

void mete(_c m){
	cola[fin++] = m;
}

_c  saca(){
	return cola[ini++];
}

int visi[10001][10001];

int C(int v){
	return v+5000;
}

int valid(int v){
	if ( C(v) >= 0 && C(v) <= 10000) return true;
	return false;
}

void init()
{
	for(int i=0;i<10001;i++){
		for(int j=0;j<10001;j++){
			visi[i][j] = 0;
		}
	}
}

void recon(int pos){
	if ( pos == 0 ) return;
	recon(cola[pos].padre);
	printf("%c",cola[pos].mov);
}

int main()
{
	int t,caso=1;
	scanf("%d",&t);
	while(t--)
	{
		int dx,dy;
		scanf("%d %d",&dx,&dy);
		init();
		ini = 0;
		fin = 0;
		_c act = {0,0,'X',0,-1};
		mete(act);

		while(ini<fin){
			act = saca();
			_c nuevo;
			if ( visi[C(act.x)][C(act.y)] == 1 ) continue;			
			if ( !valid(act.x) || !valid(act.y) ) continue;
			visi[C(act.x)][C(act.y)] = 1;
			nuevo.cont = act.cont+1;
			nuevo.padre = ini-1;
			if ( nuevo.cont > 500 ) continue;
						
			if ( dx == act.x && dy == act.y ){
				printf("Case #%d: ",caso++);
				recon(ini-1);
				printf("\n");
				break;
			}

			
			nuevo.x = act.x + nuevo.cont;
			nuevo.y = act.y;
			nuevo.mov = 'E';
			mete(nuevo);
			nuevo.x = act.x - nuevo.cont;
			nuevo.y = act.y;
			nuevo.mov = 'W';			
			mete(nuevo);
			
			nuevo.x = act.x;
			nuevo.y = act.y + nuevo.cont;
			nuevo.mov = 'N';
			mete(nuevo);

			nuevo.x = act.x;
			nuevo.y = act.y - nuevo.cont;
			nuevo.mov = 'S';
			
			mete(nuevo);
		}		

		
	}
	return 0;
}

/*
int con(char c){
	if ( c == 'a' || c == 'e' || c=='i' || c=='o' || c=='u' ) return false;
	return true;
}

int main()
{
	int t,caso=1;
	int n;
	char str[1009];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s %d",str,&n);
		int cont = 0;
		int ans = 0;
		int len = strlen(str);
		for(int i=0;i<len;i++){
			for(int j=i;j<len;j++)
			{
				cont = 0;
				for(int k=i;k<=j;k++){
					if ( con(str[k])){
						cont++;
					}else{
						cont = 0;
					}
					if ( cont >= n ){
						ans++;
						break;
					}
				}
			}
		}
		printf("Case #%d: %d\n",caso++,ans);
	}
	return 0;
}
*/