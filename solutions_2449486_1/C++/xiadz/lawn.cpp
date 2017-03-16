#include <iostream>
#include <algorithm>
using namespace std;

int A[100][100];
int rowmax[100];
int colmax[100];

int main()
{
    int T;
    cin >> T;
    for(int t=0; t<T; ++t){
        cout << "Case #" << (t+1) << ": ";
        int N, M;
        cin >> N >> M;
        for(int i=0; i<N; ++i){
            rowmax[i] = 0;
        }
        for(int j=0; j<M; ++j){
            colmax[j] = 0;
        }
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                cin >> A[i][j];
                rowmax[i] = max(rowmax[i], A[i][j]);
                colmax[j] = max(colmax[j], A[i][j]);
            }
        }
        bool possible = true;
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                if(A[i][j] < rowmax[i] && A[i][j] < colmax[j])
                    possible = false;
            }
        }
        if(possible)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

