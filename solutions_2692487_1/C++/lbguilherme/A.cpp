
#include <iostream>
#include <algorithm>

using namespace std;

int solve(int* m, int N, int A)
{
    for (int i = 0; i < N; ++i)
    {
        if (m[i] < A)
        {
            A += m[i];
        }
        else
        {            
            unsigned sz1 = (A == 1 ? -1 : solve(m+i, N-i, A+A-1));
            unsigned sz2 = N-i-1;
            return min(sz1, sz2)+1;
        }
    }
    return 0;
}

int main()
{
    int total;
    cin >> total;
    for (int current = 0; current < total; ++current)
    {
        cout << "Case #" << current+1 << ": ";
        
        int A, N;
        cin >> A >> N;
        
        int m[N];
        for (int i = 0; i < N; ++i)
            cin >> m[i];
        
        sort(m, m+N);
        // A=2
        // 100 101 102 
        int r = solve(m, N, A);
        cout << r << endl;
        
        
    }
}
