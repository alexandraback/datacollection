// errachete - 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <functional>
#include <sstream>
#include <utility>
#include <cctype>
#include <stack>
#include <queue>
#include <ctime>
using namespace std;

ifstream fin;
ofstream fout;

bool buscar(vector< string > const& v, string const& str, int num)
{
	for (int j = 0; j < v.size(); ++j)
	{
		if (j != num && v[j] == str)
			return true;
	}
	return false;
}

void cambiaOrden(vector< string > & v, vector< string > & w)
{
	string straux = "";
	for (int i = 0; i < v.size(); ++i)
	{
		int num = rand() % v.size();
		straux = v[i];
		v[i] = v[num];
		v[num] = straux;
		straux = w[i];
		w[i] = w[num];
		w[num] = straux;
	}
}

void resolucion(int caso)
{
	int numPal = 0, copias = 0, maxcopias = 0;
	fin >> numPal;

	vector< string > primero(numPal);
	vector< string > orig1;
	vector< string > segundo(numPal);
	vector< string > orig2;

	for (int i = 0; i < numPal; ++i)
	{
		fin >> primero[i];
		fin >> segundo[i];
	}

	orig1 = primero;
	orig2 = segundo;

	for (int k = 0; k < 1000; ++k)
	{
		
		for (int i = 0; i < primero.size(); ++i)
		{
			if (buscar(primero, primero[i], i) && buscar(segundo, segundo[i], i))
			{
				primero.erase(primero.begin() + i);
				segundo.erase(segundo.begin() + i);
				i = 0;
				++copias;
			}
		}
		if (maxcopias < copias)
		{
			maxcopias = copias;
			cout << "error\n";
		}
		copias = 0;
		primero = orig1;
		segundo = orig2;
		cambiaOrden(primero, segundo);
	}

	fout << "Case #" << caso << ": " << maxcopias << '\n';
}

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");
	int numCasos = 0;
	fin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resolucion(i + 1);
	fin.close();
	fout.close();
	return 0;
}