#include<cstdio>
#include<algorithm>

using namespace std;

int t,n,il;
double suma, x,maxt;
double tab[207],tab2[207];
int pop[207];
double ile[207];

inline void czysc(){
	for(int i=0;i<207;i++)
		ile[i]=0;
}

inline bool cmp (int a, int b){
	return a>b;
}

bool b=0;

int main(){
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		suma=0;
		czysc();
		scanf("%d",&n);
		il=n;
		for(int j=0;j<n;j++){
			
			scanf("%lf",&tab[j]);
			tab2[j]=tab[j];
			suma+=tab[j];
		}
		sort(tab2,tab2+n);
		reverse(tab2,tab2+n);
		int it=0;
		maxt=tab2[it];
		pikachu:
		x=suma;
		for(int j=0;j<il;j++){
			if(tab[j]<=maxt){
			ile[j]=maxt-tab[j];
			x-=ile[j];
			if(x<0){/* printf("!\n");*/it++; maxt=tab2[it]; czysc(); n--; goto pikachu;}
		}
		}
		x/=n;
		double y;
		//printf(" |x = %lf| SUMA = %lf\n",x,suma);
		printf("Case #%d: ",i+1);
		for(int j=0;j<il;j++){
			if(tab[j]<=maxt){
			y=(x+ile[j])/suma;
			y*=100;
			printf("%.5lf ",y);
			}
			else
			printf("0.00000 ");
		}
		printf("\n");
	}
	return 0;
}
