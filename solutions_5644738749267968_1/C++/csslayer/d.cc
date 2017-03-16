#include <iostream>
#include <stdint.h>
#include <iomanip>
#include <algorithm>

using namespace std;
double wN[1000];
double wK[1000];
	
int main()
{
	int T;
	cin >> T;
	
	for (int t = 1; t <= T; t++) {
        int N;
		cin >> N;
		cout << "Case #" << t << ": ";
		
		for (int i = 0; i < N ; i++) {
			cin >> wN[i];
		}
		for (int i = 0; i < N ; i++) {
			cin >> wK[i];
		}
		
		sort(wN, wN + N);
		sort(wK, wK + N);

        int lK = 0;
        int uK = N - 1;
        int z = 0;
        for (int i = N - 1; i >= 0; i --)
        {
            if (wN[i] > wK[uK]) {
                lK ++;
                z ++;
            } else {
                uK --;
            }
        }
		
		// lets get z first
		// ken's strategy must be use he least to over naomi
		// and use the least for his fail
		// I don't see if there's a optimal strategy for naomi?..
		// let's think about from least
		
		// then y next
        lK = 0;
        uK = N - 1;
        int y = 0;
        for (int i = 0; i < N; i ++) {
            // if n small > k small, no cheat
            if (wN[i] > wK[lK]) {
                lK ++;
                y ++;
            } else {
                uK --;
            }
        }

        cout << y << " " << z << endl;
	}
}
