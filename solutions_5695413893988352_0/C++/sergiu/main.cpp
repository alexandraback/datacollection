#include <fstream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

char c[20];
char j[20];

long c_score;
long j_score;

/*
void is_greater(long cs, long js, int start, int len)
{
    for (int i = start; i < len; i++)
    {
        if (c[i] == '?')
            cs *= 10;
        else
            cs = cs * 10 + c[i] - '0';
        if (j[i] == '?')
            js = js * 10 + 9;
        else
            js = js * 10 + j[i] - '0';
    }
    c_score = cs;
    j_score = js;
}

void is_less(long cs, long js, int start, int len)
{
    for (int i = start; i < len; i++)
    {
        if (c[i] == '?')
            cs = cs * 10 + 9;
        else
            cs = cs * 10 + c[i] - '0';
        if (j[i] == '?')
            js = js * 10;
        else
            js = js * 10 + j[i] - '0';
    }
    c_score = cs;
    j_score = js;
}

void interclass(int len)
{
    long cs = 0, js = 0;
    int i;
    for (i = 0; i < len; i++)
    {
        if (c[i] == '?')
        {
            if (j[i] == '?')
            {
                if ((i < len - 1) && (c[i + 1] != '?') && (j[i + 1] != '?') && (c[i + 1] != j[i + 1]))
                {
                    if (c[i + 1] > j[i + 1])
                    {
                        if (c[i + 1] - j [i + 1] > 5)
                        {
                            cs *= 10;
                            js = js * 10 + 1;
                        }
                        is_less(cs, js, i + 1, len);
                    }
                    else
                    {
                        if (j[i + 1] - c[i + 1] > 5)
                        {
                            cs = cs * 10 + 1;
                            js = js * 10;
                        }
                        is_greater(cs, js, i + 1, len);
                    }
                    break;
                }
                cs *= 10;
                js *= 10;
            }
            else
            {
                if ((i < len - 1) && (c[i + 1] != '?') && (j[i + 1] != '?') && (c[i + 1] != j[i + 1]))
                {
                    if (c[i + 1] > j[i + 1])
                    {
                        if (j[i] > '0')
                        {
                            if (c[i + 1] - j [i + 1] > 5)
                            {
                                cs = cs * 10 + j[i] - '0' - 1;
                                js = js * 10 + j[i] - '0';
                            }
                            is_less(cs, js, i + 1, len);
                        }
                    }
                    else
                    {
                        if (j[i] < '9')
                        {
                            if (j[i + 1] - c[i + 1] > 5)
                            {
                                cs = cs * 10 + j[i] - '0' + 1;
                                js = js * 10 + j[i] - '0';
                            }
                            is_greater(cs, js, i + 1, len);
                        }
                    }
                    break;
                }
                cs = cs * 10 + j[i] - '0';
                js = js * 10 + j[i] - '0';
            }
            continue;
        }
        if (j[i] == '?')
        {
            if ((i < len - 1) && (c[i + 1] != '?') && (j[i + 1] != '?') && (c[i + 1] != j[i + 1]))
            {
                if (c[i + 1] > j[i + 1])
                {
                    if (c[i] < '9')
                    {
                        if (c[i + 1] - j [i + 1] > 5)
                        {
                            cs = cs * 10 + c[i] - '0';
                            js = js * 10 + c[i] - '0' + 1;
                        }
                        is_less(cs, js, i + 1, len);
                    }
                }
                else
                {
                    if (c[i] > '0')
                    {
                        if (j[i + 1] - c[i + 1] > 5)
                        {
                            cs = cs * 10 + j[i] - '0';
                            js = js * 10 + j[i] - '0' - 1;
                        }
                        is_greater(cs, js, i + 1, len);
                    }
                }
                break;
            }
            cs = cs * 10 + c[i] - '0';
            js = js * 10 + c[i] - '0';
            continue;
        }
        if (c[i] == j[i])
        {
            cs = cs * 10 + c[i] - '0';
            js = js * 10 + j[i] - '0';
            continue;
        }
        if (c[i] > j[i])
        {
            cs = cs * 10 + c[i] - '0';
            js = js * 10 + j[i] - '0';
            is_greater(cs, js, i + 1, len);
            break;
        }
        cs = cs * 10 + c[i] - '0';
        js = js * 10 + j[i] - '0';
        is_less(cs, js, i + 1, len);
        break;
    }
    if (i >= len)
    {
        c_score = cs;
        j_score = js;
    }
}

void solve()
{
    int len = strlen(c);
    interclass(len);
}
*/

void compute_values(long cs, long js)
{
    if (c_score == -1 || (abs(cs - js) < abs(c_score - j_score)))
    {
        c_score = cs;
        j_score = js;
    }
}

void backt2(int k, int l, long acc_value, long cs)
{
    if (k >= l)
        compute_values(cs, acc_value);
    else
    {
        if (j[k] != '?')
            backt2(k + 1, l, acc_value * 10 + j[k] - '0', cs);
        else
        {
            for (int i = 0; i < 10; i++)
                backt2(k + 1, l, acc_value * 10 + i, cs);
        }
    }
}

void backt(int k, int l, long acc_value)
{
    if (k >= l)
        backt2(0, l, 0, acc_value);
    else
    {
        if (c[k] != '?')
            backt(k + 1, l, acc_value * 10 + c[k] - '0');
        else
        {
            for (int i = 0; i < 10; i++)
                backt(k + 1, l, acc_value * 10 + i);
        }
    }
}

int main()
{
    int ii, t;
    ifstream f("match.in");
    ofstream g("match.out");
    f >> t;
    for (ii = 1; ii <= t; ii++)
    {
        f >> c >> j;
        c_score = -1;
        backt(0, strlen(c), 0);
        g << "Case #" << ii << ": ";
        g << setfill('0') << setw(strlen(c)) << c_score;
        g << " " << setfill('0') << setw(strlen(j)) << j_score;
        g << "\n";
    }
    f.close();
    g.close();
    return 0;
}
