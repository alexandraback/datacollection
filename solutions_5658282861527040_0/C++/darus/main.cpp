#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <cassert>

struct TestCase
{
    unsigned long long a, b, k;
};


std::vector<TestCase> ReadCases(std::istream& stream)
{
    int totalCases;
    std::vector<TestCase> result;

    stream >> totalCases;

    for (int i = 0; i < totalCases; i++)
    {
        TestCase testCase;
        stream >> testCase.a >> testCase.b >> testCase.k;

        result.push_back(testCase);
    }

    return result;
}

int FindPower(unsigned long long num)
{
    int res = 0;
    while (num > 0)
    {
        res++;
        num >>= 1;
    }

    return res - 1;
}

unsigned long long Solve1(unsigned long long a, unsigned long long b, unsigned long long k)
{
    unsigned long long result = 0;

    int N = FindPower(k);
    int M = FindPower(b);
    int L = FindPower(a);

    unsigned long long S = 1;
    for (int i = 0; i < N; i++)
    {
        S *= 4;
    }

    result = S;

    for (unsigned long long i = (1LL << N); i < std::min(a, 1ULL << (N+1)); i++)
    {
        result += S;
    }

    for (unsigned long long j = (1LL << N); j < std::min(b, 1ULL << (N+1)); j++)
    {
        result += S;
    }

    for (unsigned long long i = (1LL << N); i < std::min(a, 1ULL << (N+1)); i++)
    {
        for (unsigned long long j = (1LL << N); j < std::min(b, 1ULL << (N+1)); j++)
        {
            if ((i & j) < k)
            {
                result++;
            }
        }
    }

    if (L == N)
    {
        return result;
    }

    S = result;
    result = 0;

    unsigned long long T = 1;
    for (int i = 0; i < M - N; i++)
    {
        T *= 3;
    }

    result += S * T;

    if (L == M)
    {
        for (unsigned long long i = (1LL << M); i < std::min(a, 1ULL << (M+1)); i++)
        {
            for (unsigned long long j = (1LL << M); j < std::min(b, 1ULL << (M+1)); j++)
            {
                if (((i & j) >> M) == 0)
                {
                    result++;
                }
            }
        }

        return result;
    }

    if (M > N)
    {
        for (unsigned long long j = (1LL << M); j < b; j++)
        {
            auto tj = j >> M;
            for (int i = 0; i < M - N - 1; i++)
            {
                if (tj & 0x1)
                {
                    result ++;
                }
                else
                {
                    result += 2;
                }
            }
        }
    }

    result += ((a - b)) * result;

    return result;
}

unsigned long long Solve(const TestCase& testCase)
{
    unsigned long long a = testCase.a;
    unsigned long long b = testCase.b;
    unsigned long long k = testCase.k;

    unsigned long long result = 0;

    for (auto i = 0; i < a; i++)
    {
        for (auto j = 0; j < b; j++)
        {
            if ((i & j) < k)
            {
                result++;
            }
        }
    }

    return result;


    if (a == 0)
    {
        return 0;
    }
    else if (b == 0)
    {
        return 0;
    }

    if ((k <= a) && (k <= b))
    {
        return Solve1(std::max(a, b), std::min(a, b), k);
    }

    assert(false);
}

int main(int argc, char* argv[])
{
    std::vector<TestCase> cases;

    if (argc == 1)
    {
        cases = ReadCases(std::cin);
    }
    else if (argc == 2)
    {
        std::ifstream stream(argv[1]);
        if (!stream.good())
        {
            return 1;
        }

        cases = ReadCases(stream);
    }
    else
    {
        return 1;
    }

    int testNum = 1;
    for (auto& testCase : cases)
    {
        std::cout << "Case #" << testNum << ": " << Solve(testCase) << std::endl;
        testNum++;
    }

    return 0;
}

