#include <iostream>
using namespace std;
long long convert(int base, int a[], int length)
{
    long long ans = 0;
    for (int i = 0; i < length; i++)
    {   ans *= base;
        ans = ans + a[i];
    }
    return ans;
}
int main()
{
    int T, K, C, S;
    cin >> T;
    for (int kase = 1; kase <= T; kase++)
    {   cin >> K >> C >> S;
        
        cout << "Case #" << kase << ":";
        if (K == S) 
        {
            for (int i = 0; i < K; ++i) cout << " " << i+1 ;

                cout << endl;
        }   
        else if (K > S*C) cout << " IMPOSSIBLE" << endl;
        else
        {   int cnt = 0;
            int a[min(K, C)];
            for (int i = 0; i < min(K, C); ++i)
                a[i] = i;
            for (int i = 0; i < S && cnt < K; ++i)
            {   

                cout << " " << convert(K, a, min(K, C))+1;

                cnt += min(K, C);

                for (int j = 0; j < min(K, C); ++j)
                {
                    a[j] += min(K-cnt, min(K, C));
                }

            }
            cout << endl;
        }
    }
    return 0;
}
