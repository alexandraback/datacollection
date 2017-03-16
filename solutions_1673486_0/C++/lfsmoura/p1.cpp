#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
	int t;
	cin >> t;

	for(int c = 1; c <= t; c++) {
		int a, b;
		cin >> a >> b;
		vector<double> p(a);
		double m = 1.0;
		for(int i = 0; i < a; i++) {
			cin >> p[i];
			m *= p[i];
		}
		
		vector<double> t(a+1);

		t[0] = b + 2; //quit
		//t[1] = ((double) (b - a + 1) * m) + ((double) (b + b - a + 2) * (1.0 - m) * (pow(2.0,a) - 1.0)); //keep typing

		double pAcertarTodos = 1.0;
		for(int backspaces = a-1; backspaces >= 0; backspaces--) {
			double keysErroCaptadoOuSemErro = backspaces + (b - a + backspaces) + 1;
			double keysSeErroNaoCaptado = keysErroCaptadoOuSemErro + b + 1;
			pAcertarTodos *= p[a - backspaces - 1];
			
			t[backspaces+1] = (keysErroCaptadoOuSemErro * pAcertarTodos) + (keysSeErroNaoCaptado * (1.0 - pAcertarTodos));
			//cout << endl << t[backspaces+1] << endl;
		}
		double e = *min_element(t.begin(), t.end());
		printf ("Case #%d: %1.6f\n", c, e);
		//cout << "Case #" << c << ": "<< e << endl;
	}

	return 0;
}