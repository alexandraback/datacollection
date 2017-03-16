#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

#define OUTPUT_STRING "Case #%d: %d\n"

int nCase;
unsigned long long a, b;
vector<unsigned long long> q;
int digit[20];

bool IsFair(unsigned long long num)
{
    int len = 0;    
    while (num)
    {
        digit[len++] = num % 10;
        num /= 10;
    }
    int mid = len/2;
    for (int i=0; i<mid; ++i)
    {
        if (digit[i] != digit[len-i-1])
        {
            return false;
        }
    }

    return true;
}

void PrintResult(int cn, int count)
{
    printf(OUTPUT_STRING, cn, count);
}

int main()
{
    for (unsigned long long i=1; i<=10000000; ++i)
    {
        if (IsFair(i))
        {
            unsigned long long num = i * i;
            if (IsFair(num))
            {
                q.push_back(num);
            }
        }
    }

    //freopen("c.txt", "r", stdin);

    scanf("%d", &nCase);
    for (int cn=1; cn<=nCase; ++cn)
    {
        scanf("%I64d%I64d", &a, &b);
        int count = 0;
        for (int i=0; i<q.size(); ++i)
        {
            if (q[i] >= a && q[i] <= b)
            {
                ++count;
            }
        }
        PrintResult(cn, count);
    }

    return 0;
}
