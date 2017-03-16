#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 64
#define MAXH 4096

int main() {
	int T, t, N, cant[MAXH], i, j, tmp, n[MAXN];

	cin >> T;
	for (t=1; t<=T; t++) {
		cin >> N;
		
		memset(cant, 0, sizeof(cant));
		for (i=0; i<2*N-1; i++) for (j=0; j<N; j++) {
			cin >> tmp;
			cant[tmp]++;
		}
		
		for (i=j=0; i<MAXH; i++) if (cant[i]%2) n[j++] = i;
		sort(n,n+N);
		
		cout << "Case #" << t << ":";
		for (i=0; i<N; i++) cout << ' ' << n[i];
		cout << endl;
	}

	return 0;
}
