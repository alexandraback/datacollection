#include <fstream>
#include <queue>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

bool tab[1000][1000];
int n,m,k;

int main()
{
    int t;
    in >> t;
    for(int i=1; i<=t; i++)
    {
        in >> n >> m >> k;
        out << "Case #" << i << ": " << (2*k+2)/3 + (((2*k+2)%3>0) ? 1 : 0) << endl;
    }
    return 0;
}
