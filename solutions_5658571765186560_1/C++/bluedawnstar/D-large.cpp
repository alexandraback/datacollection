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

#define MAX_R 20
#define MAX_C 20

int gX;
int gR;
int gC;

bool gPossible[7][MAX_R + 1][MAX_C + 1] = { false, };

void makeTable1()
{
    bool (*tbl)[MAX_C + 1] = gPossible[1];

    for (int i = 1; i <= MAX_R; i++)
    {
        for (int j = 1; j <= MAX_C; j++)
        {
            tbl[i][j] = true;
        }
    }
}

void makeTable2()
{
    bool (*tbl)[MAX_C + 1] = gPossible[2];

    for (int i = 1; i <= MAX_R; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            bool p = (i * j) % 2 == 0;

            tbl[i][j] = p;
            tbl[j][i] = p;
        }
    }
}

void makeTable3()
{
    bool (*tbl)[MAX_C + 1] = gPossible[3];

    for (int i = 1; i <= MAX_R; i++)
    {
        tbl[i][1] = false;
        tbl[1][i] = false;
    }

    for (int i = 1; i <= MAX_R; i++)
    {
        tbl[2][i] = tbl[i][2] = (i % 3 == 0);
    }

    for (int i = 1; i <= MAX_R; i++)
    {
        tbl[3][i] = tbl[i][3] = (i >= 2);
    }

    bool p;
    for (int i = 4; i <= MAX_R; i++)
    {
        for (int j = 4; j <= i; j++)
        {
            p = (i % 3) == 0 || (j % 3) == 0;

            tbl[i][j] = p;
            tbl[j][i] = p;
        }
    }
}

void makeTable4()
{
    bool (*tbl)[MAX_C + 1] = gPossible[4];

    bool p;
    for (int i = 1; i <= MAX_R; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if ((i * j) % 4 != 0)
                p = false;
            else if (i < 4)
                p = false;
            else if (j < 3)
                p = false;
            else
                p = (i % 4) == 0 || (j % 4) == 0;

            tbl[i][j] = p;
            tbl[j][i] = p;
        }
    }
    // 4x3, 4x4, 
}

void makeTable5()
{
    bool (*tbl)[MAX_C + 1] = gPossible[5];

    bool p;
    for (int i = 1; i <= MAX_R; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if ((i * j) % 5 != 0)
                p = false;
            else if (i < 5)
                p = false;
            else if (j < 4)
                p = false;
            else
                p = (i % 5) == 0 || (j % 5) == 0;

            tbl[i][j] = p;
            tbl[j][i] = p;
        }
    }
}

void makeTable6()
{
    bool (*tbl)[MAX_C + 1] = gPossible[6];

    bool p;
    for (int i = 1; i <= MAX_R; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if ((i * j) % 6 != 0)
                p = false;
            else if (i < 6)
                p = false;
            else if (j < 4)
                p = false;
            else
                p = (i % 6) == 0 || (j % 6) == 0;

            tbl[i][j] = p;
            tbl[j][i] = p;
        }
    }
}

void makeTable()
{
    makeTable1();
    makeTable2();
    makeTable3();
    makeTable4();
    makeTable5();
    makeTable6();
}
    
bool check()
{
    return (gX >= 7) ? false : gPossible[gX][gR][gC];
}

void process(FILE* pfIn, FILE* pfOut)
{
    int i, count;

    makeTable();

    fscanf(pfIn, "%d", &count);
    for (i = 1; i <= count; i++)
    {
        fscanf(pfIn, "%d %d %d", &gX, &gR, &gC); 
        fprintf(pfOut, "Case #%d: %s\n", i, check() ? "GABRIEL" : "RICHARD");
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
