// Problem C

#include <iostream>
#include <string.h>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <math.h>
#include <fstream>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;

bool check_solution(int *a, int *b, int *c, int J, int P, int S, int K, int cont) {
	// conto le ripetizioni delle coppie
	for (int j=1; j<=J; j++)
		for (int p=1; p<=P; p++) {
			int x = 0;
			for (int i=0; i<cont; i++)
				if (a[i] == j && b[i] == p) x++;
			if (x > K) return false;
		}
		
	for (int j=1; j<=J; j++)
		for (int s=1; s<=S; s++) {
			int x = 0;
			for (int i=0; i<cont; i++)
				if (a[i] == j && c[i] == s) x++;
			if (x > K) return false;
		}
	
	for (int s=1; s<=S; s++)
		for (int p=1; p<=P; p++) {
			int x = 0;
			for (int i=0; i<cont; i++)
				if (c[i] == s && b[i] == p) x++;
			if (x > K) return false;
		}
		
	for (int s=1; s<=S; s++)
		for (int p=1; p<=P; p++)
			for (int j=1; j<=J; j++) {
				int x = 0;
				for (int i=0; i<cont; i++) 
					if (c[i] == s && b[i] == p && a[i] == j) x++;
				if (x>1) return false;
			}
		
	return true;
}

void TestCase(int t) {
	int J, P, S, K;
	cin >> J >> P >> S >> K;
	
	int a[2000], b[2000], c[2000];
	int num = J*P*min(S, K);
	
	int cont = 0;
	for (int j=1; j<=J; j++)
		for (int p=1; p<=P; p++)
			for (int k=1; k<=min(S, K); k++) {
				a[cont] = j;
				b[cont] = p;
				if (P == 1)
					c[cont] = cont+1;
				else if (K >= S)
					c[cont] = (cont%S)+1;
				else
					c[cont] = ((cont+j)%P)+1;
				cont++;
			}
			
	assert(check_solution(a, b, c, J, P, S, K, cont));
	
	cout << "Case #" << t << ": " << num << endl;	
	for (int i=0; i<cont; i++)
		cout << a[i] << " " << b[i] << " " << c[i] << endl;
}

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; t++)
		TestCase(t);
	
	return 0;
}
