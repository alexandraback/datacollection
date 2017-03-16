#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

long long int absolu(long long int x)
{
	if(x >= 0) return x;
	else return -x;
}
int main()
{
	int i, j, T, t;
	long long int N, X, Y;
	long long int couche;
	long long int avantcouche, aprescouche, reste, onveut;
	double combi[2000][2000];
	double proba;
	
	combi[0][1] = 0.5;
	combi[1][1] = 0.5;
	
	for(i = 2; i < 2000; i++)
	{
		combi[0][i] = combi[0][i-1]/2.0;
		combi[i][i] = combi[0][i];
		for(j = 1; j < i; j++)
		{
			combi[j][i] = (combi[j-1][i-1] + combi[j][i-1])/2.0;
		}
	}
	
	scanf("%d\n", &T);
	
	for(t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		scanf("%lld %lld %lld", &N, &X, &Y);
		couche = (absolu(X)+absolu(Y))/2;
		// 1 + 5 + 9 + ... + 4*(couche-1) + 1
		// couche + 2 * (couche-1)*couche
		avantcouche = couche + 2*(couche-1)*couche;
		aprescouche = couche+1 + 2*couche*(couche+1);
		if(avantcouche >= N || Y < 0) printf("0.0\n");
		else if(aprescouche <= N) printf("1.0\n");
		else
		{
			reste = N-avantcouche;
			// On a encore "reste" blocs qui vont tomber
			if(X == 0) printf("0.0\n");
			else
			{
				// 2*couche à gauche, 2*couche à droite
				// reste va être réparti en (x, y) selon une binomiale
				// On en veut Y/2 + 1 d'un coté
				onveut = Y + 1;
				// Tous les (x,y) avec y >= Y + 1 sont OK
				// Et dans le cas où reste >= 2*couche+onveut, toujours bon
				if(reste >= 2*couche+onveut) printf("1.0\n");
				else
				{
					if(reste >= 2000) printf("ERREUR : Combi %lld!\n", reste);
					// On joue à pile ou face "reste" fois, et on veut la probabilité d'avoir plus de "onveut" succès
					proba = 0;
					for(i = onveut; i <= reste; i++)
					{
						proba += combi[i][reste];
					}
					printf("%.10lf\n", proba, onveut, reste);
				}
			}
		}

	}

	return 0;
}
