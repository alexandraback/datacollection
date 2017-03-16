#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char **argv)
{
    fstream input;
    int t;
    input.open(argv[1], fstream::in);
    input >> t;
    for(int i = 1; i<=t; i++)
    {   
        unsigned long long a,b,c, count;
        input >> a >> b >> c;
        count = 0;
        for(unsigned long long j = 0; j<a; j++)
            for(unsigned long long k = 0; k<b; k++)
                if((j&k) < c)
                    count ++;
        cout << "Case #" << i << ": " << count << endl;
    }
}
