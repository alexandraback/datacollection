#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

map<int,vector<int> > mapa;


int t,n,suma;
int liczby[300];


void wypiszWynik(int maska1, int maska2) {
	int akt = maska1;
	int poz = 0;
	printf("\n");
	while(akt>0) {
		if(akt&1 == 1) printf("%d ",liczby[poz]);
		poz++;
		akt>>=1;
	}
	printf("\n");
	akt = maska2;
	poz = 0;
	while(akt>0) {
		if(akt&1 == 1) printf("%d ",liczby[poz]);
		poz++;
		akt>>=1;
	}
	printf("\n");
}

int main() {
	scanf("%d",&t);
	for(int ind = 1;ind<=t;ind++) {
		scanf("%d",&n);
		for(int i=0;i<n;i++) {
			scanf("%d",&liczby[i]);
		}
		mapa.clear();
		int jest = 0;
		printf("Case #%d: ", ind);
		for(int i=0;i<(1<<n);i++) {
			int suma = 0;
			int akt = i;
			int poz = 0;
			while(akt>0) {
				if(akt&1 == 1) suma += liczby[poz];
				poz++;
				akt>>=1;
			}
			for(int k=0;k<mapa[suma].size();k++) {
				if((mapa[suma][k] & i) == 0) {
					jest = 1;
					wypiszWynik(mapa[suma][k],i);
					i = (1<<n);
					break;
				}				
			}
			mapa[suma].push_back(i);
		}
		
		if(jest == 0) {
			printf("Impossible\n");
		}

	}
	return 0;
}
