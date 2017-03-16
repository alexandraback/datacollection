#include <iostream>
#include <fstream>

using namespace std;

fstream IN;
fstream OUT;

long long t, a, b;


int check(long long x, long long y)
{
    long long z;
    while(y != 0)
    {
        z = x%y;
        x = y;
        y = z;
    }

    y = a/x;
    z = b/x;

    long long j = 0;
    long long pot = 1;
    while(pot<z)
    {
        pot<<=1;
        j++;
    }

    if(pot == z)
    {
        j = 0;
        pot = 1;
        while(pot<=z)
        {
            if(y*pot>=z) return j;
            pot<<=1;
            j++;
        }
    }
    else return -1;
}

int main()
{
    IN.open("C:\\GCJ\\in.txt");
    OUT.open("C:\\GCJ\\out.txt");

    char c;
    IN >> t;
    for(int i=0; i<t; i++)
    {
        IN >> a >> c >> b;
        int ans = check(a, b);

        if(ans == -1) OUT << "Case #" << i+1 << ": impossible\n";
        else OUT << "Case #" << i+1 << ": " << ans << "\n";
    }

    return 0;
}
