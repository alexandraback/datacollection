#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100;

void reverseStack(string &s, int i, int j)
{
    while (i < j)
    {
        swap(s[i], s[j]);
        i++;
        j--;
    }
}

void doOperation(string &s, int firstX)
{
    for (int i = 0; i < firstX; ++i)
    {
        if (s[i] == '+')
            s[i] = '-';
        else
            s[i] = '+';
    }

    reverseStack(s, 0, firstX - 1);
}

int getIndex(string &s)
{
    int i = s.size() - 1;

    while (i >= 0)
    {
        if (s[i] == '-')
            return i;
    }

    return -1;
}

bool testAll(string &s, int limit)
{
    for (int i = 0; i < limit; ++i)
        if (s[i] != '-')
            return false;

    return true;
}

map< pair<string, int> ,int> dp;

int memo(string s, int limit)
{
    if (testAll(s, limit))
        return 0;

    if (limit == 1)
    {
        if (s[0] == '-')
            return 0;
        else
            return 1;
    }

    int sol = numeric_limits<int>::max() / 2;

    int indice = getIndex(s);
    assert(s[indice] == '-');
    assert(indice < limit);

    sol = 1 + memo(s, limit - 1);

    return sol;
}

int smartSolve(string stiva)
{
    int solution = 0;

    for (int i = stiva.size() - 1; i >= 0; i--)
    {
        if (stiva[i] == '-')
        {
            if (stiva[0] == '+')
            {
                solution++;

                for (int j = i - 1; j >= 0; j--)
                    if (stiva[j] == '+')
                    {
                        doOperation(stiva, j + 1);
                        break;
                    }

            }

            solution++;
            doOperation(stiva, i + 1);
        }
    }

    assert(count(stiva.begin(), stiva.end(), '-') == 0);

    return solution;
}

int smartSolveOld(string stiva)
{
    int solution = 0;

    for (int i = stiva.size() - 1; i >= 0; i--)
    {
        if (stiva[i] == '-')
        {
            if (stiva[0] == '+')
            {
                solution++;
                doOperation(stiva, 1);
            }

            solution++;
            doOperation(stiva, i + 1);
        }
    }

    assert(count(stiva.begin(), stiva.end(), '-') == 0);

    return solution;
}

int main()
{
    ifstream in("B-small-attempt1.in");
    ofstream out("pancakes.out");

    int T;
    in >> T;

    for (int t = 1; t <= T; ++t)
    {
        string s;
        in >> s;

        int N = s.size();
        assert(N <= MAX_N);

        assert(smartSolve(s) <= smartSolveOld(s));

        out << "Case #" << t << ": " << smartSolve(s) << endl;
    }

    return 0;
}
