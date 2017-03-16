#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

/**
    TASK: Problem C. Dijkstra
    EVENT: Qualification Round 2015
    COMPETITION: Google Code Jam
**/

const int MAX_LEN = 10000;

int GetKey(char c)
{
    switch (c)
    {
        case '1': return 1;
        case 'i': return 2;
        case 'j': return 3;
        case 'k': return 4;
    }
}

char GetSymbol(int key)
{
    switch (key)
    {
        case 1: return '1';
        case 2: return 'i';
        case 3: return 'j';
        case 4: return 'k';
    }
}

struct Quaternion
{
    int sign, val;
    static Quaternion multiTable[5][5];

    Quaternion()
    {
    }

    Quaternion(int sign, int val) : sign(sign), val(val)
    {
    }

    Quaternion operator* (const Quaternion &other)
    {
        Quaternion q;
        q.val = multiTable[this->val][other.val].val;
        q.sign = multiTable[this->val][other.val].sign * this->sign * other.sign;
        return q;
    }

    void operator*= (const Quaternion &other)
    {
        this->sign = multiTable[this->val][other.val].sign * this->sign * other.sign;
        this->val = multiTable[this->val][other.val].val;
    }

    bool operator!= (const Quaternion &other)
    {
        return this->val != other.val || this->sign != other.sign;
    }

    bool operator== (const Quaternion &other)
    {
        return this->val == other.val && this->sign == other.sign;
    }
};

Quaternion Quaternion::multiTable[5][5] =
{
    {},
    { Quaternion(), Quaternion(1, 1), Quaternion(1, 2), Quaternion(1, 3), Quaternion(1, 4) },
    { Quaternion(), Quaternion(1, 2), Quaternion(-1, 1), Quaternion(1, 4), Quaternion(-1, 3) },
    { Quaternion(), Quaternion(1, 3), Quaternion(-1, 4), Quaternion(-1, 1), Quaternion(1, 2) },
    { Quaternion(), Quaternion(1, 4), Quaternion(1, 3), Quaternion(-1, 2), Quaternion(-1, 1) }
};

int T;
int L;
long long X;
char seq[MAX_LEN + 10];
Quaternion prefix[MAX_LEN + 10], suffix[MAX_LEN + 10];
vector<Quaternion> powers[2][5];
Quaternion one(1, 1), I(1, 2), J(1, 3), K(1, 4);

void PrintQuaternion(Quaternion q)
{
    cout << (q.sign == 1 ? "" : "-") << GetSymbol(q.val);
}

vector<Quaternion> PowerQ(Quaternion q)
{
    //cout << "Calculating: ";
    //PrintQuaternion(q);
    //cout << endl;

    vector<Quaternion> powers;
    powers.push_back(one); // q ^ 0
    //PrintQuaternion(one);
    //cout << endl;

    Quaternion curr = q;
    while (curr != one)
    {
        powers.push_back(curr);
        //PrintQuaternion(curr);
        //cout << endl;
        curr *= q;
    }

    //cout << "----------------" << endl;

    return powers;
}

bool Solve()
{
    prefix[0] = Quaternion(1, 1);
    for (int i = 1; i <= L; i++)
    {
        prefix[i] = prefix[i - 1] * Quaternion(1, GetKey(seq[i - 1]));
    }

    suffix[L] = Quaternion(1, 1);
    for (int i = L - 1; i >= 0; i--)
    {
        suffix[i] = Quaternion(1, GetKey(seq[i])) * suffix[i + 1];
    }

    int s = prefix[L].sign == 1 ? 1 : 0, res = prefix[L].val;
    int sz = powers[s][res].size();

    //cout << sz << endl;

    int maxRepeats = min(4ll, X);

    bool found = false;
    pair<int, int> iIndex;
    for (int i = 0; i < maxRepeats; i++)
    {
        for (int j = 1; j <= L; j++)
        {
            /*printf("Repeat: %d; Position: %d -> Upto: ", i, j);
            PrintQuaternion(powers[s][res][i % sz]);
            printf(" . Curr left: ");
            PrintQuaternion(prefix[j]);
            printf(" / Curr right: ");
            PrintQuaternion(suffix[j]);
            printf(" . ToEnd: ");
            PrintQuaternion(powers[s][res][(maxRequiredRepeats - i - 1) % sz]);
            printf("\n");*/

            if (powers[s][res][i % sz] * prefix[j] == I)
            {
                iIndex = pair<int, int>(i, j);
                found = true;
                break;
            }
        }

        if (found)
        {
            break;
        }
    }

    if (!found)
    {
        return false;
    }

    found = false;
    pair<int, int> kIndex;
    for (int i = 0; i < maxRepeats; i++)
    {
        for (int j = L - 1; j >= 0; j--)
        {
            if (suffix[j] * powers[s][res][i % sz] == K)
            {
                kIndex = pair<int, int>(i, j);
                found = true;
                break;
            }
        }

        if (found)
        {
            break;
        }
    }

    if (!found)
    {
        return false;
    }

    //printf("(%d, %d), (%d, %d)\n", iIndex.first, iIndex.second, kIndex.first, kIndex.second);

    if (iIndex.first * L + iIndex.second >= (X - kIndex.first - 1) * L + kIndex.second)
    {
        return false;
    }

    if (X - kIndex.first - 1 == iIndex.first)
    {
        Quaternion curr = one;
        for (int i = iIndex.second; i < kIndex.second; i++)
        {
            curr *= Quaternion(1, GetKey(seq[i]));
        }

        if (curr == J)
        {
            return true;
        }
    }
    else
    {
        if (suffix[iIndex.second] *  powers[s][res][(X - iIndex.first - kIndex.first - 2) % sz] * prefix[kIndex.second] == J)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    //freopen("C-large.in", "r", stdin);
    //freopen("C-large.out", "w", stdout);

    /*Quaternion q1(-1, GetKey('k'));
    Quaternion q2(1, GetKey('j'));
    q1 *= q2;

    cout << (q1.sign == 1 ? "" : "-") << GetSymbol(q1.val) << endl;*/

    for (int i = 1; i <= 4; i++)
    {
        powers[1][i] = PowerQ(Quaternion(1, i));
        powers[0][i] = PowerQ(Quaternion(-1, i));
    }

    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        scanf("%d %lld", &L, &X);
        scanf("%s", seq);

        printf("Case #%d: %s\n", t, Solve() ? "YES" : "NO");
    }
}


