#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    //solve
    int T, N, max = 0;
    cin >> T;
    for(int i=0; i<T; i++)
    {
        cin >> N;
        cout << "Case #" << i+1 << ": ";
        int lst[2*N-1][N];
        for(int j=0; j<2*N-1; j++)
        {
            for(int k=0; k<N; k++)
            {
                cin >> lst[j][k];
                if(lst[j][k] > max)
                    max = lst[j][k];
            }
        }
        int counts[max+1];

        for(int j=0; j<max+1; j++)
            counts[j] = 0;

        for(int j=0; j<2*N-1; j++)
        {
            for(int k=0; k<N; k++)
            {
                counts[lst[j][k]]++;
            }
        }

        vector<int> remain;

        for(int j=0; j<max+1; j++)
        {
            if(counts[j]%2 != 0)
                remain.push_back(j);
        }

        sort(remain.begin(), remain.end());

        for(int j=0; j<remain.size(); j++)
            cout << remain[j] << " ";
        cout << endl;
    }
}

