#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream fin ("deciful war.in");
    ofstream fout ("deciful war.out");

    int t;
    fin>>t;

        float me[1002];
        float him[1002];
        int n;

    for(int tc=1;tc<=t;tc++)
    {
        int dpoints=0;

        fin>>n;
        for(int i=0;i<n;i++)fin>>me[i];
        for(int i=0;i<n;i++)fin>>him[i];

        sort(me, me+n);
        sort(him, him+n);

        int f=0;

        for(int round=0;round<n;round++)
        {
            if(me[round]>him[f]){f++; dpoints++;}
        }

        f=0;
        int npoints=0;

        for(int i=0;i<n;i++)
        {
            while(f<n&&him[f]<me[i]){f++;}
            f++;
            if(f<=n)npoints++;
            if(f>=n)break;
        }

        fout<<"Case #"<<tc<<": "<<dpoints<<' '<<n-npoints<<'\n';
    }

return 0;
}
