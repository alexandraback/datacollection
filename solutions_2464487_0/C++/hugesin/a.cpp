#include<iostream>
using namespace std;

long long two(2);
long long bsearch(long long a, long long s, long long low, long long high)
{
    long long mid = (low + high) >> 1;
    if (mid == low)
    {
        return mid;
    }
    long long temp = (s / mid + 2 - a);
    if (temp < 0)
    {
        return bsearch(a, s, low, mid);
    }
    temp >>= 1;
    if (temp > mid)
    {
        return bsearch(a, s, mid, high);
    }
    else if (temp < mid)
    {
        return bsearch(a, s, low, mid);
    }
    else
    {
        return mid;
    }
}

int main()
{
    int n,  case_num;
    long long r, t, start;
    long long min = 1;
    long long max = 1E9;
    cin >> n;
    for (case_num = 1; case_num <= n; case_num++)
    {
        cin >> r >> t;
        cout << "Case #" << case_num << ": ";
        start = r * two + 1;
        cout << bsearch(start, t, min, max) << endl;
    }
    return 0;
}
