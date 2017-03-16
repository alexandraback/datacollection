#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

ifstream fin("test.in");
ofstream fout("test.out");

int n;
long long x;
char s[40010];

int op[4][4] = {0, 1, 2, 3,
                   1, 0, 3, 2,
                   2, 3, 0, 1,
                   3, 2, 1, 0 };
int opsgn[4][4] = {0, 0, 0, 0,
                       0, 1, 0, 1,
                       0, 1, 1, 0,
                       0, 0, 1, 1};
int revop1[4][4], revop2[4][4];

struct quaternion
{
    int sgn, x;

    quaternion(int newx = 0, int newsgn = 0)
    {
        x = newx;
        sgn = newsgn;
    }
};

quaternion operator * (quaternion a, quaternion b)
{
    quaternion ans;
    ans.sgn = a.sgn ^ b.sgn ^ opsgn[a.x][b.x];
    ans.x = op[a.x][b.x];
    return ans;
}

quaternion right_inverse (quaternion a, quaternion ans)
{
    quaternion b;
    b.x = revop1[a.x][ans.x];
    b.sgn = a.sgn ^ ans.sgn ^ opsgn[a.x][b.x];
    return b;
}

quaternion left_inverse (quaternion b, quaternion ans)
{
    quaternion a;
    a.x = revop2[b.x][ans.x];
    a.sgn = b.sgn ^ ans.sgn ^ opsgn[a.x][b.x];
    return a;
}

int interpret(char c)
{
    if (c == 'i')
        return 1;
    else if (c == 'j')
        return 2;
    else if (c == 'k')
        return 3;
}

void verdict (string s, int t)
{
    fout << "Case #" << t << ": " << s << "\n";
}

void mirror (char s[], int nr)
{
    for (int i = n; i < nr*n; ++i)
    {
        s[i] = s[i-n];
    }
    s[nr*n] = '\0';
}

void solve(int test)
{
    fin >> n >> x >> s;

    int count;

    if (x >= 4)
    {
        mirror(s, 4);
        count = 4;
    }
    else
    {
        mirror(s, x);
        count = x;
    }

    quaternion left;
    quaternion right;
    quaternion total;
    quaternion temp;

    for (int i = 0; i < n; ++i)
    {
        quaternion c(interpret(s[i]), 0);
        temp = temp * c;
    }

    int nr = x % 4;
    if (nr == 0)
        nr = 4;
    for (int i = 0; i < nr; ++i)
    {
        total = total * temp;
    }

    int pleft = -1;
    int pright = count*n;

    for (pleft = 0; pleft < count*n; ++pleft)
    {
        quaternion c(interpret(s[pleft]), 0);
        left = left * c;

        if (left.x == 1 && left.sgn == 0)
            break;
    }

    for (pright = count*n-1; pright >= 0; --pright)
    {
        quaternion c (interpret(s[pright]), 0);
        right = c * right;

        if (right.x == 3 && right.sgn == 0)
            break;
    }

    if (pleft < count*n && pright > -1 && pleft + 1 + count*n - pright < n*x)
    {
        quaternion d;
        d = right_inverse(left,total);
        d = left_inverse(right, d);
        if (d.x == 2 && d.sgn == 0)
        {
            verdict("YES", test);
        }
        else verdict("NO", test);
    }
    else
    {
        verdict("NO", test);
    }
}

int main()
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            revop1[i][op[i][j]] = j;
            revop2[j][op[i][j]] = i;
        }
    }

    int test;
    fin >> test;

    for(int k = 1; k <= test; ++k)
    {
        solve(k);
    }
}
