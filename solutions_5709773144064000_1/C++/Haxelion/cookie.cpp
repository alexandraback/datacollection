#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char **argv)
{
    fstream input;
    int n;
    input.open(argv[1], fstream::in);
    input >> n;
    for(int i = 1; i<=n; i++)
    {
        cout << "Case #" << i << ": " ;
        double C, F, X;
        bool found = false;
        double time = 0, newtime = 0;
        input >> C >> F >> X;
        for(int j = 0; !found; j++)
        {
           if( time + C/(2+j*F) + X/(2+(j+1)*F) > time + X/(2+j*F))
           {
               found = true;
               time = time + X/(2+j*F);
           }
           else
               time = time + C/(2+j*F);
        }
        cout << fixed << setprecision(7) << time << endl;
    }
}
