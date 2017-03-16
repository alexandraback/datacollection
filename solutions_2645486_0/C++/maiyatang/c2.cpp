#include<fstream>
using namespace std;
ifstream fin ("temp.in");
ofstream fout ("temp.out");
int save [6];
int main ()
{
    int t;
    fin>>t;
    int i;
    for (i=0;i<t;i++)
    {
        fout<<"Case #"<<i+1<<": ";
        int e,r,n;
        fin>>e>>r>>n;
        int j;
        for (j=0;j<e;j++) save[j]=-1;
        save[e]=0;
        for (j=0;j<n;j++)
        {
            int v;
            fin>>v;
            int x,y;
            for (x=0;x<=e;x++)
                for (y=x;y<=e;y++)
                   if (save[y]!=-1)
                      if (save[y]+(y-x)*v>save[x]) save[x]=save[y]+(y-x)*v;
            int temp=0;
            if (r>e) temp=0;
            else temp=e-r;
            for (x=e;x>=temp;x--)
                if (save[x]>save[e]) save[e]= save[x];
            for (x=temp-1;x>=0;x--)
                save[x+r]=save[x];
            int temp2=0;
            if (r>e) temp2=e-1;
            else temp2=r-1;
            for (x=temp2;x>=0;x--) save[x]=-1;
        }
        int maxv=0;
        for (j=0;j<=e;j++)
        {
         //fout<<save[j]<<endl;
            if (maxv<save[j]) 
            {
               //fout<<save[j]<<endl;
               maxv=save[j];
            }
            }
        fout<<maxv<<endl;
    }
}
