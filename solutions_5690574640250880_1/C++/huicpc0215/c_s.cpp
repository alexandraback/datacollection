#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<fstream>
using namespace std;

char mp[600][600];
int r,c,m,rev,bk,tnum,casecnt;
ifstream i1("C-large.in");
ofstream o1("c_s.out");
void output()
{
    if( rev == -1 )
    {
        //printf("Impossible\n");
        o1<<"Impossible"<<endl;
        return ;
    }
    else if( rev  == 0 )
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(i==0&&j==0) o1<<"c";
                else o1<<mp[i][j];
            }
            o1<<endl;
        }
    }
    else
    {
        for(int i=0;i<c;i++)
        {
            for(int j=0;j<r;j++)
            {
                if(i==0&&j==0) o1<<"c";
                else o1<<mp[j][i];
            }
            o1<<endl;
        }
    }
}
int main()
{
//    freopen("C-samll-attempt0.in","r",stdin);
//    freopen("c_s.out","w",stdout);
//    scanf("%d",&t);
    casecnt=1;
    i1>>tnum;
    //printf("t=%d\n",tnum);
    while(tnum--)
    {
//        scanf("%d%d%d",&r,&c,&m);
//        printf("Case #%d:\n",casecnt++);
        i1>>r>>c>>m;
        //printf("pro -> %d\n",casecnt);
        o1<<"Case #"<<casecnt++<<":"<<endl;
        if( r < c )
        {
            rev = 1 ;
            swap(  r , c );
        }
        else rev = 0;
        bk = r * c  -  m;
        if( c == 1 )
        {
            for(int i=0;i<r;i++)
            {
                if( i < bk ) mp[i][0]='.';
                else mp[i][0]='*';
            }
        }
        else if( c == 2 )
        {
            if( bk == 1 )
            {
                for(int i=0;i<r;i++)
                    for(int j=0;j<c;j++)
                        mp[i][j]='*';
            }
            else if( bk % 2 == 1 || bk == 2 ) rev = -1;
            else
            {
                for(int i=0;i<r;i++)
                {
                    for(int j=0;j<c;j++)
                    {
                        if(i*2<bk) mp[i][j]='.';
                        else mp[i][j]='*';
                    }
                }
            }
        }
        else
        {
//            printf("in here bk=%d\n",bk);
            if( bk == 1 )
            {
                for(int i=0;i<r;i++)
                    for(int j=0;j<c;j++)
                        mp[i][j] = '*';
            }
            else if( bk == 2 || bk == 3 || bk == 5 || bk == 7) rev = -1;
            else
            {
                for(int i=0;i<r;i++)
                    for(int j=0;j<c;j++)
                        mp[i][j]='*';
                if( bk < r * 2 + 1 )
                {
                    if(bk%2==1)
                    {
                        for(int i=0;i<r;i++)
                        {
                            if(bk>3)
                            {
                                mp[i][0]=mp[i][1]='.';
                                bk-=2;
                            }
                            if(i<3) mp[i][2]='.';
                        }
                    }
                    else
                    {
                        for(int i=0;i<r;i++)
                        {
                            if(bk)
                            {
                                mp[i][0]=mp[i][1]='.';
                                bk-=2;
                            }
                        }
                    }
                }
                else if( bk == 2*r + 1)
                {
                    for(int i=0;i<r;i++)
                        {
                            if(bk>3)
                            {
                                mp[i][0]=mp[i][1]='.';
                                bk-=2;
                            }
                            if(i<3) mp[i][2]='.';
                        }
                }
                else
                {
                    for(int i=0;i<r;i++)
                        mp[i][0]=mp[i][1]='.';
                    bk-=2*r;
                    int line = 2,lastline =1,row=0;
                    while( bk )
                    {
                        if( line!= lastline  &&  bk==1 )
                        {
                            mp[r-1][lastline]='*';
                            mp[0][line]=mp[1][line]='.';
                            break;
                        }
                        else if( line!=lastline )
                        {
                            bk-=2;
                            mp[row++][line]='.';
                            mp[row++][line]='.';
                        }
                        else
                        {
                            bk--;
                            mp[row++][line]='.';
                        }
                        lastline = line ;
                        if( row==r )
                        {
                            line++;
                            row=0;
                        }
                    }
                }
            }
        }
        output();
    }
    return 0;
}
