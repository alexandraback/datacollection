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
int gQ[40001];

I64 gCycle;
I64 gGroup;

#define QI  2
#define QJ  3
#define QK  4

int mulQ(int l, int r)
{
    static int gMulTab[][9] = {
    //     -k   -j   -i   -1  0   1     i   j     k
        {  -1, -QI,  QJ,  QK, 0, -QK, -QJ,  QI,   1 }, // -k=-4
        {  QI,  -1, -QK,  QJ, 0, -QJ,  QK,   1, -QI }, // -j=-3
        { -QJ,  QK,  -1,  QI, 0, -QI,   1, -QK,  QJ }, // -i=-2
        {  QK,  QJ,  QI,   1, 0,  -1, -QI, -QJ, -QK }, // -1
        {   0,   0,   0,   0, 0,   0,   0,   0,   0 }, // 0
        { -QK, -QJ, -QI,  -1, 0,   1,  QI,  QJ,  QK }, // 1
        {  QJ, -QK,   1, -QI, 0,  QI,  -1,  QK, -QJ }, // i=2
        { -QI,   1,  QK, -QJ, 0,  QJ, -QK,  -1,  QI }, // j=3
        {   1,  QI, -QJ, -QK, 0,  QK,  QJ, -QI,  -1 }, // k=4
    };
    return gMulTab[l + 4][r + 4];
}

int invQ(int l, int target)
{
    static int gInv[][9] = {
    //     -k   -j   -i   -1  0    1    i    j    k
        {   1, -QI,  QJ,  QK, 0, -QK, -QJ,  QI,  -1 }, // -k
        {  QI,   1, -QK,  QJ, 0, -QJ,  QK,  -1, -QI }, // -j
        { -QJ,  QK,   1,  QI, 0, -QI,  -1, -QK,  QJ }, // -i
        { -QK, -QJ, -QI,   1, 0,  -1,  QI,  QJ,  QK }, // -1
        {   0,   0,   0,   0, 0,   0,   0,   0,   0 }, // 0
        {  QK,  QJ,  QI,  -1, 0,   1, -QI, -QJ, -QK }, // 1
        {  QJ, -QK,  -1, -QI, 0,  QI,   1,  QK, -QJ }, // i
        { -QI,  -1,  QK, -QJ, 0,  QJ, -QK,   1,  QI }, // j
        {  -1,  QI, -QJ, -QK, 0,  QK,  QJ, -QI,   1 }, // k
    };
    return gInv[target + 4][l + 4];
}

int charToQ(int ch)
{
    return ch - 'i' + QI;
}

void makeTable()
{
    gQ[0] = 1;

    int k = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < gL; j++)
        {
            gQ[k + 1] = mulQ(gQ[k], gS[j]);
            k++;
        }
    }
}

void calcCycle()
{
    int x = 1;
    int v = gQ[gL];

    gCycle = 0;
    do
    {
        x = mulQ(x, v);
        gCycle++;
    } while (x != 1);

    gGroup = gCycle * gL;
}

int mulRange(I64 size)
{
    size %= gGroup;

    if (size <= 0)
        return 1;

    return gQ[size];
}

int mulRange(I64 start, I64 size)
{
    return mulQ(-mulRange(start), mulRange(start + size));
}

bool moveNext(I64& pos, int& value, I64 maxN, int target)
{
    int start = pos % gGroup;

    int t = mulQ(mulRange(start), invQ(value, target));

    for (int i = 1; i <= maxN; i++)
    {
        if (++start > gGroup)
            start -= gGroup;

        if (gQ[start] == t)
        {
            pos += i;
            value = target;
            return true;
        }
    }

    pos += maxN;
    value = mulQ(value, mulRange(pos, maxN));

    return false;
}

bool possible()
{
    I64 i, j, k, n = gL * gX;
    I64 start;
    
    start = (gX / gCycle - 2) * gCycle * gL;
    if (start < 0)
        start = 0;

    int iv = 1;
    I64 maxI = min(start + gGroup, n);
    for (i = start; i < maxI; )
    {
        if (!moveNext(i, iv, min(gGroup, maxI - i), QI))
            continue;

        int jv = 1;
        I64 maxJ = min(i + gGroup, n);
        for (j = i; j < maxJ; )
        {
            if (!moveNext(j, jv, min(gGroup, maxJ - j), QJ))
                continue;

            if (mulRange(j, n - j) == QK)
                return true;
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
        calcCycle();

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
