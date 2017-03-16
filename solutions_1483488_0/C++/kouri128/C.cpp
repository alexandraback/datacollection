#include <iostream>
#include <set>
#include <cmath>
using namespace std;

int pow10(int n)
{
    int ret = 1;
    while (n > 0)
    {
        n /= 10;
        ret *= 10;
    }
    return ret;
}
int main()
{
    int T;
    cin>>T;

    for (int i = 0; i < T; ++i)
    {
        int A, B;
        cin>>A>>B;

        long long ans = 0;
        for (int j = A; j <= B; ++j)
        {
            int front = j;
            int back = 0;
            int p = pow10(j);
            int q = 1;
            while (front > 0)
            {
                back = (front % 10) * q + back;
                front /= 10;
                p /= 10;
                q *= 10;
                int b = front + back * p;
                if (j == b)
                {
                    break;
                }
                if (j < b && b <= B)
                {
                    ++ans;
                }
            }
        }

        cout<<"Case #"<<i + 1<<": "<<ans<<endl;
    }

    return 0;
}
