#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

#define PB push_back
typedef long double LD;

class Prostokat {
	public:
	char (*dane)[100];
	int wiersze,kolumny;
	int obrocony;
	
	Prostokat() {obrocony = 0;}
	
	Prostokat(char d[100][100], int r, int c) {
		dane = d;
		wiersze = r;
		kolumny = c;
		obrocony = 0;
	}
	
	void obroc() {
		obrocony = !obrocony;
	}
	
	int get_wiersze() {
		return obrocony ? kolumny : wiersze;
	}
	
	int get_kolumny() {
		return obrocony ? wiersze : kolumny;
	}	
	
	int get_wartosc(int r, int c) {
		return obrocony ? dane[c][r] : dane[r][c];
	}
	
	void set_wartosc(int r, int c, int val) {
		if(obrocony)
			dane[c][r] = val;
		else 
			dane[r][c] = val;
	}
} prostokat;


struct Kwadracik {
	char (*dane)[4];
	
	Kwadracik(char d[3][4]) {
		dane = d;
	}
	
	bool ok() {
		return dane[0][0] != 'Z';
	}
	
	void wprowadz(Prostokat &p) 
	{
		for(int i=0;i<3;i++) for(int i2=0;i2<3;i2++) {
			p.set_wartosc(i,i2,dane[i][i2]);
		}
	}
};
// 1,2,3,4,5,6,7,8,9
char kwak[][3][4] =  {{"c**","***","***"}, {"Z**","***","**c"},{"Z**","**.","**c"},{"c.*","..*","***"},{"Z**","***","**c"},{"c..","...","***"},{"Z**","...","c.."},{"c..","...","..*"},{"c..","...","..."}};

char dane[100][100];

void wypelniaj(int &sr, int &sc, int &w) {
	int cr = prostokat.get_wiersze();
	int cc = prostokat.get_kolumny();
	for(int i2=sc;i2<cc&&w;i2++) {
		if(w==1) {
			prostokat.set_wartosc(sr-1,i2-1,'*');
			prostokat.set_wartosc(0,i2,'.');
			prostokat.set_wartosc(1,i2,'.');
			w--;
		}
		else {
			for(int i3=0;i3<sr&&w;i3++) {
				prostokat.set_wartosc(i3,i2,'.');
				w--;
			}
		}
		sc=i2;
	}
	sc++;
}

int main() {
	int id=1;int t;scanf("%d",&t);
	while(t--) {
		int c,r,n;
		scanf("%d %d %d",&r,&c,&n);
		for(int i=0;i<r;i++) {for(int i2=0;i2<c;i2++) dane[i][i2] = '*'; dane[i][c] = 0; }
		
		int res = 0;
		prostokat = Prostokat(dane,r,c);
		if(c < r) 
			prostokat.obroc();
		
		int cr = prostokat.get_wiersze();
		int cc = prostokat.get_kolumny();
		int w = cr*cc - n;
		if(cr == 1) {
			res = 1;
			prostokat.set_wartosc(0,0,'c');
			w--;
			for(int i=1;i<cc&&w>0;i++) {
				prostokat.set_wartosc(0,i,'.');
				w--;
			}
		}
		else if(cr==2) {
			res = w == 1 || (w % 2 == 0 && w >= 4);
			prostokat.set_wartosc(0,0,'c');
			w--;
			if(w>0) {prostokat.set_wartosc(1,0,'.'); w--;}
			for(int i=1;i<cc&&w>0;i++) {
				prostokat.set_wartosc(0,i,'.');
				prostokat.set_wartosc(1,i,'.');
				w-=2;
			}
		}
		else {
			res = 1;
			if(w < 9) {
				// Schematy
				Kwadracik kwa(kwak[w-1]);
				res = kwa.ok();
				if(res) {
					kwa.wprowadz(prostokat);
				}
			}
			else {
				int sr = 3;
				int sc = 3;
				Kwadracik kwa(kwak[9-1]);
				kwa.wprowadz(prostokat);
				w-=9;

				wypelniaj(sr,sc,w);
				if(w) {
					// Obroc i to samo.
					prostokat.obroc();
					swap(sr,sc);
					wypelniaj(sr,sc,w);
				}
			}
		}
		
		printf("Case #%d:\n",id++);
		if(res == 0) printf("Impossible\n");
		else {
			for(int i=0;i<r;i++) {
				printf("%s\n",dane[i]);
			}
		}
	}
	return 0;
}
