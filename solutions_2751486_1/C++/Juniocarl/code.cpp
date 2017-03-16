#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;
/*
struct _C{
	int x;
	int y;
};

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

map<_C,int> visi;

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
		visi.clear();
		ini = 0;
		fin = 0;
		_c act = {0,0,'X',0,-1};
		mete(act);

		while(ini<fin){
			act = saca();
			_c nuevo;
			_C C;
			C.x = act.x;
			C.y = act.y;
			if ( visi[C] == 1 ) continue;			
			visi[C] = 1;
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

*/
int con(char c){
	if ( c == 'a' || c == 'e' || c=='i' || c=='o' || c=='u' ) return false;
	return true;
}

int main()
{
	int t,caso=1;
	int n;
	char str[1000009];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s %d",str,&n);
		long long int cont = 0;
		long long int ans = 0;
		int len = strlen(str);
		int ini,fin;
		bool f = false;
		for(int i=0;i<len;i++){
			if ( con(str[i]) ){
				if ( cont == 0 ) ini = i;
				fin = i;
				cont++;
			}else{
				if ( cont >= n ){
					long long int l = fin-ini+1;
					ans += (l*(l-n)) - ( n*(l-n)   +  (l-n)*(l-n-1)/2 );
					/*for(int ni=n;ni<l;ni++){
						ans+= l-ni;
					}*/
				}
				cont=0;
			}
			if ( cont >= n ){
				if ( f ) ans--;
				ans+= len+ini-fin;
				long long int op = (ini* (len-fin-1))-1;;
				if ( op > 0 )
					ans += op; 
				f = true;
			}
		}
		if ( cont >= n ){
			long long int l = fin-ini+1;
			ans += (l*(l-n)) - ( n*(l-n)   +  (l-n)*(l-n-1)/2 );
			/*for(int ni=n;ni<l;ni++){
				ans+= l-ni;
			}*/
		}
		printf("Case #%d: %lld\n",caso++,ans);
	}
	return 0;
}