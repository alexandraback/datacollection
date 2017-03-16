#include <iostream>
#include <cmath>
using namespace std;
unsigned long long convert(int base, int a)
{   unsigned long long ans = 0;
    unsigned long long p = 1;
    while (a > 0)
    {   ans += p * (a&1);
        p *= base;
        a >>= 1;
    }
    return ans;
}

string binary(int a, int length)
{   string s;
    while (a > 0)
    {   s = (char)((a & 1) + '0') + s;
        a >>= 1;
    }
    return s;
}

int main()
{   int cnt = 0, T;
    cin >> T;

    int S, N;
    cin >> N >> S;  // N = 32, S = 500;


    int len = 0;
    for (int i = 2; i <= sqrt(N); ++i)
        if (N % i == 0)
        {
            len = N/i;
            break; 
        }
    
    if (len > 0)
    {
        cout << "Case #1: " << endl;
        len--;
        int base = (1 << len) + 1;
        for (int i = 0; i < (1 << (len-1)) && i < S; ++i)
        {   int temp = base + (i << 1);
            string s = binary(temp, len);
            for (int j = 0; j < N/len; ++j)
                cout << s;
            
            cout << " " << temp;
            for (int j = 3; j <= 10; ++j)
                cout << " "<< convert(j, temp);
            cout << endl;
        }
    }

    return 0;
}
