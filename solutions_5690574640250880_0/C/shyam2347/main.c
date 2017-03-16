//
//  main.c
//  MinesweeperMaster
//
//  Created by Shyamsundar Parthasarathy on 4/12/14.
//  Copyright (c) 2014 ___shyam2347___. All rights reserved.
//

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void computeMine(int row, int col, int *arr)
{
    int i;
    int j;
    int count;
    int index;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            index = i*col + j;
            if (arr[index] != -1)
            {
                count = 0;
                index = ((i-1) * col) + (j-1);
                if (i > 0 && j > 0 && arr[index] == -1)
                {
                    count++;
                }
                index = ((i-1) * col) + (j);
                if (i > 0 && arr[index] == -1)
                {
                    count++;
                }
                index = ((i-1) * col) + (j+1);
                if (i > 0 && (j < col-1) && arr[index] == -1)
                {
                    count++;
                }
                index = (i * col) + (j-1);
                if (j>0 && arr[index] == -1)
                {
                    count++;
                }
                index = (i * col) + (j+1);
                if ((j < col-1) && arr[index] == -1)
                {
                    count++;
                }
                index = ((i+1) * col) + (j-1);
                if ((i < row-1) && (j > 0) && arr[index] == -1)
                {
                    count++;
                }
                index = ((i+1) * col) + (j);
                if ((i < row-1) && arr[index] == -1)
                {
                    count++;
                }
                index = ((i+1) * col) + (j+1);
                if ((i < row-1) && (j < col-1) && arr[index] == -1)
                {
                    count++;
                }
                index = i*col + j;
                arr[index] = count;
            }
        }
    }
}

// Return 1 if valid
// 0 - not valid
int checkValid(int row, int col, int *arr, int numFreeCell)
{
    int i;
    int j;
    int index;
    int flag;

    if (numFreeCell == 0)
        return 1;
    else if (numFreeCell == 1)
    {
        index = (row-1)*col + (col-1);
        if (arr[index] != -1)
            return 1;
    }

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            index = i*col + j;
            if (i == row - 1 && j == col-1)
            {
                continue;
            }
            if (arr[index] != -1)
            {
                flag = 0;
                index = ((i-1) * col) + (j-1);
                if (i > 0 && j > 0 && arr[index] == 0)
                {
                    flag++;
                    continue;
                }
                index = ((i-1) * col) + (j);
                if (i > 0 && arr[index] == 0)
                {
                    flag++;
                    continue;
                }
                index = ((i-1) * col) + (j+1);
                if (i > 0 && (j < col-1) && arr[index] == 0)
                {
                    flag++;
                    continue;
                }
                index = (i * col) + (j-1);
                if (j>0 && arr[index] == 0)
                {
                    flag++;
                    continue;
                }
                index = (i * col) + (j+1);
                if ((j < col-1) && arr[index] == 0)
                {
                    flag++;
                    continue;
                }
                index = ((i+1) * col) + (j-1);
                if ((i < row-1) && (j > 0) && arr[index] == 0)
                {
                    flag++;
                    continue;
                }
                index = ((i+1) * col) + (j);
                if ((i < row-1) && arr[index] == 0)
                {
                    flag++;
                    continue;
                }
                index = ((i+1) * col) + (j+1);
                if ((i < row-1) && (j < col-1) && arr[index] == 0)
                {
                    flag++;
                    continue;
                }
                // If I reach here - then I found a discrepancy
                return 0;
            }
        }
    }
    return 1;
}

