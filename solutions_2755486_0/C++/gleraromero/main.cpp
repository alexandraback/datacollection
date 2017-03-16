#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <list>

#define ulong unsigned long long int
#define MAX_LONG_WALL 1000000
#define WALL_CERO 676060

using namespace std;

struct Wall
{
	int desde;
	int hasta;
	int fuerza;
	
	Wall(int d, int h, int f)
	{
		desde = d;
		hasta = h;
		fuerza = f;
	}
};
int cont = 0;
struct Tribe
{
	int id;
	int dia;
	int fuerza;
	int desde;
	int hasta;
	int ataquesRestantes;
	int deltaDias;
	int deltaFuerza;
	int deltaDistancia;
	
	Tribe(int di, int ni, int wi, int ei, int si, int delta_di, int delta_pi, int delta_si)
	{
		id = cont++;
		dia = di;
		fuerza = si;
		desde = wi;
		hasta = ei;
		ataquesRestantes = ni;
		deltaDias = delta_di;
		deltaFuerza = delta_si;
		deltaDistancia = delta_pi;
	}
	
	bool operator<(const Tribe& t) const
	{
		return dia < t.dia || (dia == t.dia && id < t.id);
	}
};

bool ataqueEnWall(int desde, int hasta, int fuerza, Wall& w)
{
	return w.fuerza < fuerza && ((desde >= w.desde && desde < w.hasta) || (hasta > w.desde && hasta <= w.hasta) || (desde <= w.desde && hasta >= w.hasta));
}

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		cout << "Case #" << (t+1) << ": ";
		int N, di, ni, wi, ei, si, delta_di, delta_pi, delta_si;
		cin >> N;
		
		set<Tribe> tribus;
		for (int n = 0; n < N; ++n)
		{
			cin >> di >> ni >> wi >> ei >> si >> delta_di >> delta_pi >> delta_si;
			tribus.insert(Tribe(di,ni,wi,ei,si,delta_di,delta_pi,delta_si));
		}
		list<Wall> wall;
		wall.push_back(Wall(-10000000, 10000000, 0));
		int lastDay = 0;
		vector<int> forces;
		vector<int> lastLeft;
		vector<int> lastRight;
		
		int count = 0;
		while (!tribus.empty())
		{
			Tribe t = *tribus.begin();
			tribus.erase(t);
			
			if (t.dia > lastDay)
			{
				for (unsigned int j = 0; j < forces.size(); ++j)
				{
					for (list<Wall>::iterator it = wall.begin(); it != wall.end(); ++it)
					{
						if (ataqueEnWall(lastLeft[j], lastRight[j], forces[j], *it))
						{
							bool crearIzq = it->desde < lastLeft[j];
							bool crearDer = it->hasta > lastRight[j];
							
							//cout << "Creo [" << lastLeft[j] << "->" << lastRight[j] << ": " << forces[j] << "] " << crearIzq << " " << crearDer << "[" << it->desde << "->" << it->hasta << ": " << it->fuerza << "]" << endl;
							if (crearIzq)
								wall.insert(it, Wall(it->desde, lastLeft[j], it->fuerza));
							wall.insert(it, Wall(lastLeft[j], lastRight[j], forces[j]));
							if (crearDer)
								wall.insert(it, Wall(lastRight[j], it->hasta, it->fuerza));
							it = wall.erase(it);
							it--;
						}
					}
				}
				forces.clear();
				lastLeft.clear();
				lastRight.clear();
				lastDay = t.dia;				
			}
			
			forces.push_back(t.fuerza);
			lastLeft.push_back(t.desde);
			lastRight.push_back(t.hasta);
			
			for (list<Wall>::iterator it = wall.begin(); it != wall.end(); ++it)
			{
				if (ataqueEnWall(t.desde, t.hasta, t.fuerza, *it))
				{
					count++;
					break;
				}
			}
			
			if (t.ataquesRestantes > 1)
			{
				t.ataquesRestantes--;
				t.desde += t.deltaDistancia;
				t.hasta += t.deltaDistancia;
				t.dia += t.deltaDias;
				t.fuerza += t.deltaFuerza;
				tribus.insert(t);
			}
		}
		
		cout << count << endl;
	}
	return 0;
}
