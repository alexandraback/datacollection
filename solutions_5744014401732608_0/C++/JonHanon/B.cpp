#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

int **generateCombinations(int B, int M)
{
    int **adj = new int*[B];
    for(int i = 0; i < B; i++) {
        adj[i] = new int[B];
        for(int j = 0; j < B; j++)
            adj[i][j] = 0;
    }
    for(int i = 0; i < B - 1; i++)
        for(int j = i + 1; j < B - 1; j++)
            adj[i][j] = 1;
    for(int i = B - 2; i >= 1; i--)
        if(M / pow(2,i-1) > 1) {
            M -= pow(2,i-1);
            adj[i][B-1] = 1;
        }
    if(M > 0)
        adj[0][B-1] = 1;
    return adj;
}

string matrix(int B, int M) {
    if(M > pow(2,B-2))
        return "IMPOSSIBLE";
    ostringstream oss;
    oss << "POSSIBLE";
    int **adj = generateCombinations(B, M);
    for(int i = 0; i < B; i++) {
        oss << endl;
        for(int j = 0; j < B; j++) {
            oss << adj[i][j];
        }
    }
    return oss.str();
}

int main()
{
    int T, B, M;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cin >> B >> M;
        cout << "Case #" << i << ": " << matrix(B,M) << endl;
    }
}
