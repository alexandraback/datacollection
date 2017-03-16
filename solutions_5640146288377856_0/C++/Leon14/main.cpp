#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("A-small-attempt0 (1).in");
    ofstream out("salidabatlleship.out");

    int r,c,w,k,t,mov;

    in>>t;
    for(k=1;k<=t;k++)
    {
        mov=0;
        in>>r>>c>>w;

        mov=(c/w);
        if(c%w==0)
        {
            mov=mov+w-1;
        }
        else
        {
            mov=mov+w;
        }
        mov=mov*r;

        out<<"Case #"<<k<<": "<<mov<<endl;

    }

    in.close();
    out.close();
    return 0;
}
