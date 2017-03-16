//#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
using namespace std;

ifstream cin("B-large.in");
ofstream cout("B-large.out");

int A[100][100];
int N,M;

pair<int,int> getmin(int & zmin) {
	pair<int,int> zp;
	zp.first = -1;
	int mmin = 1000;
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (A[i][j] == 0) continue; 
			if (A[i][j] < mmin) { mmin = A[i][j]; zp.first=i; zp.second = j; }
		}
	}
	zmin = mmin;
	return zp;
}

int main() {
int T;

cin >> T;
for (int tt=1; tt<=T; tt++) {
cout << "Case #"<<tt<<": ";
cin >> N >> M;
for (int i=0; i<N; i++) {
	for (int j=0; j<M; j++) {
		cin >> A[i][j];
	}
}
bool ok = true;
while (true) {
	int zmin;
	pair<int,int> zp = getmin(zmin);
	if (zp.first == -1) break;
	bool colt=true, rowt=true;
	for (int i=0; i<N; i++) {
		if (A[i][zp.second] == 0) continue;
		if (A[i][zp.second] != zmin) { colt=false; break; }
	}
	for (int i=0; i<M; i++) {
		if (A[zp.first][i] == 0) continue;
		if (A[zp.first][i] != zmin) { rowt=false; break; }
	}
	if (rowt==false && colt==false) { ok = false; break;  }
	if (rowt) for (int i=0; i<M; i++) A[zp.first][i] = 0;
	if (colt) for (int i=0; i<N; i++) A[i][zp.second] = 0;
}

if (ok) cout << "YES"; else cout << "NO";
cout <<endl;
}
return 0;
}

