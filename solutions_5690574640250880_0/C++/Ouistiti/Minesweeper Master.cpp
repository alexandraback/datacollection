#include <cstdio>

int r,c,m;
char ans[6][6];

void print ()
{
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c;j++)
            printf ("%c",ans[i][j]);
        printf ("\n");
    }
}

void solve (int k)
{
    if (k==1)
    {
        for (int i=0;i<m;i++)
            ans[0][i] = '.';
        ans[0][0] = 'c';
    }
    else if (k==2)
    {
        for (int i=0;i<m;i++)
            ans[i][0] = '.';
        ans[0][0] = 'c';
    }
    else if (k==4) ans[0][0] = 'c';
    else if (k==5)
    {
        ans[0][0] = 'c';
        ans[0][1] = '.';
        ans[1][1] = '.';
        ans[1][0] = '.';
        if (m>=6&&r==2)
        {
            ans[0][2] = '.';
            ans[1][2] = '.';
        }
        else if (m>=6)
        {
            ans[2][0] = '.';
            ans[2][1] = '.';
        }
        if (m==8&&r==2)
        {
            ans[0][3] = '.';
            ans[1][3] = '.';
        }
        else if (m==8)
        {
            ans[3][0] = '.';
            ans[3][1] = '.';
            if (r*c==9)
            {
                ans[1][2] = '.';
                ans[0][2] = '.';
            }
        }
    }
    else if (k==6)
    {
        if (r==2&&c==5) k=3;
        if (r==5&&c==2) k=3;
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                ans[i][j] = '.';
        ans[1][1] = 'c';
    }
    else if (k==12)
    {
        if (r==3)
        {
            for (int i=0;i<3;i++)
                for (int j=0;j<4;j++)
                    ans[i][j] = '.';
            ans[0][2] = 'c';
            if (m++<12) ans[2][3] = '*';
            if (m++<12) ans[2][2] = '*';
        }
        else
        {
            for (int i=0;i<4;i++)
                for (int j=0;j<3;j++)
                    ans[i][j] = '.';
            ans[2][0] = 'c';
            if (m++<12) ans[3][2] = '*';
            if (m++<12) ans[2][2] = '*';
        }
        //if (c>=4&&r>=4)
            //for (int i=0;i<4;i++)
                //ans[3][i] = '*';
        if (r==2&&c==5||r==5&&c==2)
        {
            for (int i=0;i<r;i++)
                for (int j=0;j<c;j++)
                    ans[i][j] = '.';
            ans[0][0] = 'c';
        }
    }
    else if (k==7)
    {
        if (c==3&&r==5)
        {
            for (int i=0;i<5;i++)
                for (int j=0;j<3;j++)
                    ans[i][j] = '.';
            ans[2][1] = 'c';
            ans[0][0] = '*';
            ans[4][2] = '*';
        }
        else if (c==5&&r==3)
        {
            for (int i=0;i<3;i++)
                for (int j=0;j<5;j++)
                    ans[i][j] = '.';
            ans[1][2] = 'c';
            ans[0][0] = '*';
            ans[2][4] = '*';
        }
        else
        {
            for (int i=0;i<4;i++)
                for (int j=0;j<4;j++)
                    ans[i][j] = '.';
            ans[1][1] = 'c';
            ans[3][3] = '*';
            ans[3][2] = '*';
            ans[2][3] = '*';
        }
    }
    else if (k==8)
    {
        if (r==5&&c==3)
        {
            for (int i=0;i<r;i++)
                for (int j=0;j<c;j++)
                    ans[i][j] = '.';
            ans[2][1] = 'c';
            if (m==14) ans[0][0] = '*';
        }
        else if (r==3&&c==5)
        {
            for (int i=0;i<r;i++)
                for (int j=0;j<c;j++)
                    ans[i][j] = '.';
            ans[1][2] = 'c';
            if (m==14) ans[0][0] = '*';
        }
        else
        {
            for (int i=0;i<4;i++)
                for (int j=0;j<4;j++)
                    ans[i][j] = '.';
            ans[1][2] = 'c';
            if (m++<16) ans[0][0] = '*';
            if (m++<16) ans[3][3] = '*';
        }   
    }
    else if (k==9)
    {
        for (int i=0;i<4;i++)
            for (int j=0;j<4;j++)
                ans[i][j] = '.';
        ans[1][1] = 'c';
    }
    else if (k==10)
    {
        for (int i=0;i<5;i++)
            for (int j=0;j<5;j++)
                ans[i][j] = '.';
        ans[1][1] = 'c';
        if (c==4)
        {
            if (m++<20) ans[4][3] = '*';
            if (m++<20) ans[3][3] = '*';
            if (m++<20) ans[2][3] = '*';
        }
        else
        {
            if (m++<20) ans[3][4] = '*';
            if (m++<20) ans[3][3] = '*';
            if (m++<20) ans[3][2] = '*';
        }
        if (c+r==10)
            for (int i=0;i<5;i++)
                ans[4][i] = '*';
    }
    else if (k==11)
    {
        for (int i=0;i<5;i++)
            for (int j=0;j<5;j++)
                ans [i][j] = '.';
        ans[2][2] = 'c';
        if (m++<25) ans[0][0] = '*';
        if (m++<25) ans[0][4] = '*';
        if (m++<25) ans[4][0] = '*';
        if (m++<25) ans[4][4] = '*';
    }
    if (k!=3) print ();
    else printf ("Impossible\n");
}

int main ()
{
    freopen ("Minesweeper Master11.in","r",stdin);
    freopen ("Minesweeper Master11.out","w",stdout);
    int t;
    scanf ("%d",&t);
    for (int g=1;g<=t;g++)
    {
        int k=0;
        scanf ("%d %d %d",&r,&c,&m);
        m = r*c-m;
        for (int i=0;i<5;i++)
            for (int j=0;j<5;j++)
                ans [i][j] = '*';
        if (r==1) k=1;
        else if (c==1) k=2;
        else if (m==2||m==3||m==5||m==7) k=3;
        else if (m==1) k=4;
        else if (m==4||m==6||m==8) k=5;
        else if (m==9) k=6;
        else if (m>=10&&m<=12) k=12;
        else if (m==13) k=7;
        else if (m==14||m==15) k=8;
        else if (m==16) k=9;
        else if (m>=17&&m<=20) k=10;
        else k=11;
        printf ("Case #%d:\n",g);
        solve (k);
    }
    scanf (" ");
    return 0;
}
