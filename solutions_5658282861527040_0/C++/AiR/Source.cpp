#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
	fstream plik, plikout;
	plik.open("a.in", ios::in);
	plikout.open("a.out", ios::out);
	int t;
	plik >> t;

	for (int i = 0; i < t; i++){
		int a, b, k;
		plik >> a >> b >> k;
		int max = 0;
		int wynik = 0;
		for (int j = a-1; j >= 0; j--){
			for (int g = b - 1; g >= 0; g--){
				//if (j & g > max) max = j & b;
				if ((j & g) < k) wynik++;
				//cout << (j & g) << endl;
			}
		}
		plikout << "Case #" << i + 1 << ": " << wynik << endl;

	}

	system("pause");
	plik.close();
	plikout.close();
}