#include <cstdint>
#include <iostream>

using namespace std;

int64_t gcd(int64_t a, int64_t b)
{
    int64_t c;
    while(a != 0)
    {
       c = a;
       a = b % a;
       b = c;
    }

    return b;
}

void solveCase()
{
    //read input
    int64_t P, Q;
    char c;
    cin >> P >> c >> Q;
    
    int64_t d = gcd(P, Q);
    P /= d;
    Q /= d;
    
    //check Q is a power of 2
    if(!(Q & (Q - 1)))
    {
        int64_t p = 2;
        for(int i = 1; i <= 40; ++i, p *= 2)
        {
            if(p * P - Q >= 0)
            {
                cout << i;
                return;
            }
        }
    }
    else
    {
        cout << "impossible";
    }
}

int main()
{
    int caseCount;
    cin >> caseCount;

    for(int i = 1; i <= caseCount; i++)
    {
        cout << "Case #" << i << ": ";
        solveCase();
        cout << endl;
    }

    return 0;
}
