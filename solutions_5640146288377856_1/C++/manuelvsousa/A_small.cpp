#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main() {

	int N, a, c, b;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int resposta = 0;
		cin >> a >> c >> b;
		resposta = c / b *a;
		resposta += b - 1;
		if (c%b != 0)
			resposta++;
		cout << "Case #" << i + 1 << ": " << resposta << endl;
	}
	return 0;
}
