#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

char g_achOutBuff[100 * 100];

#define CELL(r,c)   g_achOutBuff[(r) * (col+1) + (c)] 

void initOutBuff(int row, int col)
{
    int i, j;
    char* p;

    p = g_achOutBuff;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            *p++ = '*';
        *p++ = '\n';
    }
    *p++ = '\0';
}

void showSolution(FILE* pfOut, int row, int col, int mines)
{
    bool ok;
    int i, j, n, fillRow, noMines;

    initOutBuff(row, col);

    noMines = row * col - mines;

    ok = false;
    if (row == 1 || col == 1)
    {
        if (row == 1)
        {
            char* p = &CELL(0, 0);
            for (i = 0; i < noMines; i++)
                *p++ = '.';
        }
        else if (col == 1)
        {
            char* p = &CELL(0, 0);
            for (i = 0; i < noMines; i++)
            {
                *p = '.';
                p += col + 1;
            }
        }

        CELL(0, 0) = 'c';
        ok = true;
    }
    else if (noMines == 1)
    {
        CELL(0, 0) = 'c';
        ok = true;
    }
    else if ((noMines & 1) == 0)
    { // even
        if (noMines >= 4 && row >= 2 && col >= 2)
        {
            char *p1, *p2;

            // first 2 x 2 cells
            p1 = &CELL(0, 0);
            p2 = &CELL(1, 0);
            for (i = 0; i < 2; i++)
            {
                *p1++ = '.';
                *p2++ = '.';
            }
            noMines -= 4;

            // first 2 rows
            if (noMines >= 2 && col > 2)
            {
                n = min(noMines >> 1, col-2);
                p1 = &CELL(0, 2);
                p2 = &CELL(1, 2);
                for (i = 0; i < n; i++)
                {
                    *p1++ = '.';
                    *p2++ = '.';
                }
                noMines -= 2 * n;
            }

            // first 2 cols
            if (noMines >= 2 && row > 2)
            {
                n = min(noMines >> 1, row-2);
                p1 = &CELL(2, 0);
                for (i = 0; i < n; i++)
                {
                    *p1++ = '.';
                    *p1 = '.';
                    p1 += col;
                }
                noMines -= 2 * n;
            }

            if (noMines > 0)
            {
                fillRow = 2;

                n = noMines / (col - 2);
                for (i = 0; i < n; i++)
                {
                    p1 = &CELL(fillRow, 2);
                    for (j = 2; j < col; j++)
                        *p1++ = '.';
                    fillRow++;
                }
                noMines -= (col - 2) * n;

                p1 = &CELL(fillRow, 2);
                for (i = 0; i < noMines; i++)
                    *p1++ = '.';
            }

            CELL(0,0) = 'c';

            ok = true;
        }
    }
    else
    { // odd
        if (noMines >= 9 && row >= 3 && col >= 3)
        {
            char *p1, *p2, *p3;

            // first 3 x 3 cells
            p1 = &CELL(0, 0);
            p2 = &CELL(1, 0);
            p3 = &CELL(2, 0);
            for (i = 0; i < 3; i++)
            {
                *p1++ = '.';
                *p2++ = '.';
                *p3++ = '.';
            }
            noMines -= 9;

            // first 2 rows
            if (noMines >= 2)
            {
                n = min(noMines >> 1, col-3);
                p1 = &CELL(0, 3);
                p2 = &CELL(1, 3);
                for (i = 0; i < n; i++)
                {
                    *p1++ = '.';
                    *p2++ = '.';
                }
                noMines -= 2 * n;
            }

            // first 2 cols
            if (noMines >= 2)
            {
                n = min(noMines >> 1, row-3);
                p1 = &CELL(3, 0);
                for (i = 0; i < n; i++)
                {
                    *p1++ = '.';
                    *p1 = '.';
                    p1 += col;
                }
                noMines -= 2 * n;
            }

            if (noMines > 0)
            {
                noMines++;

                fillRow = 2;

                n = noMines / (col - 2);
                for (i = 0; i < n; i++)
                {
                    p1 = &CELL(fillRow, 2);
                    for (j = 2; j < col; j++)
                        *p1++ = '.';
                    fillRow++;
                }
                noMines -= (col - 2) * n;

                p1 = &CELL(fillRow, 2);
                for (i = 0; i < noMines; i++)
                    *p1++ = '.';
            }

            CELL(0,0) = 'c';

            ok = true;
        }
    }

    fprintf(pfOut, "%s", ok ? g_achOutBuff : "Impossible\n");
}

void process(FILE* pfIn, FILE* pfOut)
{
    int i, count;
    int row, col, mines;

    fscanf(pfIn, "%d", &count);
    for (i = 1; i <= count; i++)
    {
        fscanf(pfIn, "%d %d %d", &row, &col, &mines);

        fprintf(pfOut, "Case #%d:\n", i);
        showSolution(pfOut, row, col, mines);
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
