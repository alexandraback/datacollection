#include <algorithm>
#include <climits>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define NMAX 1024

int N;
double Nao[10], Ken[10];
int **mem;

int calc1()
{
    bool used[10];
    memset(used, 0, sizeof(bool) * 10);

    int res = 0, targ;
    for (int i = 0; i < N; i++)
    {
        bool found = false;
        for (int j = 0; j < N; j++)
            if (!used[j] && Ken[j] > Nao[i])
            {
                if (!found || Ken[j] < Ken[targ])
                    targ = j;
                found = true;
            }
        if (found)
            used[targ] = true;
        else
        {
            int min = INT_MAX, mini;
            for (int k = 0; k < N; k++)
                if (!used[k] && Ken[k] < min)
                {
                    mini = k;
                    min = Ken[k];
                }
            res++;
            used[mini] = true;
        }
    }
    return res;
}

int calc2(int n, int k)
{
    if (mem[n][k] >= 0)
        return mem[n][k];

    int tmp[10] = {0};
    for (int i = 0; i < N; i++)
        if ((1 << i) & n)
            for (int j = 0; j < N; j++)
                if ((1 << j) & k)
                    tmp[i] = max(tmp[i], calc2(n & ~(1 << i), k & ~(1 << j)) + (Nao[i] > Ken[j] ? 1 : 0));

    mem[n][k] = INT_MAX;
    for (int i = 0; i < N; i++)
        if ((1 << i) & n)
            mem[n][k] = min(mem[n][k], tmp[i]);
    return mem[n][k];
}

void func(ifstream& in, ofstream& out)
{
    in >> N;
    for (int i = 0; i < N; i++)
        in >> Nao[i];
    for (int i = 0; i < N; i++)
        in >> Ken[i];

    for (int i = 0; i < NMAX; i++)
        for (int j = 0; j < NMAX; j++)
            mem[i][j] = -1;
    mem[0][0] = 0;

    out << calc2((1 << N) - 1, (1 << N) - 1) << " " << calc1() << endl;
}

int main()
{
    ifstream in;
    in.open("D-small-attempt0.in");

    ofstream out;
    out.open("code_jam_out");
    out << fixed << showpoint << setprecision(7);

    mem = new int*[NMAX];
    for (int i = 0; i < NMAX; i++)
        mem[i] = new int[NMAX];

    int T;
    in >> T;

    for (int t = 1; t <= T; t++)
    {
        //cout << "Case #" << t << endl;
        out << "Case #" << t << ": ";
        func(in, out);
    }

    in.close();
    out.close();

    return 0;
}
