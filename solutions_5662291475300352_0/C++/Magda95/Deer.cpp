#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	long long int testy, n, wynik;
	long long int h, d1, d2, m1, m2;
	long long int delta, delta1, delta2;
	
	cin >> testy;
	for(int i=1; i<=testy; i++)
	{
		cin >> n;
		cin >> d1 >> h >> m1;
		if(n == 1 && d1 == 1) wynik = 0;
		else if(n == 1 && h == 2) 
		{
			wynik = 0;
			}
		else 
		{
			cin >> d2 >> h >> m2;
			if(d2 < d1) {swap(d1,d2); swap(m1,m2);}
			delta1 = 360 - d1;
			delta2 = 360 - d2;
			if(m1*delta1 < m2*(360+delta2)) wynik = 0;
			else wynik = 1;
			}
			
		cout << "Case #" << i << ": " << wynik << endl;
		}
	return 0;
}

