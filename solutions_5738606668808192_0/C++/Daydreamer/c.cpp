#include <iostream>
using namespace std;
long long convert(int base, int a)
{   long long ans = 0;
    int p = 1;
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
    cin >> N >> S;  // N = 16, S = 50;
    
    cout << "Case #1: " << endl;
    int base = (1 << 7) + 1;
    for (int i = 0; i < (1 << 6) && i < S; ++i)
    {   int temp = base + (i << 1);
        string s = binary(temp, 8);
        for (int j = 0; j < 2; ++j)
            cout << s;
        
        cout << " " << temp;
        for (int j = 3; j <= 10; ++j)
            cout << " "<< convert(j, temp);
        cout << endl;
    }

    return 0;
}
