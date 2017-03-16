#include <iostream>
#include <vector>
using namespace std;

int T, N;
double J[247];
double calc[247];

int main(void) {
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N;
        double X = 0;
        // input
        for(int j = 0; j < N; j++){
            cin >> J[j];
            X += J[j];
        }

        // calc
        for(int k = 0; k < 147; k++){
            calc[k] = -1;
        }
        int np = 0; // nadpriemerni
        double Xnp = 0; // sucet nadpriemernych
        for(int k = 0; k < N; k++){
            double ans = ((2.000 / N) - (J[k] / X)) * 100;
            if(ans < 0){np++; Xnp += J[k];}
            else calc[k] = ans;
        }
        if(np != 0){
            for(int k = 0; k < N; k++){
                if(calc[k] == -1) calc[k] = 0;
                else calc[k] = (((2.0 * X - Xnp) / (N - np) - J[k]) / X) * 100;
            }
        }

        // output
        cout << "Case #"; cout << (i + 1); cout << ":";
        for(int j = 0; j < N; j++){
            cout << " ";
            cout << calc[j];
        }
        cout << endl;
    }
}
