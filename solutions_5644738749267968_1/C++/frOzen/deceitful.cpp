#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int main(int argc, const char * argv[])
{
   ifstream fin;
   ofstream fout;
   int n;
   fin.open("data.in",std::ofstream::in);
   fout.open("data.out",std::ofstream::out);
   fin>>n;
   for (int i=0;i<n;i++)
   {
        int m;
        float a[1500], b[1500];
        fin>>m;
        for (int j=0; j<m; j++)
            fin>>a[j];
        for (int j=0; j<m; j++)
            fin>>b[j];
        for (int j=0; j<m; j++)
            for (int k=j+1; k<m; k++)
              {
                if (a[j]>a[k]) {
                    float s=a[j];
                    a[j]=a[k];
                    a[k]=s;
                }
                if (b[j]>b[k]) {
                    float s=b[j];
                    b[j]=b[k];
                    b[k]=s;
                }
              }
              //a ---   nami   b---- ken
        int j=0,k=0,ans=0;
        while (k<m)
        {
            while ( (j<m) && (a[j]<b[k]) ) j++;
            if (j<m) { ans++; j++; }
            k++;
        }
        fout<<"Case #"<<i+1<<": "<<ans;

        j=m-1,k=m-1,ans=0;
        while (k>=0)
        {
            while ( (j>=0) && (a[j]>b[k]) ) j--;
            if (j>=0) { ans++; j--;}
            k--;
        }
        fout<<" "<<m-ans<<endl;
    }
    fin.close();
    fout.close();
}
