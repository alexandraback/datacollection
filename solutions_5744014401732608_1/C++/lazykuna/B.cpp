#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <math.h>
using namespace std;

ifstream f;
typedef long long int int64;

void process() {
	// kind of binary problem
	int b;
	int64 m;
	int64 n[51];
	int node[50];	for (int i=0;i <50; i++) node[i]=0;
	f >> b >> m;
	n[0]=n[1]=1;
	for (int i=2; i<=50; i++) n[i]=n[i-1]*2;
	// should smaller than 2**(n-2)
	if (n[b-1]<m) {
		cout << "IMPOSSIBLE" << endl;
		return;
	} else cout << "POSSIBLE" << endl;
	for (int i=b-2; i>=0; i--) {
		if (m>=n[i]) {
			m-=n[i];
			node[i]=1;
		}
	}
	for (int i=0; i<b; i++) {
		for (int j=0; j<=i && j<b-1; j++) cout << '0';
		for (int j=i+1; j<b-1; j++) cout << '1';
		cout << (char)(node[i]+'0');
		cout << endl;
	}
}

int main(int argc, char** argv) {
	f.open(argc>=2?argv[1]:"input.txt");
	int n;	f>>n;
	for(int i=0; i<n; i++) {
		cout << "Case #" << i+1 << ": ";
		process();
	}
	f.close();
	return 0;
}
