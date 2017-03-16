#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <set>

using namespace std;

int main(int argc, char* argv[]) {
	ifstream f;
	f.open(argv[1]);
	int T;
	f >> T;
	for (int t=0; t<T; t++) {
		cout << "Case #" << t+1 << ": ";
		int A, B;
		f >> A >> B;
		int z = 0;
		for (int i=A; i<B; i++) {
			char s[10];
			sprintf(s, "%d", i);
			int n = strlen(s);
			set<int> L;
			for (int j=0; j<n-1; j++) {
				char ch = s[0];
				for (int k=0; k<n-1; k++) s[k] = s[k+1];
				s[n-1] = ch;
				int t = atoi(s);
				if  (t > i && t <= B && L.find(t) == L.end()) {
					z++;
					L.insert(t);
				}
					
			}
		}
		cout << z << endl;
	}
	f.close();
}
