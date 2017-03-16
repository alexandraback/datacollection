#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main(void) {
    unsigned short int t;

    cin >> t;

    for(int i=1; i <= t; i++) {
        
        cout << "Case #" << i << ": ";
        int J,P,S,K;
        cin >> J >> P >> S >>K;

        if (J*P*S == 1) {
        	cout << "1" << endl << "1 1 1" << endl;
        	continue;
        }

        int maxDays = J*P*K;
        if (maxDays > J*P*S) {
        	maxDays = J*P*S;
        }

        cout << maxDays << endl;

        bool * worn = new bool[J*P*S];

        for (int j = 0; j < J; j++) {
        	for (int p = 0; p < P; p++) {
        		for (int k = 0; k < S; k++) {
        			int day = j*(P+K) +p*K +k;
        			int index = j*(P+S) + p*K + day % S;

        			if (!worn[index]) {
        				cout << j+1 << " " << p+1 << " " << (day % S)+1 << endl;
        				worn[index] = true;
        			}

        			
        		}

        	}
        }



    }
    return 0;
}
