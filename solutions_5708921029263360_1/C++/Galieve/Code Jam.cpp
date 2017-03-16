#define WORK_WITH_FILES //(quitar antes de enviar)
#ifndef INCLUDE_H
#define INCLUDE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <stack>
#include <queue> 
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <bitset>
using namespace std;

#endif
#ifndef THEFANTASTICHEADER_H
#define THEFANTASTICHEADER_H

using ullint = unsigned long long int;
typedef unsigned short int usint;

//vector<ullint> calcularPrimos();

template <typename T, typename Comp>
bool busquedaBinaria(const vector<T> &vektor, const T &buscado, int & pos, Comp ord);

template <typename T, typename Comp>
void colocarInsercion(vector<T> & lista, int i, Comp ord);

template <typename T, typename Comp>
void ordenarInsercion(vector<T> & lista, Comp ord);

vector<ullint> calcularPrimos(){
	bool primo = true;
	ullint num = 3, square = ullint(sqrt(ULLONG_MAX));
	vector<ullint> v(1, 2);
	while (num <= square){
		ullint i = 0;
		primo = true;
		while (i < v.size() && primo){
			if (num % v[i] == 0){
				primo = false;
			}
			++i;
		}
		if (primo){
			v.push_back(num);
		}
		++num;
	}
	return v;
}

//Poner Comp ord = Comp() implica que en la UVa no compile.
template <typename T, typename Comp = less<T>>
bool busquedaBinaria(const vector<T> &vektor, const T& buscado, int &pos, Comp ord) {
	int ini = 0, fin = vektor.size(), mitad;
	bool encontrado = false;
	// 0 <= ini <= fin <= N
	// array[0..ini) < buscado Y buscado < array[fin..N)
	while (ini < fin && !encontrado) {
		mitad = (ini + fin - 1) / 2; // división entera
		if (ord(buscado, vektor[mitad])) fin = mitad;
		else if (ord(vektor[mitad], buscado)) ini = mitad + 1;
		else encontrado = true;
	}
	if (encontrado) pos = mitad; // en la posición mitad
	else pos = ini; // No encontrado, le corresponde la posición ini (=fin)
	return encontrado;
}

//Poner Comp ord = Comp() implica que en la UVa no compile.
template <typename T, typename Comp = less<T>>
void colocarInsercion(vector<T> & lista, int i, Comp ord) {
	T elemento = lista[i];
	int j = i;
	while (j > 0 && ord(elemento, lista[j - 1])) {
		lista[j] = lista[j - 1];
		--j;
	}
	if (j != i) lista[j] = elemento;
}

//Poner Comp ord = Comp() implica que en la UVa no compile.
template <typename T, typename Comp = less<T>>
void ordenarInsercion(vector<T> & lista, Comp ord) {
	int N = lista.size();
	for (int i = 1; i < N; ++i) {
		colocarInsercion(lista, i, ord);
	}
}

//UVa Judge
/*
#ifndef ONLINE_JUDGE
ifstream in("casos.txt");
auto cinbuf = cin.rdbuf(in.rdbuf());
ofstream out("answer.txt");
auto coutbuf = cout.rdbuf(out.rdbuf());
#endif

#ifndef ONLINE_JUDGE
cin.rdbuf(cinbuf);
cout.rdbuf(coutbuf);
system("pause");
#endif
*/

//UCM
/*
#ifndef DOMJUDGE
ifstream in("casos.txt");
auto cinbuf = cin.rdbuf(in.rdbuf());
ofstream out("answer.txt");
auto coutbuf = cout.rdbuf(out.rdbuf());
#endif

#ifndef DOMJUDGE
cin.rdbuf(cinbuf);
cout.rdbuf(coutbuf);
system("pause");
#endif*/

//Cualquier juez
/*
#define WORK_WITH_FILES //(quitar antes de enviar)
#ifdef WORK_WITH_FILES
ifstream in("casos.txt");
auto cinbuf = cin.rdbuf(in.rdbuf());
ofstream out("answer.txt");
auto coutbuf = cout.rdbuf(out.rdbuf());
#endif

#ifdef WORK_WITH_FILES
cin.rdbuf(cinbuf);
cout.rdbuf(coutbuf);
system("pause");
#endif*/
#endif

struct pareja{
	int veces = 1;
	int an;
	char al;
	int bn;
	char bl;
};
struct triint{
	int a;
	int b;
	int c;
};
typedef vector<triint> vti;
typedef vector<pareja> fashion;

bool buscar(fashion &lista, const pareja &par, int k, int &pos);
void operar(vti & lista, fashion & moda, int j, int p, int s, int k);

int main(){
#ifdef WORK_WITH_FILES
	ifstream in("casos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
	ofstream out("answer.txt");
	auto coutbuf = cout.rdbuf(out.rdbuf());
#endif
	int casos, j, p, s, cons;
	cin >> casos;
	for (int i = 0; i < casos; ++i){
		cin >> j >> p >> s >> cons;
		fashion moda;
		vti lista;
		moda.clear();
		lista.clear();
		if (i == 3){
			i = i;
		}
		for (int l = 0; l < j; ++l){
			for (int k = 0; k < p; ++k){
				for (int h = 0; h < s; ++h){
					if (!(h == k && h == l && l == k)){
						operar(lista, moda, l, k, h, cons);
					}
				}
			}
		}
		int mini = min(s, p);
		mini = min(mini, j);
		for (int i = 0; i < mini; ++i){
			operar(lista, moda, i, i, i, cons);
		}
		cout << "Case #" << i + 1 << ": " << lista.size() << "\n";
		for (int i = 0; i < lista.size(); ++i){
			cout << lista[i].a << " " << lista[i].b << " " << lista[i].c << "\n";
		}
	}
#ifdef WORK_WITH_FILES
	cin.rdbuf(cinbuf);
	cout.rdbuf(coutbuf);
	system("pause");
#endif
	return 0;
}

bool buscar(fashion &lista, const pareja &par, int k, int &pos){
	int i = 0, vez;
	bool ok = false;
	for (; i < lista.size() && !ok; ++i){
		if (lista[i].al == par.al && lista[i].an == par.an &&
			lista[i].bl == par.bl && lista[i].bn == par.bn){
			ok = true;
			pos = i;
			vez = lista[i].veces;
			if (lista[i].veces < k){
				return true;
			}
		}
		else if (lista[i].al == par.bl && lista[i].an == par.bn &&
			lista[i].bl == par.al && lista[i].bl == par.al){
			ok = true;
			pos = i;
			if (lista[i].veces < k){
				return true;
			}
		}
	}
	if (!ok){
		pos = i;
		return true;
	}
	return false;
}

void operar(vti & lista, fashion & moda, int j, int p, int s, int k){
	int posa = 0, poso = 0, posh = 0;
	int size = moda.size();
	pareja aux, otro, help;
	bool ok = false;
	aux.veces = 1;
	aux.al = 'J';
	aux.an = j;
	aux.bl = 'P';
	aux.bn = p;
	otro = aux;
	otro.al = 'S';
	otro.an = s;
	help = otro;
	help.bl = 'J';
	help.bn = j;
	if (buscar(moda, aux, k, posa) && buscar(moda, otro, k, poso) && buscar(moda, help, k, posh)){
		lista.push_back({ j + 1, p + 1, s + 1 });
		if (posa == size){
			moda.push_back(aux);
		}
		else{
			++moda[posa].veces;
		}
		if (poso == size){
			moda.push_back(otro);
		}
		else{
			++moda[poso].veces;
		}
		if (posh == size){
			moda.push_back(help);
		}
		else{
			++moda[posh].veces;
		}
	}
}
