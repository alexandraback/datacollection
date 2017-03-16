//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long double LD;
const int N = 1000006;

int t;
int n,x,y;
int tab[2*N]; // siz[i] = tab[i]-tab[i-1] // wys[i] = siz[i]/2+1

inline int siz(int x) { return tab[x]-tab[x-1]; }
inline int wys(int x) { return siz(x)/2+1; }

int main()
{
	tab[1] = 1;
	for(int i = 1, rozmiar = 1;tab[i-1] <= N;i++,rozmiar += 4)
	{
		tab[i] = tab[i-1]+rozmiar;
		//cerr << "I: " << i << " Rozmiar: " << rozmiar << " tab[i]: "<< tab[i] << " wys(i): " << wys(i) << endl;
	}

	scanf("%d", &t);
	for(int ti = 1;ti <= t;ti++)
	{
		scanf("%d%d%d", &n, &x, &y);
		int Xnumer = (abs(x)+y)/2+1;
		int Nnumer = 1;
		while(tab[Nnumer] < n) Nnumer++;

		//cerr << "Xnumer: " << Xnumer  << " Nnumer: " << Nnumer << endl;

		LD wyn = 0.0;

		if(tab[Xnumer] <= n) wyn = 1.0;
		else if(Nnumer == Xnumer)
		{
			int rozmiar = siz(Nnumer);
			int wysokosc = wys(Nnumer);
			int wrzucam = n-tab[Xnumer-1];
			int wprawo = y+1;

			//cerr << "Wrzucam: " << wrzucam << " wprawo: " << wprawo << " Rozmiar: "<< rozmiar << " Wysokosc: " << wysokosc<<  endl;

			if(wrzucam == siz(Nnumer)) wyn = 1.0;
			else if(wprawo > wrzucam) wyn = 0.0;
			else
			{
				if(wrzucam <= 20)
				{
					int dobre = 0, mozliwe = 0;
					for(int i = 0;i < (1<<wrzucam);i++)
					{
						int jed = __builtin_popcount(i);

						if(wrzucam-wys(Nnumer) < jed && jed < wys(Nnumer))
						{
							mozliwe++;
							if(jed >= wprawo)
								dobre++;
						}
					}
					//cerr << "Dobre: " << dobre << " Mozliwe: " << mozliwe << endl;
					wyn = (LD)dobre/mozliwe;
				}
			}

			// wyn = prawdopodobieństwo, że we wrzucam będzie przynajmniej wprawo jedynek.

		}

		printf("Case #%d: %Lf\n", ti, wyn);


	}
	return 0;
}
