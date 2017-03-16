#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

unsigned long long **generateCombinations(unsigned long long B, unsigned long long M)
{
    unsigned long long **adj = new unsigned long long*[B];
    for(unsigned long long i = 0; i < B; i++) {
        adj[i] = new unsigned long long[B];
        for(unsigned long long j = 0; j < B; j++)
            adj[i][j] = 0;
    }
    for(unsigned long long i = 0; i < B - 1; i++)
        for(unsigned long long j = i + 1; j < B - 1; j++)
            adj[i][j] = 1;
    for(unsigned long long i = B - 2; i >= 1; i--)
        if(M / pow(2,i-1) > 1) {
            M -= pow(2,i-1);
            adj[i][B-1] = 1;
        }
    if(M > 0)
        adj[0][B-1] = 1;
    return adj;
}

string matrix(unsigned long long B, unsigned long long M) {
    if(log(M)/log(2) > B-2)
        return "IMPOSSIBLE";
    ostringstream oss;
    oss << "POSSIBLE";
    unsigned long long **adj = generateCombinations(B, M);
    for(unsigned long long i = 0; i < B; i++) {
        oss << endl;
        for(unsigned long long j = 0; j < B; j++) {
            oss << adj[i][j];
        }
    }
    return oss.str();
}

int main()
{
    unsigned long long T, B, M;
    cin >> T;
    for(unsigned long long i = 1; i <= T; i++) {
        cin >> B >> M;
        cout << "Case #" << i << ": " << matrix(B,M) << endl;
    }
}
