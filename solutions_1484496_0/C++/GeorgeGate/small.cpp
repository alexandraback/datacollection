/*
DP:
    f[k][j]表示前k个数字组成的集合中，和为j的子集个数。 
    memset (f,0,sizeof(f));
    f[0][0]=1;
    f[k][j]=f[k-1][j-num[k-1]]+f[k-1][j];
*/
#include <fstream>
#include <string.h>

using namespace std;

long num[500],f[2000001];
ifstream fin;
ofstream fout;

int main()
{
    const char filename[256]="C-small-attempt0";
    char input[256]="data\\";
    char output[256]="data\\";
    strcat(strcat(input,filename),".in");
    strcat(strcat(output,filename),".out");
    fin.open(input);
    fout.open(output);
    
    long T,N;
    bool flag=false;
    fin >>T;
    for (long i=1;i<=T;++i)
    {
        flag=false;
        fin >>N;
        for (long j=0;j<N;++j) fin >>num[j];
        memset (f,0,sizeof(f));
        f[0]=1;
        for (long k=0;k<N;++k)
        {
            for (long j=2000001;j>=0;--j)
            {
                
                if (f[j]!=0)
                {
                   f[j+num[k]]+=f[j];
                   if (f[j+num[k]]==2)
                   {
                      fout <<"Case #" <<i <<": " <<endl;
                      fout <<num[k];
                      long a=j,b=k-1;
                      while (a>0)
                      {
                            if (f[a-num[b]]==1)
                            {
                               fout <<" " <<num[b];
                               a-=num[b];
                            }
                            --b;
                      }
                      fout <<endl;
                      a=j+num[k],b=k-1;
                      while (a>0)
                      {
                            if (f[a-num[b]]==1)
                            {
                               fout <<num[b];
                               a-=num[b];
                               if (a>0) fout <<" ";
                            }
                            --b;
                      }
                      fout <<endl;
                      flag=true;
                      break;
                   }
                }
            }
            if (flag) break;
        }
        if (!flag)
           fout <<"Case #" <<i <<": " <<"\nImpossible\n";
    }
    return 0;
}

