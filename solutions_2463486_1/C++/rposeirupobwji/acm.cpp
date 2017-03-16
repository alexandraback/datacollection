#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include <queue>
#include <numeric>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <map>
#include <stack>
#include <unordered_map>
#include <ctime>
#include <cstring>
#include <cassert>

typedef signed char int8;
typedef unsigned char uint8;
typedef signed int int32;
typedef unsigned int uint32;
typedef signed long long int64;
typedef unsigned long long uint64;

#define mp(a, b) std::make_pair(a, b)
using namespace std;

vector<string> good;

bool square(vector<uint8> const& in, vector<uint8>& res)
{
    int s = in.size();

    for (int i = 0; i < s; ++i)
    {
        for (int k = 0; k < s; ++k)
        {
            res[i + k] += in[i] * in[k];
            if (res[i + k] / 10)
                return false;
        }
    }

    return true;
}

string s;
vector<uint8> res;
vector<uint8> cpy;

bool validate(vector<uint8> const& v, bool mid)
{
    cpy = v;
    for (int i = v.size() - 1 - mid; i >= 0; --i)
        cpy.push_back(v[i]);

    res.clear();
    res.resize(cpy.size() * 2, 0);

    if (!square(cpy, res))
        return false;

    int total = res.size() - 1;
    s.clear();
    while (res[total] == 0)
        --total;


    for (int i = total; i >= 0; --i)
        s += res[i];
    
    good.push_back(s);
    return true;
}

void build(vector<uint8>& v, int size, int sum)
{
    if (v.size() >= size)
    {
        validate(v, true);
        validate(v, false);
        return;
    }

    if (v.size() == size - 1)
    {
        v.push_back(0);
        build(v, size, sum);
        v.pop_back();
        if (sum <= 8)
        {
            v.push_back(1);
            build(v, size, sum + 1);
            v.pop_back();
        }

        if (sum <= 5)
        {
            v.push_back(2);
            build(v, size, sum + 4);
            v.pop_back();
        }

        if (sum == 0)
        {
            v.push_back(3);
            build(v, size, sum + 9);
            v.pop_back();
        }
    }
    else for (uint8 i = v.size() ? 0 : 1; i < 3; ++i)
    {
        if (sum + 2 * i * i < 10)
        {
            v.push_back(i);
            build(v, size, sum + 2 * i * i);
            v.pop_back();
        }
    }
}

bool comp(string const& a, string const& b)
{
    if (a.size() != b.size())
        return a.size() < b.size();

    return a < b;
}

int main()
{
//#define GENERATE
// time to generate (i5-3750)
//real    0m57.929s
//!!!!!!!!!!!!!!!!!!!! delete two empty lines from beginning of data.txt, too lazy to fix it in code
#ifdef GENERATE
{
    for (int i = 1; i <= 50; ++i)
        build(vector<uint8>(), i, 0);

    sort(good.begin(), good.end(), comp);

    FILE* f = fopen("data.txt", "w");
    for (int i = 0; i < good.size(); ++i)
    {
        for (int j = 0; j < good[i].size(); ++j)
            fprintf(f, "%c", good[i][j] + '0');

        fprintf(f, "\n");
    }

    fclose(f);
}
#endif

    int t;
    cin >> t;

    char buff[500];

    for (int CASE = 1; CASE <= t; ++CASE)
    {
        string lo, hi;
        cin >> lo >> hi;

        FILE* f = fopen("data.txt", "r");

        int res = 0;

        while (1)
        {
            
            fscanf(f, "%s", buff);
            string s = string(buff);

            //for (int i = 0; i < s.size(); ++i)
                //s[i] -= '0';

            if (comp(s, lo) && s.compare(hi) != 0)
                continue;

            if (comp(s, hi) || s.compare(hi) == 0)
                ++res;
            else
                break;
        }

        printf("Case #%d: %d\n", CASE, res);
        fclose(f);
    }

    return 0;
}
