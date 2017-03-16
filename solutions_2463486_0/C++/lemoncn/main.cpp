#include <fstream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int f[1000001];
bool isPalin(string str)
{
    int i = 0, j = str.length() - 1;
    while(i < j)
        if(str[i++] != str[j--])
            return false;
    return true;
}
string Convert(long long i)
{
    static char str[101];
    sprintf(str, "%lld", i);
    return string(str);
}
int main(void)
{
    ifstream fin("input.in");
    ofstream fout("output.out");
    int T;
    fin >> T;
    f[1] = 1;
    for(long long i = 2; i <= 1000000; i++)
    {
        if(isPalin(Convert(i)) && isPalin(Convert(i*i)))
            f[i] = f[i-1] + 1;
        else
            f[i] = f[i-1];
    }
    for(int caseno = 1; caseno <= T; caseno++)
    {
        fout << "Case #" << caseno << ": ";
        long long a, b;
        fin >> a >> b;
        a--;
        b = sqrt(b);
        a = sqrt(a);
        fout << f[b] - f[a] << endl;
    }
    return 0;
}
