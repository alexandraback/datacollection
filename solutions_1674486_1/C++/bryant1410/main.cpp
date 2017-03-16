#include <iostream>
#include <list>
#include <string>
using namespace std;

// Caminos dice cuántos caminos hay desde el nodo inicial hasta el actual.
bool variosCaminos(int nodo, int N, list<int> *M, bool* &marcados, int* &caminos)
{
	caminos[nodo]++;
	if(caminos[nodo]>=2)
		return true;
	marcados[nodo] = true;
	for(list<int>::iterator it=M[nodo].begin();it!=M[nodo].end();it++)
		if(!marcados[*it] && variosCaminos(*it, N, M, marcados, caminos))
			return true;
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
		cin >> N;
		list<int> *M = new list<int>[N]; // Lista de ady.
		for(int i=0;i<N;i++)
		{
			int cant;
			cin >> cant;
			for(int j=0;j<cant;j++)
			{
				int nodo;
				cin >> nodo;
				M[i].push_back(nodo-1);
			}
		}
		string res = "No";
		bool existe = false;
		bool *marcados = new bool[N];
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
