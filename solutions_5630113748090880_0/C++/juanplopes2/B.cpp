#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

vector<int> T[110];
int B[110];
bool K[110];
bool M[110];
int n;

bool canPut(int index, int i) {
    if (index == 0) return true;
    for(int j=0; j<n; j++)
        if (T[i][j] <= T[B[index-1]][j])
            return false;
    return true;
}

bool isSameColumn(int i, int k) {
    for(int j=0; j<n; j++)
        if (T[i][j] != T[B[j]][k])
            return false;
    return true;
}

bool backtrack(int index, int list) {
    if (index == n) {
        memset(M, 0, sizeof M);
        int count = 0;
        for(int i=0; i<2*n-1; i++) {
            if (!K[i]) {
                for(int k=0; k<n; k++) {
                    if (!M[k] && isSameColumn(i, k)) {
                        M[k] = true;
                        count++;
                        break;
                    }
                }
            }
        }
        return count == n-1;
    }
    if (list>=n*2-1) return false;


    for(int i=list; i<n*2-1; i++) {
        if (canPut(index, i)) {
            K[i] = true;
            B[index] = i;
            if (backtrack(index+1, i+1))
                return true;
            K[i] = false;
        }
    }
    return false;
}

bool lesser(vector<int> A, vector<int> B) {
    for(int i=0; i<A.size(); i++) {
        if (A[i] < B[i]) return true;
        if (A[i] > B[i]) return false;
    }    
    return false;
}

int main() {
    int tests; cin >> tests;
    for(int test=1; test<=tests; test++) {
        cin >> n;
        memset(K, 0, sizeof K);
        for(int i=0; i<n*2-1; i++) {
            T[i].clear();
            for(int j=0; j<n; j++) {
                int temp; cin >> temp; T[i].push_back(temp);
            }
        }
        sort(T, T+(n*2-1), lesser);
        backtrack(0, 0);
       
        cout << "Case #" << test << ":";
        
        for(int i=0; i<n; i++) {
            if (!M[i]) {
                for(int j=0; j<n; j++) {
                    cout << " " << T[B[j]][i];
                }
            }
        }
        cout << endl;
    }
}
