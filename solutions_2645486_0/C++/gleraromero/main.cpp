#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

int EnergiaUsar(vector<int>& V, int N, int E, int R, int e, int c, int maximo)
{
	if (c == maximo)
		return e;
	else
	{
		int EPosible = e + (maximo-c) * R;
		int energiaUsar = (EPosible - E);
		
		for (int i = c+1; i < maximo; ++i)
		{
			if (V[i] > V[c])
			{
				energiaUsar -= E;
			}
		}
		
		energiaUsar = max(energiaUsar,0);
		return min(energiaUsar,E);
	}
}

int GananciaHastaMaximo(vector<int>& V, int N, int E, int R, int e, int c, int maximo)
{
	if (c == N-1)
	{
		return e*V[c];
	}
		
	int resultado = 0;	
	int energiaUsada = EnergiaUsar(V,N,E,R,e,c,maximo);
	resultado += energiaUsada * V[c];
	
	if (c == maximo)
	{
		maximo = c+1;
		for (int i = maximo+1; i < N; ++i)
			if (V[maximo] < V[i])
				maximo = i;
	}
	
	resultado += GananciaHastaMaximo(V,N,E,R,e-energiaUsada+R,c+1,maximo);
	
	return resultado;
}

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		cout << "Case #" << (t+1) << ": ";
		
		int E, R, N;
		cin >> E >> R >> N;
		
		vector<int> V(N);
		for (int i = 0; i < N; ++i)
			cin >> V[i];
		
		int maximo = 0;
		for (int i = 1; i < N; ++i)
			if (V[i] > V[maximo])
				maximo = i;
				
		cout << GananciaHastaMaximo(V,N,E,R,E,0,maximo) << endl;
	}
	return 0;
}
