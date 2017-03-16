#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

string s;
int N, T, p, B;
bool adj[51][51];
long long M, r;
ifstream fin("in.in");
ofstream fout("out.out");

int main()
{
    fin >>T;
    for(int p = 1; p <= T; p++)
    {
        fin >>B >>M;
        fout <<"Case #" <<p <<": ";
        r = (1LL << (B-2)) - M;
        memset(adj, 0, sizeof(adj));
        if(r < 0) fout <<"IMPOSSIBLE" <<endl;
        else
        {
            fout <<"POSSIBLE" <<endl;
            for(int i = 1; i < B; i++)
                for(int j = i + 1; j <= B; j++)
                    adj[i][j] = true;
            for(int i = 2; i < B; i++)
            {
                if(r & 1) adj[i][B] = false;
                r >>= 1;
            }
            for(int i = 1; i <= B; i++, fout <<endl)
                for(int j = 1; j <= B; j++)
                    fout <<adj[i][j];
        }
    }
    return 0;
}
