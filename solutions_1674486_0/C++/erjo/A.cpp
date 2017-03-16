#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

#define FOR(i, n) for (int i = 0; i < n; i++)

using namespace std;

int a[1000][10];
int v[1000];
int M[1000];

int diamond(int i)
{
    if (v[i])
        return 1;
    FOR (j, M[i]) {
        if (diamond(a[i][j]-1))
            return 1;
    }
    v[i] = 1;
    return 0;
}

int main()
{
    int T, N, found;

    cin >> T;
    FOR (t, T) {
        cout << "Case #" << t + 1 << ": ";

        cin >> N;
        FOR (i,N) {
            cin >> M[i];
            FOR (j, M[i])
                cin >> a[i][j];
        }

        /*FOR (i,N) {
            FOR (j, M[i])
                cout << a[i][j] << " ";
            cout << ";" << endl;
        }*/
        
        found = 0;
        FOR (i,N) {
            memset(v,0,1000*sizeof(int));
            if (diamond(i)) {
                found = 1;
                break;
            }
        }

        cout << ((found) ? "Yes" : "No") << endl;
    }
    return 0;
}
