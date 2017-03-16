#include <algorithm>
#include <stdio.h>
using namespace std;

int motes[10000];
int n;

int MIN(int a,int b){
	if ( a < b ) return a; return b;
}

int s(int pos,int a,int cont){
	if ( pos == n ) return cont;
	if ( cont ==  n ) return cont;

	if ( motes[pos] < a ){
		return s(pos+1,a+motes[pos],cont);
	} else {
		return MIN( s(pos,a+a-1,cont+1), (n-pos) + cont );
	}
}

int main()
{		
	int t;
	scanf("%d",&t);
	int caso = 1;
	while(t--){
		int a;		
		scanf("%d %d",&a,&n);
		for(int i=0;i<n;i++){
			scanf("%d",&motes[i]);
		}
		sort(motes,motes+n);
		/*
		int ops = 0;
		int min;
		for(int i=0;i<n;i++){
			if ( motes[i] < a ){
				a += motes[i];
			} else {
				if ( motes[i] < (a+a-1) ){
					a += (a-1);
					i--;
					ops++;
				}
			}
		}
		*/
		printf("Case #%d: %d\n",caso++,s(0,a,0));

	}
	return 0;
}

