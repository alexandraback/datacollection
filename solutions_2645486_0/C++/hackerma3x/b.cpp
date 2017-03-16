#include <iostream>
#include <fstream>
using namespace std;

long int maks;
int *v;

void rek(int E, int R, int N, int es, int in=0, int uk=0) {
	if(in<N) {
		if(es)
			for(int i=0; i<=es; i++)
				rek(E, R, N, (es-i+R)>E?E:es-i+R, in+1, uk+i*v[in]);
		return;
	}
	
	if(uk>maks)
		maks=uk;
}

void obrada() {
	int E, R, N;
	cin >> E >> R >> N;
	v = new int[N];
	for(int i=0; i<N; i++)
		cin >> v[i];
	
	maks = 0;
	rek(E, R, N, E);
	cout << maks;
	
	delete[] v;
}

int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int t;
	cin >> t;
	
	for(int i=1; i<=t; i++) {
		cout << "Case #" << i << ": ";
		obrada();
		cout << endl;
	}
	
	return 0;
}

