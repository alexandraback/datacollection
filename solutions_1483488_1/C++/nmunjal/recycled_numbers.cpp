#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>
using namespace std;


FILE *in = stdin;
FILE *out = stdout;

int getith(int index, int n, int len)
{
    n = n % (int)pow(10, index + 1);
    n = n / pow(10, index);
    return n;
}

bool myfunction (int i,int j) { return (i<j); }

void check_vector(vector <int>*v)
{
    int i;
    int tmp = 0;
}
    

int check_old(int A, int B, int n)
{
    int i, j, k = 0, index, count = 0;
    char tmp[10];
    int foo = 0;
    int perm;
    vector <int> v;
    vector<int>::iterator it;
    int len = (int)floor(log10(n)) + 1;
    if (len == 1)
        return 0;
    // 1 2 3 4 (number)
    // 3 2 1 0 (indexes)
    for (i = len - 2; i >= 0; i--)
    {
        k = 0;
        for (j = len; j > 0; j--)
        {
            index = (j + i)%len;
            sprintf(tmp + k, "%d", getith(index, n, len));
            sprintf(tmp + k + 1, "%c", '\0');
            k++;
        }
        perm = atoi(tmp);
        if (perm > n && perm <= B)
        {
            cout << "(n, m) = (" << n << ", " << perm << ")\n";
            count++;
            v.push_back(perm);
        }
    }
    sort(v.begin(), v.end(), myfunction);
    foo = 0;
    for (it=v.begin(); it<v.end(); it++)
    {
        if (*it == foo)
            cout << "Bingo" << *it << "\n";
        foo = *it;
    }
    return count;
}

int check(int A, int B, int n)
{
    int i, j, k = 0, index, count = 0;
    char tmp[10];
    int perm;
    int len = (int)floor(log10(n)) + 1;
    set <int>myset;
    if (len == 1)
        return 0;
    // 1 2 3 4 (number)
    // 3 2 1 0 (indexes)
    for (i = len - 2; i >= 0; i--)
    {
        k = 0;
        for (j = len; j > 0; j--)
        {
            index = (j + i)%len;
            sprintf(tmp + k, "%d", getith(index, n, len));
            sprintf(tmp + k + 1, "%c", '\0');
            k++;
        }
        perm = atoi(tmp);
        if (perm > n && perm <= B)
        {
            // cout << "(n, m) = (" << n << ", " << perm << ")\n";
            count++;
            myset.insert(perm);
        }
    }
    return myset.size();
}

void compute(int A, int B, int num)
{
    int result = 0, i;
    for (i = A; i <= B; i++)
    {
        result += check(A, B, i);
    }
    fprintf(out, "Case #%d: %d\n", num, result);
    // cout << "Case #" << num << ": " << result << "\n";
}

int main(int argc, char **argv)
{
    int T, A, B, i;
    multimap<int, int>::iterator it;
    in = fopen("input", "r");
    in = fopen("C-small-attempt0.in", "r");
    in = fopen("C-large.in", "r");
    out = fopen("Result", "w+");
    fscanf(in, "%d", &T);
    for (i = 1; i <= T; i++)
    {
        fscanf(in, "%d", &A);
        fscanf(in, "%d", &B);
        compute(A, B, i);
    }
    // check (A, B, atoi(argv[1]));
    // for (it = m.begin(); it != m.end(); it++)
       // cout << (*it).first << " => " << (*it).second << endl;
    return 0;
}
