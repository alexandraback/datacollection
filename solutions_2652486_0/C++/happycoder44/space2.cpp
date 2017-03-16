#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <stdio.h>

#define pb push_back
#define mp make_pair

using namespace std;


int main(){
    long long data[10];
    long long T,R,N,M,K;
    long long v1,v3,v4;
    double v2;
    cin >> T;
    cin >> R >> N >> M >> K;
    cout << "Case #1:" << endl;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < 10 ; j++)
            data[j] = 0;

        for(int j = 0; j < K; j++){
            cin >> v1;
            for(int z = M; z >= 2; z--){
                while(v1 % z == 0){
                    data[z]++;
                    v1 = v1/z;
                }

            }
        }

            for(int p = 0; p < N; p++){
            int max = 2;
            for(int z = 2; z <= M; z++){
                if(data[max] < data[z])
                    max = z;
            }
            cout << max;
            data[max] /=2;
            }
            cout << endl;



        }


return 0;
}
