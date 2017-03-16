
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
    int cases;
    FILE *fp;
    fp=fopen("/Users/IndianaJones/Downloads/C-small-attempt29.in", "r");
    FILE *fpout;
    fpout=fopen("/Users/IndianaJones/Documents/Minesweeper/Minesweeper/output.txt", "w");
    fscanf(fp, "%d\n", &cases);
    for (int i;i<cases;i++)
    {
        int r;
        int c;
        int m;
        fscanf(fp, "%d %d %d\n", &r,&c,&m);
        int originalm = m;
        int numberOfDots = 0;
        char board[r][c];
        for(int ii=0;ii<r;ii++)
        {
            for(int iii=0;iii<c;iii++)
            {
                board[ii][iii] = '?';
            }
        }
        if(r>1)
        {
            board[1][0] = '.';
            numberOfDots++;
            if(c>1)
            {
                board[1][1] = '.';
                numberOfDots++;
                //board[1][1] = 'c';
            }
        }
        board[0][0] = 'c';
        /*if (board[1][1] != 'c')
        {
            board[0][0] = 'c';
        }*/
        if(c>1)
        {
            board[0][1] = '.';
            numberOfDots++;
        }
        int newNumber=r-abs(r-m);
        //while (newNumber>abs(newNumber-abs(r-m))) {
            //newNumber=newNumber-abs(r-m);
        //}
        if(newNumber < 0)
        {
            newNumber = 0-newNumber;
        }
        if(m+1<r)
        {
            newNumber = 0;
        }
        int otherNewNumber=c-abs(c-m);
        //while (otherNewNumber>abs(otherNewNumber-abs(c-m))) {
            //otherNewNumber=otherNewNumber-abs(c-m);
        //}
        if(otherNewNumber < 0)
        {
            otherNewNumber = 0-otherNewNumber;
        }
        if(m+1<c)
        {
            otherNewNumber = 0;
        }
        if((newNumber == 0) || (newNumber!=1 && otherNewNumber !=0))
        {
        for(int n=1;n<10;n++)
        {
            for(int ii=c-n;ii>1;ii--)
            {
                for(int iii=r-1;iii>-1;iii--)
                {
                    if(board[iii][ii] == '?' && m==1 && iii==1)
                    {
                        m = -1;
                    }
                    if(board[iii][ii] == '?' && m>0)
                    {
                        board[iii][ii] = '*';
                        m -= 1;
                    }
                    else if(board[iii][ii] == '?' && m==0)
                    {
                        board[iii][ii] = '.';
                    }
                }
            }
        }
            for(int ii=r-1;ii>-1;ii--)
            {
                for(int iii=c-1;iii>-1;iii--)
                {
                    if(board[ii][iii] == '?' && m==1 && iii==1)
                    {
                        m = -2;
                    }
                    if(board[ii][iii] == '?' && m>0)
                    {
                        board[ii][iii] = '*';
                        m -= 1;
                    }
                    else if(board[ii][iii] == '?' && m==0)
                    {
                        board[ii][iii] = '.';
                    }
                }
            }
        }
        else if(otherNewNumber!=1)
        {
            for(int n=1;n<10;n++)
            {
                for(int ii=r-n;ii>1;ii--)
                {
                    for(int iii=c-1;iii>-1;iii--)
                    {
                        if(board[ii][iii] == '?' && m==1 && iii==1)
                        {
                            m = -3;
                        }
                        if(board[ii][iii] == '?' && m>0)
                        {
                            board[ii][iii] = '*';
                            m -= 1;
                        }
                        else if(board[ii][iii] == '?' && m==0)
                        {
                            board[ii][iii] = '.';
                        }
                    }
                }
            }
                for(int ii=c-1;ii>-1;ii--)
                {
                    for(int iii=r-1;iii>-1;iii--)
                    {
                        if(board[iii][ii] == '?' && m==1 && iii==1)
                        {
                            m = -4;
                        }
                        if(board[iii][ii] == '?' && m>0)
                        {
                            board[iii][ii] = '*';
                            m -= 1;
                        }
                        else if(board[iii][ii] == '?' && m==0)
                        {
                            board[iii][ii] = '.';
                        }
                    }
                }
        }
        else
        {
            for(int n=1;n<10;n++)
            {
                for(int ii=r-n;ii>r-n-1;ii--)
                {
                    for(int iii=c-1;iii>-1;iii--)
                    {
                        if(board[ii][iii] == '?' && m==1 && iii==1)
                        {
                            m = -5;
                        }
                        if(board[ii][iii] == '?' && m>0)
                        {
                            board[ii][iii] = '*';
                            m -= 1;
                        }
                        else if(board[ii][iii] == '?' && m==0)
                        {
                            board[ii][iii] = '.';
                        }
                    }
                }
            for(int ii=c-n;ii>c-n-1;ii--)
            {
                for(int iii=r-1;iii>-1;iii--)
                {
                    if(board[iii][ii] == '?' && m==1 && iii==1)
                    {
                        m = -6;
                    }
                    if(board[iii][ii] == '?' && m>0)
                    {
                        board[iii][ii] = '*';
                        m -= 1;
                    }
                    else if(board[iii][ii] == '?' && m==0)
                    {
                        board[iii][ii] = '.';
                    }
                }
            }
            }
            int newNumber=r-abs(r-m);
            while (newNumber>abs(newNumber-abs(r-m))) {
                newNumber=newNumber-abs(r-m);
            }
            if(newNumber < 0)
            {
                newNumber = 0-newNumber;
            }
            int otherNewNumber=c-abs(c-m);
            while (otherNewNumber>abs(otherNewNumber-abs(c-m))) {
                otherNewNumber=otherNewNumber-abs(c-m);
            }
            if(otherNewNumber < 0)
            {
                otherNewNumber = 0-otherNewNumber;
            }
            if((newNumber == 0) || (newNumber!=1 && otherNewNumber !=0))
            {
                for(int n=1;n<10;n++)
                {
                    for(int ii=c-n;ii>1;ii--)
                    {
                        for(int iii=r-1;iii>-1;iii--)
                        {
                            if(board[iii][ii] == '?' && m==1 && iii==1)
                            {
                                m = -1;
                            }
                            if(board[iii][ii] == '?' && m>0)
                            {
                                board[iii][ii] = '*';
                                m -= 1;
                            }
                            else if(board[iii][ii] == '?' && m==0)
                            {
                                board[iii][ii] = '.';
                            }
                        }
                    }
                }
                for(int ii=r-1;ii>-1;ii--)
                {
                    for(int iii=c-1;iii>-1;iii--)
                    {
                        if(board[ii][iii] == '?' && m==1 && iii==1)
                        {
                            m = -2;
                        }
                        if(board[ii][iii] == '?' && m>0)
                        {
                            board[ii][iii] = '*';
                            m -= 1;
                        }
                        else if(board[ii][iii] == '?' && m==0)
                        {
                            board[ii][iii] = '.';
                        }
                    }
                }
            }
            else if(otherNewNumber!=1)
            {
                for(int n=1;n<10;n++)
                {
                    for(int ii=r-n;ii>1;ii--)
                    {
                        for(int iii=c-1;iii>-1;iii--)
                        {
                            if(board[ii][iii] == '?' && m==1 && iii==1)
                            {
                                m = -3;
                            }
                            if(board[ii][iii] == '?' && m>0)
                            {
                                board[ii][iii] = '*';
                                m -= 1;
                            }
                            else if(board[ii][iii] == '?' && m==0)
                            {
                                board[ii][iii] = '.';
                            }
                        }
                    }
                }
                /*for(int ii=c-1;ii>-1;ii--)
                 {
                 for(int iii=r-1;iii>-1;iii--)
                 {
                 if(board[iii][ii] == '?' && m==1 && iii==1)
                 {
                 m = -4;
                 }
                 if(board[iii][ii] == '?' && m>0)
                 {
                 board[iii][ii] = '*';
                 m -= 1;
                 }
                 else if(board[iii][ii] == '?' && m==0)
                 {
                 board[iii][ii] = '.';
                 }
                 }
                 }*/
            }
        }
        /*else if(c==r)
        {
            for(int n=1;n<6;n++)
            {
                for(int ii=c-(2*n)+1;ii>c-(2*n);ii--)
                {
                    for(int iii=r-1;iii>-1;iii--)
                    {
                        if(board[iii][ii] == '?' && m>0)
                        {
                            board[iii][ii] = '*';
                            m -= 1;
                        }
                        else if(board[iii][ii] == '?' && m==0)
                        {
                            board[iii][ii] = '.';
                        }
                    }
                }
                for(int ii=c-(2*n);ii>c-(2*n)-1;ii--)
                {
                    for(int iii=r-1;iii>-1;iii--)
                    {
                        if(board[iii][ii] == '?' && m>0)
                        {
                            board[iii][ii] = '*';
                            m -= 1;
                        }
                        else if(board[iii][ii] == '?' && m==0)
                        {
                            board[iii][ii] = '.';
                        }
                    }
                }
                for(int ii=r-n;ii>r-n-1;ii--)
                 {
                 for(int iii=c-1;iii>-1;iii--)
                 {
                 if(board[ii][iii] == '?' && m>0)
                 {
                 board[ii][iii] = '*';
                 m -= 1;
                 }
                 else if(board[ii][iii] == '?' && m==0)
                 {
                 board[ii][iii] = '.';
                 }
                 }
                 }
            }
        }*/
        for(int ii=0;ii<r;ii++)
        {
            for(int iii=0;iii<c;iii++)
            {
                if(board[ii][iii] == '?')
                {
                    board[ii][iii] = '.';
                }
            }
        }
        char origBoard[r][c];
        for(int ii=0;ii<r;ii++)
        {
            for(int iii=0;iii<c;iii++)
            {
                origBoard[ii][iii] = board[ii][iii];
            }
        }
        for(int ii=0;ii<r;ii++)
        {
            for(int iii=0;iii<c;iii++)
            {
                if(board[ii][iii] == '.')
                {
                    int minesAround = 0;
                    if(board[ii-1][iii-1] == '*' && ii-1>-1 && iii-1>-1)
                    {
                        minesAround++;
                    }
                    if(board[ii-1][iii] == '*' && ii-1>-1)
                    {
                        minesAround++;
                    }
                    if(board[ii-1][iii+1] == '*' && ii-1>-1 && iii+1<c)
                    {
                        minesAround++;
                    }
                    if(board[ii+1][iii-1] == '*' && ii+1<r && iii-1>-1)
                    {
                        minesAround++;
                    }
                    if(board[ii+1][iii] == '*' && ii+1<r)
                    {
                        minesAround++;
                    }
                    if(board[ii+1][iii+1] == '*' && ii+1<r && iii+1<c)
                    {
                        minesAround++;
                    }
                    if(board[ii][iii+1] == '*' && iii+1<c)
                    {
                        minesAround++;
                    }
                    if(board[ii][iii-1] == '*' && iii-1>-1)
                    {
                        minesAround++;
                    }
                    board[ii][iii] = (char)(((int)'0')+minesAround);
                }
            }
        }
        int error = 0;
        int lol = 0;
        for(int ii=0;ii<r;ii++)
        {
            for(int iii=0;iii<c;iii++)
            {
                if(board[ii][iii] != 'c' && board[ii][iii] != '*')
                {
                    int minesAround = 0;
                    if(board[ii-1][iii-1] == '0' && ii-1>-1 && iii-1>-1)
                    {
                        minesAround++;
                    }
                    if(board[ii-1][iii] == '0' && ii-1>-1)
                    {
                        minesAround++;
                    }
                    if(board[ii-1][iii+1] == '0' && ii-1>-1 && iii+1<c)
                    {
                        minesAround++;
                    }
                    if(board[ii+1][iii-1] == '0' && ii+1<r && iii-1>-1)
                    {
                        minesAround++;
                    }
                    if(board[ii+1][iii] == '0' && ii+1<r)
                    {
                        minesAround++;
                    }
                    if(board[ii+1][iii+1] == '0' && ii+1<r && iii+1<c)
                    {
                        minesAround++;
                    }
                    if(board[ii][iii+1] == '0' && iii+1<c)
                    {
                        minesAround++;
                    }
                    if(board[ii][iii-1] == '0' && iii-1>-1)
                    {
                        minesAround++;
                    }
                    error = minesAround;
                    lol++;
                }
            }
        }
        if(lol==0)
        {
            error=1;
        }
        //fprintf(fpout, "\n");
        if(error == 0 && r!=1 && c!=1 && !(board[0][0]=='c' && board[1][0]=='2' && board[0][1]=='2' && board[1][1] == '5'))
        {
            m=-10;
            //fprintf(fpout, "Error\n");
        }
        for(int ii=0;ii<r;ii++)
        {
            for(int iii=0;iii<c;iii++)
            {
                //fprintf(fpout, "%c",board[ii][iii]);
            }
            //fprintf(fpout, "\n");
        }
        if(m == numberOfDots)
        {
            if(r>1)
            {
                origBoard[1][0] = '*';
                if(c>1)
                {
                    origBoard[1][1] = '*';
                    numberOfDots++;
                    //board[1][1] = 'c';
                }
            }
            if(c>1)
            {
                origBoard[0][1] = '*';
            }
            fprintf(fpout, "Case #%d:\n",i+1);
            for(int ii=0;ii<r;ii++)
            {
                for(int iii=0;iii<c;iii++)
                {
                    fprintf(fpout, "%c",origBoard[ii][iii]);
                }
                fprintf(fpout, "\n");
            }
        }
        else if(m!=0)
        {
            fprintf(fpout, "Case #%d:\n",i+1);
            fprintf(fpout, "Impossible\n");
            /*fprintf(fpout, "%d %d %d\n", r,c,originalm);
            for(int ii=0;ii<r;ii++)
            {
                for(int iii=0;iii<c;iii++)
                {
                    fprintf(fpout, "%c",board[ii][iii]);
                }
                fprintf(fpout, "\n");
            }*/
        }
        else
        {
            fprintf(fpout, "Case #%d:\n",i+1);
            for(int ii=0;ii<r;ii++)
            {
                for(int iii=0;iii<c;iii++)
                {
                    fprintf(fpout, "%c",origBoard[ii][iii]);
                }
                fprintf(fpout, "\n");
            }
        }
    }
    fclose(fp);
    fclose(fpout);
    return 0;
}

