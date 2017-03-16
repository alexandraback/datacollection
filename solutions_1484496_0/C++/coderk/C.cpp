// code jam round 1b
//problem C

#include <iostream>
#include <cstdio>
using namespace std;

const int MAXS = (1 << 21), MAXN = 55;

long long sum[MAXS], indx[MAXS], element[MAXN];
long long temp1[MAXS], temp2[MAXS];
int n, cnt, testcase;

void gen(long long state, long long s, int pos)
{
    if (pos >= n)
    {
        cnt++;
        sum[cnt] = s, indx[cnt] = state;
        return;
    }
    gen(state, s, pos + 1);
    gen((state | (1 << pos)), s + element[pos + 1], pos + 1);
}

void qs(int l, int r)
{
    if (l >= r)
        return;
    int mid = ((l + r) >> 1);
    int i = l, j = mid + 1, account = 0;
    qs(l, mid);
    qs(mid + 1, r);
    while (i <= mid || j <= r)
        if (j > r || i <= mid && sum[i] < sum[j])
        {
            account++;
            temp1[account] = sum[i], temp2[account] = indx[i];
            i++;
        }
        else
        {
            account++;
            temp1[account] = sum[j], temp2[account] = indx[j];
            j++;
        }
    for (i = l; i <= r; i++)
        sum[i] = temp1[i - l + 1], indx[i] = temp2[i - l + 1];
}

int main()
{
    FILE *fin = fopen("c.in", "r");
    FILE *fout = fopen("c.out", "w");
    fscanf(fin, "%d", &testcase);
    for (int test = 1; test <= testcase; test++)
    {
        fprintf(fout, "Case #%d:\n", test);
        fscanf(fin, "%d", &n);
        for (int i = 1; i <= n; i++)
            fscanf(fin, "%lld", &(element[i]));
        cnt = 0;
        gen(0, 0, 0);
        qs(1, cnt);
        bool found = false, first;
        for (int i = 2; !found && i <= cnt; i++)
            if (sum[i] == sum[i - 1])
            {
                long long temp = (indx[i] & indx[i - 1]);
                long long a = indx[i] - temp, b = indx[i - 1] - temp;
                found = true;
                first = true;
                for (int j = 1; j <= n; j++)
                    if (((1 << (j - 1)) & a) != 0)
                    {
                        if (!first)
                            fprintf(fout, " ");
                        fprintf(fout, "%lld", element[j]);
                        first = false;
                    }
                fprintf(fout, "\n");
                first = true;
                for (int j = 1; j <= n; j++)
                    if (((1 << (j - 1)) & b) != 0)
                    {
                        if (!first)
                            fprintf(fout, " ");
                        fprintf(fout, "%lld", element[j]);
                        first = false;
                    }
                fprintf(fout, "\n");
            }
            if (!found)
                fprintf(fout, "Impossible\n");
    }
    fclose(fout);
    fclose(fin);
    return 0;
}
