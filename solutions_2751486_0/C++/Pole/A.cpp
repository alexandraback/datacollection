#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=1000*1000;

char chaine[MAXN];
int indice[MAXN];

long long resoud(){
	int N;
	scanf("%s%d",chaine,&N);
	int iPrec=-1;
	int curLong=0;
	long long r=0;
	for (int i=0;chaine[i];i++){
		if (chaine[i]!='a' && chaine[i]!='e' && chaine[i]!='i' && chaine[i]!='o' && chaine[i]!='u'){
			curLong++;
			if (curLong==N){
				curLong--;
				iPrec=i;
			}
		}
		else
			curLong=0;
		if (iPrec!=-1){
			r+=iPrec-N+2;
		}
	}
	return r;
}

int main(){
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++)
		printf("Case #%d: %lld\n",i+1,resoud());
	return 0;
}
