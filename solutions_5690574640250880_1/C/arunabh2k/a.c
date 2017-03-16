#include <stdio.h>
#include <math.h>

void printim()
{
    printf("Impossible\n");
}
int main()
{
    int nc, notc;
	scanf("%d", &notc);
	for(nc=1;nc<=notc;nc++)
	{
        int gr, gc, gm;
        int r, c, m;
        char cmat[51][51];
        scanf("%d %d %d", &gr, &gc, &gm);
        int ix, jx;
        m = gm;
        r=gr;
        c=gc;
        for(ix=1;ix<=gr;ix++)
        {
            for(jx=1;jx<=gc;jx++)
            {
                cmat[ix][jx] = '.';
            }
        }
        cmat[0][0] = 'c';
        while(m>0)
        {
            if(m >= r && c > 3)
            {   m = m - r;c--;}
            else if (m >= c  && r > 3)
            {   m = m - c;r--;}
            else if(r==3 && c==3)
            {
                if(m>=5){ r--;c--;m = m-5; }
                else
                    break;
            }
            else if(r==2 && c==2)
            {
                if(m==3){ r--;c--;m = 0; }
                else
                    break;
            }
            else if(r ==2 && c > 2 && m >= 2)
            {
                c--;
                m=m-2;
            }
            else if(c ==2 && r > 2 && m >= 2)
            {
                r--;
                m=m-2;
            }
            else if(r ==1 && c > 1 && m >= 1)
            {
                c--;
                m=m-1;
            }
            else if(c ==1 && r > 1 && m >= 1)
            {
                r--;
                m=m-1;
            }
            else
                break;
        }

        //printf("%d %d %d\n", gr, gc, gm);
        //printf("%d %d %d\n", r, c, m);
        
        for(ix=1;ix<=gr;ix++)
        {
            for(jx=c+1;jx<=gc;jx++)
            {
                cmat[ix][jx] = '*';
            }
        }
        for(ix=r+1;ix<=gr;ix++)
        {
            for(jx=1;jx<=gc;jx++)
            {
                cmat[ix][jx] = '*';
            }
        }
/*        
        for(ix=1;ix<=gr;ix++)
        {
            for(jx=1;jx<=gc;jx++)
            {
                printf("%c ", cmat[ix][jx]);
            }
            printf("\n");
        }
*/
        printf("Case #%d:\n", nc);
        //printf("Case #%d: %d %d %d\n", nc, gr,gc,gm);

        if(r==1 || c==1)
        {
        }
        else if(r==2 && c ==2)
        {
            if(m>0)
            {
                printim();
                continue;
            }
        }
        else if(r==2 || c ==2)
        {
            if(m>0)
            {
                printim();
                continue;
            }
        }
        else if(r==3 && c==3)
        {
            if(m==0)
            {
            }
            else if(m==1)
            {
                cmat[r][c] = '*';
            }
            else if(m==3)
            {
                cmat[r][c] = '*';
                cmat[r][c-1] = '*';
                cmat[r][c-2] = '*';
            }
            else
            {
                printim();
                continue;
            }
        }
        else if(r==3 || c==3)
        {
            if(r==3)
            {
                if(m > c-2)
                {
                    printim();
                    continue;
                }
                else
                {
                    if(m > 0)
                    {
                        cmat[r][c] = '*';
                        m--;
                    }
                    if(m!=0)
                    {
                        cmat[r][c-1] = '*';
                        m--;
                    }
                    if(m!=0)
                    {
                        cmat[r][c-2] = '*';
                        m--;
                    }
                }
            }
            else
            {
                if(m > r-2)
                {
                    printim();
                    continue;
                }
                else
                {
                    if(m > 0)
                    {
                        cmat[r][c] = '*';
                        m--;
                    }
                    if(m!=0)
                    {
                        cmat[r-1][c] = '*';
                        m--;
                    }
                    if(m!=0)
                    {
                        cmat[r-2][c] = '*';
                        m--;
                    }
                }
            }
        }
        else
        {
            if(m > 0)
            {
                cmat[r][c] = '*';
                m--;
            }
            int di = 1;
            while(1)
            {
                if(m==0)
                    break;
                cmat[r-di][c] = '*';
                m--;

                if(m==0)
                    break;
                cmat[r][c-di] = '*';
                m--;
                di++;
            }
        }
        cmat[1][1] = 'c';
        int cnt = 0;
        for(ix=1;ix<=gr;ix++)
        {
            for(jx=1;jx<=gc;jx++)
            {
                if(cmat[ix][jx] == '*')
                    cnt++;
                printf("%c", cmat[ix][jx]);
            }
            printf("\n");
        }
        /*
        if(cnt != gm)
            printf("Case #%d: %d %d %d\n", nc, gr,gc,gm);
        */
	}
    return 0;
}

