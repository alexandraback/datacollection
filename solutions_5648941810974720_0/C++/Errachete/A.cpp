// errachete - A: Getting the digits

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
using namespace std;

ifstream fin;
ofstream fout;


ostream & operator<<(ostream & salida, vector< int > const& v)
{
	for (int i = 0; i < v.size(); ++i)
		salida << v[i];
	return fout;
}

void buscaryeliminar(string & numero, char chara)
{
	for (int i = 0; i < numero.length(); ++i)
	{
		if (numero[i] == chara)
		{
			numero.erase(numero.begin() + i);
			return;
		}
	}
}
void buscarZERO(string & numero, vector< int > & v)
{
	for (int i = 0; i < numero.length(); ++i)
	{
		if (numero[i] == 'Z')
		{
			numero.erase(numero.begin() + i);
			buscaryeliminar(numero, 'E');
			buscaryeliminar(numero, 'R');
			buscaryeliminar(numero, 'O');
			v.push_back(0);
			buscarZERO(numero, v);
		}
	}
}
void buscarSIX(string & numero, vector< int > & v)
{
	for (int i = 0; i < numero.length(); ++i)
	{
		if (numero[i] == 'X')
		{
			numero.erase(numero.begin() + i);
			buscaryeliminar(numero, 'I');
			buscaryeliminar(numero, 'S');
			v.push_back(6);
			buscarSIX(numero, v);
		}
	}
}
void buscarTWO(string & numero, vector< int > & v)
{
	for (int i = 0; i < numero.length(); ++i)
	{
		if (numero[i] == 'W')
		{
			numero.erase(numero.begin() + i);
			buscaryeliminar(numero, 'T');
			buscaryeliminar(numero, 'O');
			v.push_back(2);
			buscarTWO(numero, v);
		}
	}
}
void buscarEIGHT(string & numero, vector< int > & v)
{
	for (int i = 0; i < numero.length(); ++i)
	{
		if (numero[i] == 'G')
		{
			numero.erase(numero.begin() + i);
			buscaryeliminar(numero, 'E');
			buscaryeliminar(numero, 'I');
			buscaryeliminar(numero, 'H');
			buscaryeliminar(numero, 'T');
			v.push_back(8);
			buscarEIGHT(numero, v);
		}
	}
}
void buscarTHREE(string & numero, vector< int > & v)
{
	for (int i = 0; i < numero.length(); ++i)
	{
		if (numero[i] == 'T')
		{
			numero.erase(numero.begin() + i);
			buscaryeliminar(numero, 'R');
			buscaryeliminar(numero, 'H');
			buscaryeliminar(numero, 'E');
			buscaryeliminar(numero, 'E');
			v.push_back(3);
			buscarTHREE(numero, v);
		}
	}
}
void buscarFOUR(string & numero, vector< int > & v)
{
	for (int i = 0; i < numero.length(); ++i)
	{
		if (numero[i] == 'R')
		{
			numero.erase(numero.begin() + i);
			buscaryeliminar(numero, 'F');
			buscaryeliminar(numero, 'O');
			buscaryeliminar(numero, 'U');
			v.push_back(4);
			buscarFOUR(numero, v);
		}
	}
}
void buscarFIVE(string & numero, vector< int > & v)
{
	for (int i = 0; i < numero.length(); ++i)
	{
		if (numero[i] == 'F')
		{
			numero.erase(numero.begin() + i);
			buscaryeliminar(numero, 'I');
			buscaryeliminar(numero, 'V');
			buscaryeliminar(numero, 'E');
			v.push_back(5);
			buscarFIVE(numero, v);
		}
	}
}
void buscarSEVEN(string & numero, vector< int > & v)
{
	for (int i = 0; i < numero.length(); ++i)
	{
		if (numero[i] == 'V')
		{
			numero.erase(numero.begin() + i);
			buscaryeliminar(numero, 'S');
			buscaryeliminar(numero, 'E');
			buscaryeliminar(numero, 'E');
			buscaryeliminar(numero, 'N');
			v.push_back(7);
			buscarSEVEN(numero, v);
		}
	}
}
void buscarONE(string & numero, vector< int > & v)
{
	for (int i = 0; i < numero.length(); ++i)
	{
		if (numero[i] == 'O')
		{
			numero.erase(numero.begin() + i);
			buscaryeliminar(numero, 'N');
			buscaryeliminar(numero, 'E');
			v.push_back(1);
			buscarONE(numero, v);
		}
	}
}
void buscarNINE(string & numero, vector< int > & v)
{
	for (int i = 0; i < numero.length(); ++i)
	{
		if (numero[i] == 'N')
		{
			numero.erase(numero.begin() + i);
			buscaryeliminar(numero, 'I');
			buscaryeliminar(numero, 'N');
			buscaryeliminar(numero, 'E');
			v.push_back(9);
			buscarNINE(numero, v);
		}
	}
}
void resolucion(int caso)
{
	string numero = "";
	vector< int > v;

	fin >> numero;
	buscarZERO(numero, v);
	buscarSIX(numero, v);
	buscarTWO(numero, v);
	buscarEIGHT(numero, v);
	buscarTHREE(numero, v);
	buscarFOUR(numero, v);
	buscarFIVE(numero, v);
	buscarSEVEN(numero, v);
	buscarONE(numero, v);
	buscarNINE(numero, v);
	
	sort(v.begin(), v.end());
	fout << "Case #" << caso << ": " << v << '\n';
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