#include <iostream>

using namespace std;

int main(){

    int kase;
    cin >> kase;

    for (int k = 1; k <= kase; k++){
        int K, C, S;
        cin >> K >> C >> S;
        cout << "Case #" << k << ": ";
        for (int i = 1; i <= S; i++){
            cout << i ;
            if (i != S)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}
