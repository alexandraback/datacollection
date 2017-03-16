#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long uint64;

size_t next_type(const vector<uint64>& types, size_t index, uint64 t)
{
    for (size_t i = index; i < types.size(); ++i)
        if (types[i] == t)
            return i;
    return -1;
}

int main()
{
    uint64 T = 0;
    cin >> T;

    for (uint64 t = 1; t <= T; ++t)
    {
        size_t N = 0, M = 0;
        cin >> N >> M;

        vector<uint64> a(N + 1, 0), A(N + 1, 0), b(M + 1, 0), B(M + 1, 0);
        for (size_t i = 1; i <= N; ++i)
            cin >> a[i] >> A[i];
        for (size_t i = 1; i <= M; ++i)
            cin >> b[i] >> B[i];

        uint64 count = 0;
        for (size_t i = 1, j = 1; i < a.size() && j < b.size(); )
        {
            if (A[i] != B[j])
            {
                size_t next_i = next_type(A, i + 1, B[j]);
                size_t next_j = next_type(B, j + 1, A[i]);

                if (next_i >= A.size())
                {
                    ++j;
                    continue;
                }
                if (next_j >= B.size())
                {
                    ++i;
                    continue;
                }

                if (min(a[next_i], b[j]) > min(b[next_j], a[i]))
                    i = next_i;
                else if (min(b[next_j], a[i]) > min(a[next_i], b[j]))
                    j = next_j;
                else
                {
                    if (next_i < next_j)
                        i = next_i;
                    else
                        j = next_j;
                }
            }
            else
            {
                uint64 val = min(a[i], b[j]);
                count += val;
                a[i] -= val;
                b[j] -= val;
                if (0 == a[i])
                    ++i;
                if (0 == b[j])
                    ++j;
            }
        }

        cout << "Case #" << t << ": " << count << endl;
    }

    return 0;
}