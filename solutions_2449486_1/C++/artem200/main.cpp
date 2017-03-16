#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int u = 0; u < t; u++)
    {
        bool OLOLO = false;
        int n, m;
        cin >> n >> m;
        int A[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> A[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                bool o1 = false, o2 = false;
                for (int k = 0; k < m; k++)
                {
                    if (A[i][k] > A[i][j])
                        o1 = true;
                }
                for (int k = 0; k < n; k++)
                {
                    if (A[k][j] > A[i][j])
                        o2 = true;
                }
                if (o1 && o2)
                {
                    if (!OLOLO)
                        cout << "Case #" << u + 1 << ": NO" << endl;
                    OLOLO = true;
                }
            }
        }
        if (!OLOLO)
            cout << "Case #" << u + 1 << ": YES" << endl;
    }
    return 0;
}
