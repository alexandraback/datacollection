#include<iostream>
using namespace std;

const long long P[] = {
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
2001002,
0};

void solve(int n)
{
    long long A, B, j;
    int i;
    cin >> A >> B;
    int ans = 0;
    for (i = 0; P[i] > 0; ++i)
    {
        j = P[i] * P[i];
        if (A <= j && j <= B)
            ans += 1;
    }
    cout << "Case #" << n << ": " << ans << endl;
}
int main()
{
    int n, i;
    cin >> n;
    for (i = 1; i <= n; ++i)
    {
        solve(i);
    }
}

