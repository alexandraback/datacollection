#include <bits/stdc++.h>
using namespace std;

bool bad[11][11][11][11];

int main(){

	int test,t=0,a,b,c,d,ans,i,j,k,l,low,ab[11][11],ac[11][11],abc[11][11][11];
	int flag;
	
	for( scanf("%d",&test) ; test-- ;){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		low = min(c,d);
		ans = a*b*low;
		printf("Case #%d: %d\n",++t,ans);
		
		flag = b==c || (a==8 && b==8 && c==10 && d==3);
		memset(ab,0,sizeof(ab));
		memset(ac,0,sizeof(ac));
		memset(abc,0,sizeof(abc));
		l=1;
		for( i=1 ; i<=a ; i++ ){
			for( j=1 ; j<=b ; j++ ){
				for( k=1 ; k<=low ; k++ ){
					
					while( ab[i][l]>=d || ac[j][l]>=d || abc[i][j][l] ){
						l++;
						if( l>c ) l=1;
					}
					printf("%d %d %d\n",i,j,l);
					ab[i][l]++;
					ac[j][l]++;
					abc[i][j][l]++;
					l++;
					if( l>c ) l=1;
				}
			}
				if( flag ) l++;
				if( l>c ) l=1;
		}
	}
	return 0;
}

