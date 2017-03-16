#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

fstream fin,fout;
int T;

long long rr,t;

int main()
{
    fin.open("A-large.in",ios::in);
    fout.open("test1.txt",ios::out);
    fin >> T;
    for (int k = 0; k < T; k++)
    {
        fin >> rr >> t;
        long long r = sqrt(t) + 1;
        long long l = 1;
        long long tmp;
        long long ans;
        long double tt;
        ans = 1;
        while (r >= l)
        {
            tmp = (r + l) / 2;
            //cout << tmp << ' ' << l << ' ' << r << endl;
            tt = tmp;
            //if (tmp*tmp*2+(2*rr-1)*tmp <= t) {ans = tmp; l = tmp+1;}
            if (tt*tt*2 + (2*rr-1)*tt <= t) {ans = tmp; l = tmp+1;}
            else r = tmp-1;
        }

        fout << "Case #"<< k+1 << ": " << ans << endl;
    }
    fout.close();
    return 0;
}
