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
    fout<<fixed;
   for (int i=0;i<n;i++)
   {
        double c,f,x, buytime, percookie;
        double ans;
        fin>>c;
        fin>>f;
        fin>>x;
        ans=x/2;
        buytime=0;
        percookie=2;
        while (buytime<ans)
        {
            if (buytime+x/percookie<ans) ans=buytime+x/percookie;
            buytime=buytime+c/percookie;
            percookie+=f;
        }
        fout<<"Case #"<<i+1<<": "<<setprecision(7)<<ans<<endl;
   }
   fin.close();
   fout.close();
}
