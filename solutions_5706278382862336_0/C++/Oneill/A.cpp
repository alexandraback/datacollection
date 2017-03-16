#include <cstdint>
#include <cstdio>
#include <iostream>

using namespace std;

void solveCase()
{
    //read input
    unsigned int P, Q;
    scanf("%u/%u", &P, &Q);
    
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
