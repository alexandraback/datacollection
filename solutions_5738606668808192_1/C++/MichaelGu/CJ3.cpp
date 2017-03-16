// CJ3.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <math.h>
#include <vector>

std::vector<unsigned int> prime;

class BigNum
{
public:
    static const unsigned int radix = 100000000;
    //static const unsigned int radix = 100;

    std::vector<unsigned int> data;

    BigNum(unsigned int raw, int base)
    {
        if (2 == base)
            data.push_back(raw);
        else
        {
            for (int i = 31; i >= 0; i--)
            {
                multiply(base);

                if (0 != (raw & (1 << i)))
                {
                    add(1);
                }
            }
        }
    }

    void multiply(unsigned int mult)
    {
        int len = data.size();
        for (int i = 0; i < len; i++)
        {
            data[i] *= mult;
        }

        for (int i = 0; i < len; i++)
        {
            if (data[i] >= radix)
            {
                if (i+1 < len)
                    data[i+1] += (data[i] / radix);
                else
                    data.push_back(data[i] / radix);
                
                data[i] = (data[i] % radix);
            }
        }
    }

    void add(unsigned int addtional)
    {
        if (data.empty())
            data.push_back(addtional);
        else
            data[0] += addtional;

        int len = data.size();
        for (int i = 0; i < len; i++)
        {
            if (data[i] >= radix)
            {
                if (i+1 < len)
                    data[i+1] += (data[i] / radix);
                else
                    data.push_back(data[i] / radix);
                
                data[i] = (data[i] % radix);
            }
        }
    }

    unsigned int mode(unsigned int mod)
    {
        unsigned __int64 result = 0;

        int i = data.size() - 1;
        for (; i >= 0; i--)
        {
            unsigned int tmp = radix % mod;
            result = ((result * tmp) + data[i]) % mod;
        }

        return result;
    }

    bool big(unsigned int cmp)
    {
        if (data.empty())
            return false;

        if (data.size() > 1)
            return true;

        return data[0] > cmp;
    }
};

void initPrime(void)
{
    unsigned int ceil = 300000;

    prime.push_back(2);

    //unsigned int sq = sqrt(ceil) + 2;
    for (unsigned int i = 2; i < ceil; i++)
    {
        unsigned int isq = sqrt(i) + 2;
        unsigned int j = 2;
        for (; j < isq; j++)
        {
            if (0 == i%j)
                break;
        }

        if (j >= isq)
            prime.push_back(i);
    }
}

unsigned int getDivisor(BigNum& n)
{
    for (unsigned int i = 0; i < prime.size() && n.big(prime.at(i)); i++)
    {
        unsigned int tm = prime.at(i);
        if (0 == n.mode(tm))
            return tm;
    }

    return 0;
}

int main(void)
{
    initPrime();

    int t = 0;
    std::cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n = 0;
        int j = 0;

        std::cin >> n;
        std::cin >> j;

        std::cout << "Case #" << i << ":\n";

        unsigned int low = 1 << (n-2);
        unsigned int high = 1 << (n-1);
        int count = 0;
        for (unsigned int k = low; k < high && count < j; k++)
        {
            unsigned int raw = (k << 1) + 1;

            int base = 2;
            unsigned int div[11] = {0};
            for (; base <= 10; base++)
            {
                BigNum tmp(raw, base);
                div[base] = getDivisor(tmp);
                if (0 == div[base])
                    break;
            }

            if (base > 10)
            {
                for (int m = 0; m < n; m++)
                {
                    std::cout << ((raw & (1<<(n-m-1))) >> (n-m-1));
                }

                for (int base = 2; base <= 10; base++)
                    std::cout << " " << div[base];
                std::cout << std::endl;

                count++;
            }
        }
    }

    return 0;
}

