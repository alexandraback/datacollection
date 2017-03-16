#include <stdio.h>
#include <algorithm>


struct para {
	int x, y;
	para(){}
	para(int xx, int yy) {
		x = xx;
		y = yy;
	}
};

void quicksort(para tab[],int lewy,int prawy)
{
   if(lewy<prawy) {
      int m=lewy;
      for(int i=lewy+1;i<=prawy;i++)
         if(tab[i].x<tab[lewy].x)
            std::swap(tab[++m],tab[i]);
         else if(tab[i].x==tab[lewy].x && tab[i].y<tab[lewy].y)
			std::swap(tab[++m],tab[i]);
      std::swap(tab[lewy],tab[m]);
      quicksort(tab,lewy,m-1);
      quicksort(tab,m+1,prawy);
   }
}

int main() {
	int t;
	scanf("%d", &t);
	for(int it=1; it<=t; it++) {
		int n;
		int out = 0;
		scanf("%d", &n);
		para tab[n];
		for(int i=0; i<n; i++)
			scanf("%d %d", &tab[i].x, &tab[i].y);
		// quicksort(tab, 0, n-1);
		
		int star = 0;
		while(true) {
			bool cont = false;
			// poszukiwanie 1 - szukam dwoch na raz
			for(int i=0; i<n; i++) {	
				if(tab[i].x>=0 && tab[i].y>=0 && star>=tab[i].y) {
					cont = true;
					tab[i].x = -1;
					tab[i].y = -1;
					star += 2;
					out += 1;
					break;
				}	
			}
			if(cont) continue;
			// szukam pojedynczego z minusem
			for(int i=0; i<n; i++)
				if(tab[i].x>=0 && tab[i].y<0 && star>=tab[i].x) {
					tab[i].x = -1;
					cont = true;
					star += 1;
					out += 1;
					break;
				}
			if(cont) continue;
			// szukam maksymalnej dostepnej roznicy
			int gdzie = -1;
			int ile = 0;
			for(int i=0; i<n; i++)
				if(tab[i].x>=0 && tab[i].y>=0 && star>=tab[i].x && tab[i].y-tab[i].x>ile) {
					ile = tab[i].y-tab[i].x;
					gdzie = i;
				}
			if(gdzie == -1)
				break;
			else {
				tab[gdzie].x = tab[gdzie].y;
				tab[gdzie].y = -1;
				out += 1;
				star += 1;
			}
		}
		// printf("%d ", star);
		if(star == 2*n)
			printf("Case #%d: %d\n", it, out);
		else
			printf("Case #%d: Too Bad\n", it);
	}
	
	return 0;
}
