#include <iostream>
#include <sstream>

using namespace std;

string numDays(int J, int P, int S, int K)
{
    int count = 0;
    int **JP = new int*[J];
    for(int i = 0; i < J; i++) {
        JP[i] = new int[P];
        for(int j = 0; j < P; j++)
            JP[i][j] = 0;
    }
    int **JS = new int*[J];
    for(int i = 0; i < J; i++) {
        JS[i] = new int[S];
        for(int j = 0; j < S; j++)
            JS[i][j] = 0;
    }
    int **PS = new int*[P];
    for(int i = 0; i < P; i++) {
        PS[i] = new int[S];
        for(int j = 0; j < S; j++)
            PS[i][j] = 0;
    }
    if(S == 1)
        return "1\n1 1 1\n";
    ostringstream oss;
    for(int k = 0; k < S; k++) {
        for(int j = 0; j < P; j++) {
            for(int i = 0; i < J; i++) {
                if(JP[i][j] < K && JS[i][k] < K && PS[j][k] < K) {
                    count++;
                    JP[i][j]++;
                    JS[i][k]++;
                    PS[j][k]++;
                    oss << i+1 << " " << j+1 << " " << k+1 << endl;
                }
            }
        }
    }

    ostringstream oss2;
    oss2 << count << endl << oss.str();
    return oss2.str();
}

int main()
{
    int T, J, P, S, K;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cin >> J >> P >> S >> K;
        cout << "Case #" << i << ": " << numDays(J, P, S, K);
    }
}
