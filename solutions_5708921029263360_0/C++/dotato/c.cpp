#include <bits/stdc++.h>
using namespace std;

bool bad[11][11][11][11];

int main(){

	int test,t=0,a,b,c,d,ans,i,j,k,l,low,ab[11][11],ac[11][11],abc[11][11][11];
	int flag,infinit;
	
	FILE *f = fopen("fbad.in","r");
	FILE *f2 = fopen("fbad2.in","w");
	for(; ~fscanf(f,"%d%d%d%d",&a,&b,&c,&d) ;){
		bad[a][b][c][d]=1;
	}
	
	for( scanf("%d",&test) ; test-- ;){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		low = min(c,d);
		ans = a*b*low;
		printf("Case #%d: %d\n",++t,ans);
		
		flag = bad[a][b][c][d];
		
		memset(ab,0,sizeof(ab));
		memset(ac,0,sizeof(ac));
		memset(abc,0,sizeof(abc));
		l=1;
		for( i=1 ; i<=a ; i++ ){
			for( j=1 ; j<=b ; j++ ){
				for( k=1 ; k<=low ; k++ ){
					infinit=0;
					while( ab[i][l]>=d || ac[j][l]>=d || abc[i][j][l] ){
						if (flag ){
							l++;
							if( l>c ) l-=c;	
						}
						else{
							l++;
							if( l>c ) l=1;	
						}
						infinit++;
						if( infinit==100 ){
							fprintf(f2,"%d %d %d %d\n",a,b,c,d);
							goto next;
						}
					}
					printf("%d %d %d\n",i,j,l);
					ab[i][l]++;
					ac[j][l]++;
					abc[i][j][l]++;
					if (flag ){
						l+=(i)%c+1;
						if( l>c ) l-=c;	
					}
					else{	
						l++;
						if( l>c ) l=1;
					}
				}
			}
		}
		next:;
	}
	return 0;
}

