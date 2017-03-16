#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <bitset>
#include <algorithm>

using namespace std;

typedef vector<vector<int> > VVI;

//---------------------------------------------------------
int SToI(const string& s) { return atoi(s.c_str()); }
long long SToLL(const string& s) { return _atoi64(s.c_str()); }
double SToD(const string& s) { return atof(s.c_str()); }
//---------------------------------------------------------
string GetLine(ifstream& fs) { string ln; getline(fs, ln); return ln; }
int ParseInt(ifstream& fs) { return SToI(GetLine(fs)); }

//---------------------------------------------------------
template<typename T> struct Trait {};
template<> struct Trait<string> { static string FromS(const string& s) { return s; } };
template<> struct Trait<int> { static int FromS(const string& s) { return SToI(s); } };
template<> struct Trait<long long> { static long long FromS(const string& s) { return SToLL(s); } };
template<> struct Trait<double> { static double FromS(const string& s) { return SToD(s); } };

template<typename T>
void GetLines(ifstream& fs, vector<T>& out, int ct = 0)
{
    if (ct == 0)
    {
        ct = ParseInt(fs);
    }

    out.resize(ct);

    for (int i = 0; i < ct; i++)
    {
        out.push_back(Trait<T>::FromS(GetLine(fs)));
    }
}

template<typename T>
void Tokenize(ifstream& fs, vector<T>& out)
{
    string ln = GetLine(fs);

    size_t iFrom = 0;
    size_t iTo = 0;

    for (; iTo < ln.size(); iTo++)
    {
        if (ln[iTo] == ' ')
        {
            if (iTo > iFrom)
            {
                out.push_back(Trait<T>::FromS(ln.substr(iFrom, iTo - iFrom)));
            }
            
            iFrom = iTo + 1;
        }   
    }

    if (iTo > iFrom)
    {
        out.push_back(Trait<T>::FromS(ln.substr(iFrom, iTo - iFrom)));
    }
}

template<typename T>
void Tokenize(ifstream& fs, vector<vector<T> >& out, int ct = 0)
{
    if (ct == 0)
    {
        ct = ParseInt(fs);
    }

    out.resize(ct);

    for (int i = 0; i < ct; i++)
    {
        Tokenize(fs, out[i]);
    }
}

//---------------------------------------------------------
//---------------------------------------------------------
void Solve(ifstream&  fs)
{
    vector<int> ln1;
    vector<int> vs;

    Tokenize(fs, ln1);
    Tokenize(fs, vs);

    int e = ln1[0];
    int r = ln1[1];
    int n = ln1[2];

    if (r > e)
        r = e;

    vector<int> es(n, e);

    for (int i = 1; i < n; i++)
    {
        es[i] += i * r;
    }

    int v = 0;

    for (int i = 0; i < n; i++)
    {
        int toSpend = es[i] - e;

        while (toSpend > 0)
        {
            int max = vs[i - 1];
            int maxIndex = i - 1;
            for (int j = i - 2; j >= 0; j--)
            {
                if (es[j] == 0)
                    break;

                if (vs[j] > max)
                {
                    max = vs[j];
                    maxIndex = j;
                }
            }

            int canSpend = min(toSpend, es[maxIndex]);

            v += canSpend * vs[maxIndex];

            toSpend -= canSpend;

            for (int k = maxIndex; k < n; k++)
            {
                es[k] -= canSpend;
            }
        }
    }

    int toSpend = e;

    while (toSpend > 0)
    {
        int max = vs[n - 1];
        int maxIndex = n - 1;
        for (int j = n - 2; j >= 0; j--)
        {
            if (es[j] == 0)
                break;

            if (vs[j] > max)
            {
                max = vs[j];
                maxIndex = j;
            }
        }

        int canSpend = min(toSpend, es[maxIndex]);

        v += canSpend * vs[maxIndex];

        toSpend -= canSpend;

        for (int k = maxIndex; k < n; k++)
        {
            es[k] -= canSpend;
        }
    }

    cout << v;

}
//---------------------------------------------------------
int main(int argc, char* argv[])
{   
    string sz = argc == 2 ? argv[1] : "tt";
    string file = string(sz) + ".in";
    ifstream fs(file.c_str());

    if (fs.is_open())
    {
        int numTests = ParseInt(fs);

        for (int i = 0; i < numTests; i++)
        {
            cout << "Case #" << i + 1 << ": ";

            Solve(fs);

            cout << endl;
        }
    }
    else
    {
        cout << file << " not found" << endl;
    }



    return 0;
}
