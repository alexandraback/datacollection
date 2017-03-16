#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;
long long factors[11];

const int N_PRIMES = 168;

int primes[N_PRIMES] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997 };

long long to_base(int a, int base)
{
    long long ret = 0, t = 1;
    for(; a; a >>= 1, t *= base)
        if (a & 1)
            ret += t;
    return ret;
}

long long mod(long long a, int base, int b)
{
    long long t = 1, ret = 0;
    for(; a; a >>= 1, t = (t * base) % b) 
        if (a & 1)
            ret = (ret + t) % b;
    return ret;
}

long long find_factor(long long a, int base)
{
    for (int i = 0; i < 25; i++)
        if (mod(a, base, primes[i]) == 0)
            return primes[i];
    return -1;
}

void output_binary(long long a)
{
    if (!a) return;
    output_binary(a >> 1);
    printf("%lld", a & 1);
}

void solve()
{
    int n, j;
    scanf("%d%d", &n, &j);
    for (int i = 0; i < (1 << (n - 2)); i++)
    {
        long long t = 1 + (i << 1) + (1LL << (n - 1));
        bool flag = 1;
        for (int base = 2; base <= 10; base++)
        {
            long long factor = find_factor(t, base);
            if (factor == -1)
            {
                flag = 0;
                break;
            } 
            factors[base] = factor;
        }
        if (flag)
        {
            output_binary(t);
            for (int k = 2; k <= 10; k++)
                printf(" %lld", factors[k]);
            printf("\n");
            j--;
            if(!j) return;
        }
    }
}

int main()
{
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("Case #%d: \n", i);
        solve();
    }
    return 0;
}
