#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        long K, C, S;
        cin >> K >> C >> S;
        C--;
        cout << "Case #" << t << ":";

        long powK = 1;
        for(int i=0;i<C;i++) powK *= K;

        for(int k=1;k<=K;k++){
            cout << " " << powK*k;
        }
        cout << endl;
    }
}
