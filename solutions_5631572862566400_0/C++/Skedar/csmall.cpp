#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int Nr[1005];

int Find(int x)
{
	if (Nr[x] != x)
		return Nr[x] = Find(Nr[x]);
	return x;
}
void Union(int x, int y)
{
	int a = Find(x), b = Find(y);
	if (a != b)
		Nr[a] = b;
}

pair < int, int > wierz(vector < int > & V, int v) //dlugosc, 1 jesli cykl, 2 jest sciezka mala, 0 jesli sciezka duza
{
	int N = V.size();
	vector < int > Odw(N, 0), Kol;
	while(Odw[v] == 0)
	{
		Odw[v] = 1;
		Kol.push_back(v);
		v = V[v];
	}
	/*
	cout << "A ";
	for(auto el : Kol)
		cout << el << " ";
		cout << "    " << v;
	cout << endl;
	* */
	int siz = Kol.size();
	if (v == Kol[siz-2])
	{
		if (Kol[siz-1] < Kol[siz-2])
			return {Kol.size(), 2};
		else
			return {Kol.size(), 0};
	}
	if (v == Kol[0])
		return {Kol.size(), 1};
	return {-1, 0};
	
}

void wynik()
{
	int N;
	cin>>N;
	vector < int > V(N);
	for(int i=0; i<=1001; i++)
		Nr[i] = i;
	for(int i=0; i<N; i++)
	{
		int pom;
		cin>>pom;
		pom --;
		V[i] = pom;
		Union(i, pom);
	}
	/*for(int i=0; i<N; i++)
		cout << Find(i)<<" ";
	cout << endl;*/
	vector < int > S1(N, 0), C(N, 0), S2(N, 0);
	for(int i=0; i<N; i++)
	{
		auto p = wierz(V, i);
		if (p.first == -1)
			continue;
		if (p.second == 1)
		{
			C[ Find(i) ] = p.first;
			continue;
		}
		if (p.second == 0)
		{
			S1[ Find(i) ] = max(S1[ Find(i)], p.first);
			continue;
		}
		if (p.second == 2)
		{
			S2[ Find(i) ] = max(S2[ Find(i)], p.first);
			continue;
		}
	}
	for(int i=0; i<N; i++)
	{
		S1[i] = max( max(S1[i], S2[i]), S1[i] + S2[i] - 2);
	}
	/*
	for(auto el : S)
		cout << el << " ";
	cout << endl;
	for(auto el : C)
		cout << el << " ";
	cout << endl;
	* */
	int best = 0;
	for(auto el : S1)
		best += el;
	for(auto el: C)
		best = max(best, el);
	cout << best;
}

int main()
{
//	ios_base::sync_with_stdio(0); cin.tie(0);
	int testy;
	cin>>testy;
	for(int test=1; test<=testy; test++)
	{
		cout << "Case #"<<test<<": ";
		wynik();
		cout<<endl;
	}
}
