#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>

using namespace std;

int main (int argc, char const *argv[])
{
	int T, A, B;
	cin >> T;
	
	for (int casen = 1; casen <= T ; casen++){
		cin >> A >> B;
		int cnt = 0;
		map <int, bool> M;
		for (int c = A ; c < B ; c++){
			M.clear();
			for (int i = 1 ; i < log10(c) ; i++){
				int n = c % (int)pow((double)10, (double)i) * pow((double)10, (double)floor(log10(c)) - i + 1) + c / pow((double)10, (double)i);
				// cout << n << " " << (n <= B && n > c) << endl;
				if (n <= B && n > c && M.find(n) == M.end()){
					M[n] = true;
					cnt++;
				} 
			}
		}
		
		cout << "Case #" << casen << ": " << cnt << endl;
	}

	return 0;
}