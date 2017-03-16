#include <fstream>

using namespace std;

long long a[100][100],s[100],i,j,w,t,n,p;

int main()
{
    ifstream f("in.txt");
    ofstream g("out.txt");
    f >> t;
    for (w=1;w<=t;w++)
    {
        g << "Case #" << w << ": ";
        f >> n >> p;
        for (i=1;i<n;i++)
            for (j=i+1;j<n;j++)
                a[i][j]=1;
        s[1]=1;
        s[2]=1;
        for (i=3;i<n;i++)
            s[i]=2*s[i-1];
        for (i=n-1;i>=1;i--)
            if (s[i]<=p)
            {
                p-=s[i];
                a[i][n]=1;
            }
        if (p!=0)
        {
            g << "IMPOSSIBLE\n";
        }
        else
        {
            g << "POSSIBLE\n";
            for (i=1;i<=n;i++)
            {
                for (j=1;j<=n;j++)
                    g << a[i][j];
                g << "\n";
            }
        }
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
                a[i][j]=0;
    }
    return 0;
}
