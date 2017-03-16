#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int> v);

int main(void)
{
    int t;
    cin >> t;
    for (int _t = 0; _t < t; _t++)
    {
        int n;
        cin >> n;
        vector<int> need1(n), need2(n);
        for (int i = 0; i < n; i++)
            cin >> need1[i] >> need2[i];
        vector<int> stars(n, 0);
        int numlevels = 0;
        while (sum(stars) < 2 * n)
        {
            int s = sum(stars);
            vector<int> gain(n, 0);
            for (int i = 0; i < n; i++)
                if (s >= need2[i])
                    gain[i] = 2 - stars[i];
                else if (s >= need1[i])
                    gain[i] = 1 - stars[i];
            if (sum(gain) == 0)
                break;
            int m = 0;
            for (int i = 1; i < n; i++)
                if (gain[i] > gain[m])
                    m = i;
            stars[m] += gain[m];
            numlevels++;
        }
        if (sum(stars) >= 2 * n)
            cout << "Case #" << _t + 1 << ": " << numlevels << endl;
        else
            cout << "Case #" << _t + 1 << ": Too Bad" << endl;
    }
}

int sum(vector<int> v)
{
    int s = 0;
    for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
        s += *it;
    return s;
}
