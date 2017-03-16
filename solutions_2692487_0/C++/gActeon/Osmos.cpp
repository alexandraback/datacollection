#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Data
{
    int a, n;
    vector<int> arr;
};

Data inputTest(ifstream& in)
{
    Data res;
    in >> res.a >> res.n;
    res.arr.resize(res.n);
    for (int i = 0; i < res.n; ++i)
    {
        in >> res.arr[i];
    }

    sort(res.arr.begin(), res.arr.end());

    return res;
}

int processTest(const Data& data)
{
    int aa = data.a;
    int op = 0;

    if (aa == 1)
    {
        return data.n;
    }

    vector<int> t(data.n);
    for (int i = 0; i < data.n; ++i)
    {
        while (aa <= data.arr[i])
        {
            if (aa - 1 > 0)
                aa += (aa - 1);
            else
                ++aa;
            ++op;
        }
        aa += data.arr[i];
        t[i] = op;
    }

    int m = data.n;
    for (int i = 0; i < data.n; ++i)
    {
        int nm = t[i] + (data.n - i - 1);
        if (nm < m)
            m = nm;
    }

    return m;
}

void outputTest(ofstream& out, int t, const int res)
{
    out << "Case #" << t + 1 << ": " << res << endl;
}

int main()
{
    ifstream in("input.txt");
    if (!in.is_open())
        return 1;

    ofstream out("ouput.txt");
    if (!out.is_open())
        return 1;

    int testCases;
    in >> testCases;

    for (int t = 0; t < testCases; ++t)
    {
        Data test;
        test = inputTest(in);
        int res = processTest(test);
        outputTest(out, t, res);
    }

    return 0;
}

