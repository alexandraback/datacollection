#include<iostream>
#include<algorithm>
#include<iomanip>
#include<fstream>
#include<cmath>
#include<algorithm>
using namespace std;
int b,t,r,c,m,o;
char rj[100][100];
void print(int pos)
{
    cout<<"Case #"<<o+1<<": "<<endl;
    if (pos==1)
        cout<<"Impossible"<<endl;
    else
    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
            cout<<rj[i][j];
        cout<<endl;
    }
    return;
}
int main()
{
    //ofstream fout ("test.out");
    //ifstream fin ("test.in");
    cin>>t;
    for (o=0; o<t; o++)
    {
        cin>>r>>c>>m;

        if (r==1) //+3
        {
            for (int i=0; i<m; i++)
                rj[0][i]='*';
            rj[0][c-1]='c';
            for (int i=m; i<c-1; i++)
                rj[0][i]='.';
            print(0);
            continue;
        }
        if (c==1)     //+3
        {
            for (int i=0; i<m; i++)
                rj[i][0]='*';
            rj[r-1][0]='c';
            for (int i=m; i<r-1; i++)
                rj[i][0]='.';
            print(0);
            continue;
        }
        if ((r*c-m)==1)  //+2
        {
            for (int i=0; i<r; i++)
                for (int j=0; j<c; j++)
                    rj[i][j]='*';
            rj[0][0]='c';
            print(0);
            continue;
        }
        if ((r*c-m)==2)   //+6
        {
            print(1);
            continue;
        }

        if (r==2)
        {
            if (m%2==1)     //+2
                {
                    print(1);
                    continue;
                }

            for (int i=0; i<m/2; i++)  //+2
                {
                    rj[0][i]='*';
                    rj[1][i]='*';
                }
            for (int i=m/2; i<c-1; i++)
                {
                    rj[0][i]='.';
                    rj[1][i]='.';
                }
            rj[0][c-1]='c';
            rj[1][c-1]='.';
            print(0);
            continue;
        }

        if (c==2)
        {
            if (m%2==1) //+2
                {
                    print(1);
                    continue;
                }

            for (int i=0; i<m/2; i++)  //+2
                {
                    rj[i][0]='*';
                    rj[i][1]='*';
                }
            for (int i=m/2; i<r-1; i++)
                {
                    rj[i][0]='.';
                    rj[i][1]='.';
                }
            rj[r-1][0]='c';
            rj[r-1][1]='.';
            print(0);
            continue;
        }

        if ((r*c-3)==m || (r*c-5)==m || (r*c-7)==m)  //+4
        {
            print(1);
            continue;
        }

        for (int i=0; i<r; i++)
                for (int j=0; j<c; j++)
                    rj[i][j]='*';

        b=r*c-m;



        if (b<=3*c)
        {
            if (b%2==0)
            {
                if (b<=2*c)  //+3
                {
                    for (int i=0; i<2; i++)
                        for (int j=0; j<b/2; j++)
                            rj[i][j]='.';
                }
                else   //+2
                {
                    for (int i=0; i<2; i++)
                        for (int j=0; j<c; j++)
                            rj[i][j]='.';
                    for (int i=0; i<b-2*c; i++)
                        rj[2][i]='.';
                }
                rj[0][0]='c';
                print(0);
                continue;
            }
            else
            {

                for (int i=0; i<3; i++)
                    for (int j=0; j<3; j++)
                        rj[i][j]='.';
                rj[0][0]='c';
                b-=9;

                if (b<=2*(c-3))  //+3
                {
                    for (int i=0; i<2; i++)
                        for (int j=0; j<b/2; j++)
                            rj[i][j+3]='.';
                }
                else  //+2
                {
                    for (int i=0; i<2; i++)
                        for (int j=3; j<c; j++)
                            rj[i][j]='.';
                    for (int i=0; i<b-2*(c-3); i++)
                        rj[2][3+i]='.';
                }
                b+=9;
                print(0);
                continue;
            }

        }
        if (b>3*c)
        {
            if (b%c!=1)  //+2
            {
                for (int i=0; i<b/c; i++)
                    for (int j=0; j<c; j++)
                        rj[i][j]='.';
                for (int j=0; j<b%c; j++)
                    rj[b/c][j]='.';
                rj[0][0]='c';
                print(0);
                continue;
            }
            else   //+4
            {
                for (int i=0; i<b/c-1; i++)
                    for (int j=0; j<c; j++)
                        rj[i][j]='.';
                for (int j=0; j<c-1; j++)
                        rj[b/c-1][j]='.';
                rj[b/c][0]='.';
                rj[b/c][1]='.';
                rj[0][0]='c';
                print(0);
                continue;
            }
        }
    }
    return 0;
}
