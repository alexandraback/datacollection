#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int T, p, i, j, a, b, n;
int ans[50];
ifstream fin("in.in");
ofstream fout("out.out");

int main()
{   
    fin >>T;
    for(p = 1; p <= T; p++)
    {
        fin >>n;
        bool seen[2501] = {0};
        for(i = 1; i < 2*n; i++)
            for(j = 1; j <= n; j++)
            {
                fin >>a;
                seen[a] = !seen[a];
            }
        for(i = 1, j = 0; i<=2500; i++)
            if(seen[i]) ans[j++] = i;
        fout <<"Case #" <<p <<": ";
        for(i = 0; i < j ; i++)
            fout <<ans[i] <<' ';
        fout <<endl;
    }
    return 0;
} 
