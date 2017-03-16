#include<iostream>

using namespace std;

main(void){
    long long T;
    cin >> T;
    for(long long i = 1; i <= T ; i++){
        long long K, C, S;
        cin >> K >> C >> S;
        cout << "Case #" << i << ": ";
        if (C * S < K){
            cout << "IMPOSSIBLE";
        } else {
            for(long long i = 0; (i*C) < K; i++){
                long long pos = 0; // numbers in [i*C,(i+1)*C)
                for(long long j = 0; j < C; j++){
                    if (j + i*C >= K) break;
                    pos = (pos * K) + (i*C + j);
                }
                cout << ( pos + 1 )<<" ";
            }
        }
        cout << endl;
    }
}