void compute(int row, int col, int mines, FILE *fpout)
{
    int numFreeCell;
    int i;
    int j;
    int arr[row][col];
    int mineRow = 0;
    int mineCol = 0;
    int nextRow;
    int nextCol;

    // spl case
    if (row == 1 || col == 1)
    {
        if (row == 1)
        {
            for (i = 0; i < col; i++)
            {
                if (mines)
                {
                    mines--;
                    fprintf(fpout, "*");
                }
                else if (i == col-1)
                {
                    fprintf(fpout, "c");
                }
                else
                {
                    fprintf(fpout, ".");
                }
            }
            fprintf(fpout, "\n");
        }
        else
        {
            for (i = 0; i < row; i++)
            {
                if (mines)
                {
                    mines--;
                    fprintf(fpout, "*\n");
                }
                else if (i == row-1)
                {
                    fprintf(fpout, "c\n");
                }
                else
                {
                    fprintf(fpout, ".\n");
                }
            }
        }
        return;
    }
    numFreeCell = (row * col) - mines;

    // Spl Case 2
    if (row == 2 || col == 2)
    {
        if (numFreeCell != 1 && numFreeCell % 2 != 0)
        {
            fprintf(fpout, "Impossible\n");
            return;
        }
    }

    // if numFreeCell != 1 or 4 or 6 or 8 or more
    if (numFreeCell < 8)
    {
        if (numFreeCell != 1 && numFreeCell != 4 && numFreeCell != 6)
        {
            fprintf(fpout, "Impossible\n");
            return;
        }
    }

    // Reaching here, means it is a possible case, draw the mine board
    // Always have C at rowend and colend - free space will be at corner
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (mines)
            {
                mines--;
                arr[i][j] = -1;
                if (j == col-1)
                {
                    mineRow = i+1;
                }
            }
            else
            {
                arr[i][j] = 0;
            }
        }
    }
    
    // Compute Mine
    computeMine(row, col, &arr[0][0]);
    
    // Check for discrepancy. Loop until discrepancy fixed
    while (checkValid(row, col, &arr[0][0], numFreeCell) == 0)
    {
        // Move 1 element from mineRow, mineCol to nextRow, nextCol
        // Compute mineCol
        mineCol = 0;
        while (mineCol == 0)
        {
            for (j = col-1; j >= 0; j--)
            {
                if (arr[mineRow][j] == -1)
                {
                    mineCol = j;
                    break;
                }
            }
            if (mineCol == 0)
                mineRow--;
            if (mineRow < 0)
            {
                printf("Fatal\n");
                exit(1);
            }
        }
        arr[mineRow][mineCol] = 0;
        
        // Compute next row, next Col
        // Row with least mine cols
        int minCol = col;
        int minRow = row;
        for (i = mineRow+1; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                if (j >= minCol)
                {
                    break;
                }
                if (arr[i][j] != -1)
                {
                    if (j < minCol)
                    {
                        minCol = j;
                        minRow = i;
                        break;
                    }
                }
            }
            if (minCol == 0)
            {
                break;
            }
        }
        // Place the mine
        nextCol = minCol;
        nextRow = minRow;
        arr[nextRow][nextCol] = -1;
    
        // Move complete, compute mine again
        computeMine(row, col, &arr[0][0]);
    }

    // Print Answer
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (arr[i][j] == -1)
            {
                fprintf(fpout, "*");
            }
            else if (i == row -1 && j == col - 1)
            {
                fprintf(fpout, "c");
            }
            else
            {
                fprintf(fpout, ".");
            }
        }
        fprintf(fpout, "\n");
    }
}

int main(int argc, const char * argv[])
{
    // Standard variables
    FILE *fp;
    FILE *fpout;
    ssize_t read;
    char *line  = NULL;
    size_t len  = 0;
    
    // Problem variables
    char *str;
    int lineNum = 0;
    int numTestCases = 0;
    int testCaseIndex = 0;
    int row;
    int col;
    int mines;

    
    fp = fopen("/Users/shyam2347/Desktop/C-small-attempt3.in", "r");
    if (NULL == fp)
    {
        printf("File not present\n");
        exit(1);
    }
    fpout = fopen("/Users/shyam2347/Desktop/output.txt", "w");
    if (NULL == fpout)
    {
        printf("File not present\n");
        exit(1);
    }
    while ((read = getline(&line, &len, fp)) != -1)
    {
        if (lineNum++ == 0)
        {
            numTestCases = (int) strtoul(line, NULL, 10);
            continue;
        }
        testCaseIndex++;
        fprintf(fpout, "Case #%d:\n", testCaseIndex);
        str = strtok(line, " ");
        row = (int) strtoul(str, NULL, 10);
        str = strtok(NULL, " ");
        col = (int) strtoul(str, NULL, 10);
        str = strtok(NULL, " ");
        mines = (int) strtoul(str, NULL, 10);
        
        compute(row, col, mines, fpout);

        if (testCaseIndex == numTestCases)
        {
            break;
        }
    }
    fclose(fp);
    fclose(fpout);
    return 0;
}

