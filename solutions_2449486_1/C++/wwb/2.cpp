#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

int mm[110][110];
int A[110], B[110];
int n,m;

bool checkline(int l)
{
    int mx = 0;
    for (int i = 0; i < m; ++i)
        mx = max(mx, mm[l][i]);
    for (int i = 0; i < m; ++i)
        if (mx != mm[l][i])
        {
            if (A[i] && A[i] != mm[l][i])
                return false;
            else
                A[i] = mm[l][i];
        }
    B[l] = mx;
    return true;
}

bool checkcolumn(int c)
{
    int mx = 0;
    for (int i = 0; i < n; ++i)
        mx = max(mx, mm[i][c]);
    for (int i = 0; i < n; ++i)
        if (mx != mm[i][c])
        {
            if (B[i] && B[i] != mm[i][c])
                return false;
            else
                B[i] = mm[i][c];
        }
    A[c] = mx;
    return true;
}
const char * check()
{
    for (int l = 0; l < n; ++l)
        if (!checkline(l)) return "NO";
    for (int c = 0; c < m; ++c)
        if (!checkcolumn(c)) return "NO";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (mm[i][j] != min(A[j], B[i]))
                return "NO";
    return "YES";
}
int main()
{
    int T;
    cin >> T;
    for (int i = 1;  i <= T; ++i)
    {
        cin >> n >> m;
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < m; ++k)
                cin >> mm[j][k];
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        cout << "Case #" << i << ": " << check() <<endl;
    }
}