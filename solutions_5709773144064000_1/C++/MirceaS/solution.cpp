#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin ("cookie clicker alpha.in");
    ofstream fout ("cookie clicker alpha.out");
    fout.precision(12);

    int t;
    fin>>t;

    for(int tc=1;tc<=t;tc++)
    {
        double c, f, x;
        fin>>c>>f>>x;

        if(x<=c){fout<<"Case #"<<tc<<": "<<x/2<<'\n'; continue;}

        double delta=x-c;

        double cps=2;
        double time=c/cps;

        while(delta/cps>x/(cps+f)){cps+=f;time+=c/cps;}
        time+=delta/cps;

        fout<<"Case #"<<tc<<": "<<time<<'\n';
    }

return 0;
}
