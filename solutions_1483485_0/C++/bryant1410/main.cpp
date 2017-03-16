#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int T;
	cin >> T;
	string linea;
	getline(cin, linea); // Leo el resto de la línea.
	for(int i=1;i<=T;i++)
	{
		getline(cin, linea);
		map<char, char> funcion;
		map<char, bool> marcados; // Para marcar las imágenes.
		for(int i='a';i<='z';i++)
		{
			funcion[i]=0;
			marcados[i]=false;
		}
		funcion['a'] = 'y';
		funcion['b'] = 'h';
		funcion['c'] = 'e';
		funcion['d'] = 's';
		funcion['e'] = 'o';
		funcion['f'] = 'c';
		funcion['g'] = 'v';
		funcion['h'] = 'x';
		funcion['i'] = 'd';
		funcion['j'] = 'u';
		funcion['k'] = 'i';
		funcion['l'] = 'g';
		funcion['m'] = 'l';
		funcion['n'] = 'b';
		funcion['o'] = 'k';
		funcion['p'] = 'r';
		funcion['q'] = 'z';
		funcion['r'] = 't';
		funcion['s'] = 'n';
		funcion['t'] = 'w';
		funcion['u'] = 'j';
		funcion['v'] = 'p';
		funcion['w'] = 'f';
		funcion['x'] = 'm';
		funcion['y'] = 'a';
		funcion['z'] = 'q';
		funcion[' '] = ' ';
		int n=linea.length();
		//BT(linea, n, 0, funcion, marcados);
		cout << "Case #" << i << ": ";
		for(int i=0;i<n;i++)
			cout << funcion[linea[i]];
		cout << endl;
	}
	return 0;
}
