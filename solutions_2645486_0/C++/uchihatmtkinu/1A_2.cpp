#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

fstream fin,fout;
int T;

int E,R,n;
int a[20000000];
int ans;

int min(int a, int b)
{
    if (a>b) return b; else return a;
}

int find(int h,int e,int xx)
{
    if (xx > ans) ans = xx;
    if (h == n) return 0;
    int tmp = e;
    int yy = 0;
    find(h+1,min(tmp+R,E),xx);
    while (tmp > 0)
    {
        tmp--;
        yy++;
        find(h+1,min(tmp+R,E),xx+yy*a[h]);
    }
}

int main()
{
    fin.open("B-small-attempt1.in",ios::in);
    fout.open("test1.txt",ios::out);
    fin >> T;
    for (int k = 0; k < T; k++)
    {
        fin >> E >> R >> n;
        ans = 0;
        for (int i = 0; i < n; i++)
            fin >> a[i];
        find(0,E,0);

        fout << "Case #"<< k+1 << ": " << ans << endl;
    }
    fout.close();
    return 0;
}
