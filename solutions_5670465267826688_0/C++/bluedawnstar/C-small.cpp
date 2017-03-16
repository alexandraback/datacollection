#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

#define IT                  iterator
#define VEC(T)              vector<T >
#define VIT(T)              vector<T >::IT

typedef long long           I64;
typedef unsigned long long  UI64;

using namespace std;

int gL;
I64 gX;
char gS[20000];
int gQ[10001][10001];

I64 gCycle;

#define QI  2
#define QJ  3
#define QK  4

int gMulTab[][5] = {
    { 0,  0,   0,   0,   0 },
    { 0,  1,  QI,  QJ,  QK },
    { 0, QI,  -1,  QK, -QJ },
    { 0, QJ, -QK,  -1,  QI },
    { 0, QK,  QJ, -QI,  -1 },
};

int gInv[][5] = {
    //    1    i    j    k
    { 0,  0,   0,   0,   0 },
    { 0,  1, -QI, -QJ, -QK }, // 1
    { 0, QI,   1,  QK, -QJ }, // i
    { 0, QJ, -QK,   1,  QI }, // j
    { 0, QK,  QJ, -QI,   1 }, // k
};

int mulQ(int l, int r)
{
    int aL = abs(l);
    int aR = abs(r);
    int res = gMulTab[aL][aR];

    if ((l < 0) != (r < 0))
        res = -res;

    return res;
}

int charToQ(int ch)
{
    return ch - 'i' + QI;
}

I64 calcCycle()
{
    int x = 1;

    for (I64 i = 0; i < gX; i++)
    {
        for (int j = 0; j < gL; j++)
            x = mulQ(x, gS[j]);

        if (x == 1)
            return i + 1;
    }

    return 0;
}

void makeTable()
{
    gQ[0][0] = 1;

    for (int i = 0; i < gL; i++)
        gQ[0][i + 1] = mulQ(gQ[0][i], gS[i]);

    for (int i = 1; i < gL; i++)
    {
        for (int j = 0; j < gL; j++)
            gQ[i][j] = mulQ(-gS[i - 1], gQ[i - 1][j + 1]);
        gQ[i][gL] = mulQ(gQ[i][gL - 1], gS[i - 1]);
    }
}

void moveNext(I64& pos, int& value, I64 maxN, int target)
{
    int x = abs(value);
    int start = pos % gL;

    int t = gInv[target][x];
    if (value < 0)
        t = -t;

    for (int i = 1; i < maxN; i++)
    {
        if (gQ[start][i] == t)
        {
            pos += i;
            value = target;
            return;
        }
    }

    pos += maxN;
    value = mulQ(value, gQ[start][maxN]);
}

bool possible()
{
    I64 i, j, k, n = gL * gX;

    I64 start = 0, maxL = n;
    
    if (gCycle > 0)
    {
        start = (gX / gCycle - 2) * gCycle * gL;
        if (start < 0)
            start = 0;

        maxL = gCycle * gL;
    }

    int iv = 1;
    I64 maxI = min(start + maxL, n);
    for (i = start; i < maxI; )
    {
        moveNext(i, iv, min((I64)gL, maxI - i), QI);
        //iv = mulQ(iv, gS[i % gL]);
        if (iv == QI)
        {
            int jv = 1;
            I64 maxJ = min(i + maxL, n);
            for (j = i; j < maxJ; )
            {
                moveNext(j, jv, min((I64)gL, maxJ - j), QJ);
                //jv = mulQ(jv, gS[j % gL]);
                if (jv == QJ)
                {
                    int kv = 1;
                    for (k = j; k < n; )
                    {
                        moveNext(k, kv, min((I64)gL, n - k), QK);
                        //kv = mulQ(kv, gS[k % gL]);
                    }
                    if (k == n && kv == QK)
                        return true;
                }
            }
        }
    }

    return false;
}

void process(FILE* pfIn, FILE* pfOut)
{
    int i, count;

    fscanf(pfIn, "%d", &count);
    for (i = 1; i <= count; i++)
    {
        fscanf(pfIn, "%d %lld", &gL, &gX);
        fscanf(pfIn, "%s", gS);

        for (int i = 0; gS[i]; i++)
            gS[i] = charToQ(gS[i]);

        makeTable();
        gCycle = calcCycle();

        //printf("Case #%d: L=%d, X=%lld, cycle=%lld\n", i, gL, gX, gCycle);

        fprintf(pfOut, "Case #%d: %s\n", i, possible() ? "YES" : "NO");
    }
}

//-----------------------------------------------------------------------------

void process(const char* pcszInFile, const char* pcszOutFile)
{
    FILE* pfIn = fopen(pcszInFile, "rt");
    if (pfIn == NULL)
    {
        printf("file not found! \"%s\"\n", pcszInFile);
        exit(-2);
    }

    FILE* pfOut = fopen(pcszOutFile, "wt");
    if (pfOut == NULL)
    {
        printf("can't create file! \"%s\"\n", pcszOutFile);
        exit(-3);
    }

    process(pfIn, pfOut);

    fclose(pfIn);
    fclose(pfOut);
}

void main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("Usage : %s <input_file> <output_file>\n", argv[0]);
        exit(-1);
    }

    process(argv[1], argv[2]);
}
