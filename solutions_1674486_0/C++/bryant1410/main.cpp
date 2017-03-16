#include <iostream>
#include <string>
using namespace std;

// Caminos dice cuántos caminos hay desde el nodo inicial hasta el actual.
bool variosCaminos(int nodo, int N, bool **M, bool* &marcados, int* &caminos)
{
	caminos[nodo]++;
	if(caminos[nodo]>=2)
		return true;
	marcados[nodo] = true;
	for(int i=0;i<N;i++)
		if(M[nodo][i])
		{
			if(!marcados[i] && variosCaminos(i, N, M, marcados, caminos))
				return true;
		}
	marcados[nodo] = false;
	return false;
}

int main()
{
	int T;
	cin >> T;
	for(int caso=1;caso<=T;caso++)
	{
		// Consiste en ver si tiene ciclos.
		int N;
		bool **M; // Matriz de ady.
		cin >> N;
		M = new bool*[N];
		bool *marcados = new bool[N];
		for(int i=0;i<N;i++)
		{
			M[i] = new bool[N];
			for(int j=0;j<N;j++)
				M[i][j] = false;
			int cant;
			cin >> cant;
			for(int j=0;j<cant;j++)
			{
				int nodo;
				cin >> nodo;
				M[i][nodo-1] = true;
			}
			marcados[i] = false;
		}
		string res = "No";
		bool existe = false;
		int *caminos = new int[N];
		for(int i=0;i<N && !existe;i++)
		{
			for(int j=0;j<N;j++)
			{
				marcados[j] = false;
				caminos[j] = 0;
			}
			existe=variosCaminos(i, N, M, marcados, caminos);
		}
		if(existe)
			res = "Yes";
		cout << "Case #" << caso << ": " << res << endl;
		delete [] M;
	}
	return 0;
}
