#include <cassert>
#include <iostream>

using namespace std;

struct Board
{
    Board() : N(0), M(0)
    {
        cin >> N >> M;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> get(i, j);
            }
        }
    }
    int N;
    int M;
    int data[100][100];

    int& get(int i, int j)
    {
        static int INVALID = -1;
        assert(INVALID == -1);
        if (i < 0 || i >= N)
        {
            return INVALID;
        }
        if (j < 0 || j >= M)
        {
            return INVALID;
        }
        return data[i][j];
    }

    bool solve()
    {
        int iMin[100];
        int jMin[100];
        int hMax[100];
        int vMax[100];
        for (int i = 0; i < N; i++) { iMin[i] = 999; hMax[i] = -1; }
        for (int j = 0; j < M; j++) { jMin[j] = 999; vMax[j] = -1; }

        // find maximum for each row
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                hMax[i] = max(hMax[i], get(i, j));
            }
        }
        // find maximum for each column
        for (int j = 0; j < M; j++)
        {
            for (int i = 0; i < N; i++)
            {
                vMax[j] = max(vMax[j], get(i, j));
            }
        }
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                const int value = get(i, j);
                if (value < vMax[j])
                {
                    iMin[i] = min(iMin[i], value);
                }
                if (value < hMax[i])
                {
                    jMin[j] = min(jMin[j], value);
                }
            }
        }

        // check constraints
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                const int value = get(i, j);
                if (value > iMin[i] || value > jMin[j])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cout << "Case #" << (t+1) << ": ";
        Board b;
        if (b.solve())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}

