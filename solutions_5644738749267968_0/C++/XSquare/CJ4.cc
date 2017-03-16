#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t){
        int N;
        cin >> N;
        vector <double> Nao(N);
        vector <double> Ken(N);
        for (int i = 0; i < N; ++i) cin >> Nao[i];
        for (int i = 0; i < N; ++i) cin >> Ken[i];
        sort(Nao.begin(), Nao.end());
        sort(Ken.begin(), Ken.end());
        int contini = 0;
        int contfin = N-1;
        int points1 = 0;
        for (int i = 0; i < N; ++i){
            if (Nao[i] < Ken[contini]){
               --contfin;
            }
            else{
                 ++contini;
                 ++points1;
            }
        }
        int points2 = 0;
        int continf = 0;
        int contsup = 0;
        for (int i = 0; i < N; ++i){
            while (contsup < N and Ken[contsup] < Nao[i]) ++contsup;
            if (contsup == N) ++points2;
            else ++contsup;
        }
        cout << "Case #" << t << ": " << points1 << " " << points2 << endl;
    }
}
