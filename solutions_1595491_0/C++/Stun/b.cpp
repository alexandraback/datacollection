#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main (int argc, char const *argv[])
{
	int T, N, S, p, t;
	cin >> T;
	
	for (int casen = 1; casen <= T ; casen++){
		cin >> N >> S >> p;
		int cnt = 0;
		for (int i = 0 ; i < N ; i++){
			cin >> t;
			
			if ((t / 3) + ((t % 3)?1:0) >= p){
				cnt++;
				// cout << t << endl;
			}else if ((t / 3 > 0 || t % 3 > 1) && (t / 3) + ((t % 3 == 2)?1:0) + 1 >= p && S){
				cnt++;
				S--;
				// cout << t << endl;
			}
		}
		
		cout << "Case #" << casen << ": " << cnt << endl;
	}

	return 0;
}