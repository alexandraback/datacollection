#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
ifstream fin;
ofstream fout;
int n;
int go[3][2] = {{-1,-1},{-1,0},
                {0,-1},
                };
int r,c,m;
int a[51][51];

void dfs(int x, int y)

{
   bool f=true;
   a[x][y]=1;
   for (int i=0;i<3;i++)
   {
    int textx=x+go[i][0];
    int texty=y+go[i][1];
    if ((textx>0)&&(texty>0))
        if (a[textx][texty]==-1) {
                                    f=false;
                                    break;
        }
   }
   if (f) {

    for (int i=0;i<3;i++)
   {
    int textx=x+go[i][0];
    int texty=y+go[i][1];
    if ((textx>0)&&(texty>0)&&(a[textx][texty]==0)) dfs(textx,texty);
   }
   }

}
int main(int argc, const char * argv[])
{

   fin.open("data.in",std::ofstream::in);
   fout.open("data.out",std::ofstream::out);
   fin>>n;
   for (int step=0;step<n;step++)
   {

        fin>>r>>c>>m;

        for (int i=1;i<=r;i++)
            for (int j=1;j<=c;j++)
              a[i][j]=0;


        int i=1,j=1;

        while (m>0)
        {
            int s=r-i;
            if (c-j<s) s=c-j;
            if (m>s)
            {
                if ( (r-i)>(c-j) )
                {
                    for (int k=j;k<=c;k++)
                    if (m>0) {
                                m--;
                                a[i][k]=-1;
                            }
                    i++;
                }
                else
                {
                    for (int k=i;k<=r;k++)
                    if (m>0) {
                                m--;
                                a[k][j]=-1;
                            }
                    j++;
                }
            }
            else {
                if ( (r-i)>(c-j) )
                {
                    int i_s=1,j_s=0;
                    while (m>0)
                    {
                    if (i_s==j_s) {
                                    a[i+i_s][j]=-1;
                                    i_s++;

                                }
                                    else
                                {
                                        a[i][j+j_s]=-1;
                                        j_s++;
                                    }
                    m--;
                    }
                }
                else {
                   int i_s=0,j_s=1;
                    while (m>0)
                    {
                    if (i_s==j_s) {
                                    a[i][j+j_s]=-1;
                                    j_s++;

                                }
                                    else
                                {
                                        a[i+i_s][j]=-1;
                                        i_s++;
                                    }
                    m--;
                    }
                }

            }

        }
        fout<<"Case #"<<step+1<<":"<<endl;


        dfs(r,c);
        bool eans=true;
        for (int i=1;i<=r;i++)
           {
            for (int j=1;j<=c;j++)
                if (a[i][j]==0) {
                        eans=false;
                        break;
                }
            if (not eans) break;
           }
        if (not eans) {fout<<"Impossible"<<endl;
                       continue;
                    }
        for (int i=1;i<=r;i++)
           {

           for (int j=1;j<=c;j++)
            {

                if (a[i][j]==1) {
                    if ((i==r)&&(j==c)) fout<<'c';
                                   else fout<<'.';
                }
                else
                if (a[i][j]==-1) fout<<'*';
                            else fout<<' ';

            }
            fout<<endl;
           }
    }
    fin.close();
    fout.close();
}
