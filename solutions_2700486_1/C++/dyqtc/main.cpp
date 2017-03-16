#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#define MAXN 2000
#define cin fin
#define cout fout
using namespace std;

double f[MAXN][MAXN];

int main()
{
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    int i,j,k,n,t,CASE,h,x,y,now;
    double ans;
    cin >> CASE;
    for (t=1;t<=CASE;t++)
    {
        cin >> n >> x >>y;
        now=1;h=0;
        while (now<=n)
        {
            n = n-now;
            h++;
            now=now+4;
        }
        if (x+y<=2*(h-1))
            ans = 1;
        else if (x+y>2*h || x+y==2*h && x==0)
            ans = 0;
        else {
            h++;
            memset(f,0,sizeof(f));
            f[0][0]=1;
            for (i=1;i<=n;i++)
                for (j=0;j<=n;j++)
                {
                    k=i-j;
                    if (k==0)
                        f[i][j] = f[i-1][j-1]*0.5;
                    else if (j==0)
                        f[i][j] = f[i-1][j]*0.5;

                    //else if (k-1>2*h-1-2)
                    //    f[i][2*h-2] = f[i-1][j-1]+f[i-1];
                    //else if (j-1>2*h-1-2)
                    //    f[i][j] = f[i-1][j];
                    else f[i][j] = f[i-1][j]*0.5+f[i-1][j-1]*0.5;
                }
            ans = 0;
            for (i=y+1;i<=n;i++)
                ans += f[n][i];
            for (i=2*h-2+y+1;i<=n;i++)
                ans += f[n][i];
        }
        cout << "Case #" << t <<": " << setprecision(10) << fixed <<  ans << endl;



    }
    return 0;
}
/*
7
3 2 0
*/
