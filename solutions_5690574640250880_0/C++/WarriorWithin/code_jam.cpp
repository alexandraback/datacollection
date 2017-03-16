#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#include <math.h>

using namespace std;

int main()
{
    FILE *ptr = fopen("C-small-attempt1.in", "r");
    //FILE *ptr = fopen("input.txt", "r");
    int i, t, startr, startc, leftc, rightc, upr, downr, num, r, c, m, j, k;
    fscanf(ptr, "%d", &t);

    for(i=1; i<=t; i++)
    {
        int flag = 0;
        fscanf(ptr, "%d %d %d", &r, &c, &m);
        char board[r][c];

        for(j=0; j<r; j++)
            for(k=0; k<c; k++)
                board[j][k] = '*';

        int num = (r*c)-m;

        if(m==0)
        {
            for(j=0; j<r; j++)
                for(k=0; k<c; k++)
                    board[j][k] = '.';
            board[0][0] = 'c';
        }
        else if(num==1)
        {
            board[0][0] = 'c';
        }
        else if(r==1 || c==1)
        {
            board[0][0] = 'c';
            if(r==1)
                for(j=1; j<num; j++)
                    board[0][j] = '.';
            else
                for(j=1; j<num; j++)
                    board[j][0] = '.';
        }
        else if(num<4)
            flag = 1;
        else if(num==4)
        {
            board[0][0] = 'c';
            board[1][0] = board[0][1] = board[1][1] = '.';
        }
        else if(num<=9)
        {
            board[0][0] = 'c';
            downr = 0;
            leftc = 0;
            int temp = 1;
            while(temp<num)
            {
                downr++; leftc++;
                if(downr<r)
                {
                    for(j=downr, k=0; k<leftc && k<c && temp<num; k++)
                    {
                        board[j][k] = '.';
                        temp++;
                    }
                }

                if(leftc<c)
                {
                    if(downr<r)
                    {
                        for(j=leftc, k=downr; k>=0 && temp<num; k--)
                        {
                            board[k][j] = '.';
                            temp++;
                        }
                    }
                    else
                    {
                        for(j=leftc, k=c-1; k>=0 && temp<num; k--)
                        {
                            board[k][j] = '.';
                            temp++;
                        }
                    }
                }
            }
        }
        else
        {
            if(r%2==0)
                startr = (r-1)/2;
            else
                startr = r/2;

            if(c%2==0)
                startc = (c-1)/2;
            else
                startc = c/2;

            board[startr][startc] = 'c';
            num--;
            upr = startr;
            downr = startr;
            leftc = startc;
            rightc = startc;
            while(num)
            {
                leftc--; upr--;
                rightc++; downr++;

                if(leftc>=0)
                {
                    if(upr>=0)
                    {
                        for(j=leftc, k=upr; k<downr && k<r && num>0; k++)
                        {
                            board[k][j] = '.';
                            num--;
                        }
                    }
                    else
                    {
                        for(j=leftc, k=0; k<downr && k<r && num>0; k++)
                        {
                            board[k][j] = '.';
                            num--;
                        }
                    }

                }

                if(downr<r)
                {
                    if(leftc>=0)
                    {
                        for(j=downr, k=leftc; k<rightc && k<c && num>0; k++)
                        {
                            board[j][k] = '.';
                            num--;
                        }
                    }
                    else
                    {
                        for(j=downr, k=0; k<rightc && k<c && num>0; k++)
                        {
                            board[j][k] = '.';
                            num--;
                        }
                    }
                }

                if(rightc<c)
                {
                    if(downr<r)
                    {
                        for(j=rightc, k=downr; k>0 && k>upr && num>0; k--)
                        {
                            board[k][j] = '.';
                            num--;
                        }
                    }
                    else
                    {
                        for(j=rightc, k=r-1; k>0 && k>upr && num>0; k--)
                        {
                            board[k][j] = '.';
                            num--;
                        }
                    }
                }

                if(upr>=0)
                {
                    if(rightc<c)
                    {
                        for(j=upr, k=rightc; k>leftc && k>0 && num>0; k--)
                        {
                            board[j][k] = '.';
                            num--;
                        }
                    }
                    else
                    {
                        for(j=upr, k=c-1; k>leftc && k>0 && num>0; k--)
                        {
                            board[j][k] = '.';
                            num--;
                        }
                    }
                }
            }
        }

        cout<<"Case #"<<i<<":\n";
        if(flag)
            cout<<"Impossible\n";
        else
        {
            for(j=0; j<r; j++)
            {
                for(k=0; k<c; k++)
                    cout<<board[j][k];
                cout<<endl;
            }
        }
    }
    fclose(ptr);
    return 0;
}
