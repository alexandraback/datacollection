#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

ifstream fin("1b_a.in");
ofstream fout("1b_aout.txt");

int n,sum,sum2,nn;
int a[200];
bool b[200];

int main()
{
    int o,t;
    fin >> t;
    for (o=1;o<=t;o++)
    {
        fin >> n;
        sum = 0;
        memset(b,false,sizeof(b));
        nn = n;
        for (int i=0;i<n;i++)
        {
            fin >> a[i];
            sum += a[i];
        }
        sum2 = sum;
        for (int i=0;i<n;i++)
        {
            if ((double)(sum*2/n)<a[i]) {b[i] = true;nn--;}
        }
        for (int i=0;i<n;i++)
        {
            if (b[i]) sum-=a[i];
        }
        fout << "Case #" << o << ":" ;
        for (int i=0;i<n;i++)
        {
            if (b[i]) fout << " 0.000000" ;
            else fout << " " << setiosflags(ios::fixed) << setprecision(6) << 100*(double)(((double)((double)(sum+sum2)/(double)nn) - a[i])/(double)sum2);
        }
        fout << endl;
    }
    return 0;
}
