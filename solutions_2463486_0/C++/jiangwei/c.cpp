#include <cmath>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

long long pali_manual[] = {
1,
2,
3,
11,
22,
101,
111,
121,
202,
212,
1001,
1111,
2002,
10001,
10101,
10201,
11011,
11111,
11211,
20002,
20102,
100001,
101101,
110011,
111111,
200002,
1000001,
1001001,
1002001,
1010101,
1011101,
1012101,
1100011,
1101011,
1102011,
1110111,
1111111,
2000002,
2001002
};

bool is_palidrome(string s)
{
    for (int i = 0; i < s.size() - i - 1; i++)
    {
        if (s[i] != s[s.size() - i - 1])
        {
            return false;
        }
    }
    return true;
}

bool is_palidrome(long long n)
{
    stringstream ss;
    ss << n;
    return is_palidrome(ss.str());
}

long long count_square_pali(long long max_bound, vector<long long> &pali)
{
    long long x = (long long)(sqrt(max_bound) + 1e-8);
    int index = std::lower_bound(pali.begin(), pali.end(), x) - pali.begin();
    if (index < pali.size() && pali[index] == x)
    {
        ++index;
    }
    //cout << max_bound << " " << x << " " << index << endl;
    return index;
}

int main()
{
    vector<long long> pali(pali_manual, pali_manual + sizeof(pali_manual) / sizeof(long long));
    /*
    long long bound = 10000000;
    //long long bound = 1000;
    for (long long n = 1; n <= bound; n++)
    {
        if (is_palidrome(n) && is_palidrome(n * n))
        {
            pali.push_back(n);
            cout << n << endl;
        }
    }*/
    //cout << "total: " << pali.size() << endl;
    long long T, A, B;
    cin >> T;
    for (int task = 1; task <= T; task++)
    {
        cin >> A >> B;
        cout << "Case #" << task << ": " << count_square_pali(B, pali) - count_square_pali(A - 1, pali) << endl;
    }
    return 0;
}
