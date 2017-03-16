#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

struct st
{
    int x,y,z;
};

st make(int x,int y,int z)
{
    st a;
    a.x=x;
    a.y=y;
    a.z=z;
    return a;
}

vector <st> v,s;
int a[100][100],b[100][100],c[100][100],A[100],B[100],C[100],i,j,k,t,w,p,x,y,z;

int main()
{
    ifstream f("in.txt");
    ofstream g("out.txt");
    f >> t;
    srand(time(NULL));
    for (w=1;w<=t;w++)
    {
        g << "Case #" << w << ": ";
        f >> x >> y >> z >> p;
        for (i=1;i<=z;i++)
            A[i]=B[i]=C[i]=i;
        for (i=1;i<=x;i++)
            for (j=1;j<=y;j++)
                a[i][j]=0;
        for (i=1;i<=x;i++)
            for (k=1;k<=z;k++)
                b[i][k]=0;
        for (j=1;j<=y;j++)
            for (k=1;k<=z;k++)
                c[j][k]=0;
        random_shuffle(A+1,A+x+1);
        random_shuffle(B+1,B+y+1);
        random_shuffle(C+1,C+z+1);
        for (i=1;i<=x;i++)
            for (j=1;j<=y;j++)
                for (k=1;k<=z;k++)
                    if (a[A[i]][B[j]]<p && c[B[j]][C[k]]<p && b[A[i]][C[k]]<p)
                    {
                        a[A[i]][B[j]]++;
                        b[A[i]][C[k]]++;
                        c[B[j]][C[k]]++;
                        v.push_back(make(A[i],B[j],C[k]));
                    }
        for (int W=1;W<=10000;W++)
        {
            for (i=1;i<=z;i++)
                A[i]=B[i]=C[i]=i;
            for (i=1;i<=x;i++)
                for (j=1;j<=y;j++)
                    a[i][j]=0;
            for (i=1;i<=x;i++)
                for (k=1;k<=z;k++)
                    b[i][k]=0;
            for (j=1;j<=y;j++)
                for (k=1;k<=z;k++)
                    c[j][k]=0;
            random_shuffle(A+1,A+x+1);
            for (i=1;i<=x;i++)
            {
                random_shuffle(B+1,B+y+1);
                for (j=1;j<=y;j++)
                {
                    random_shuffle(C+1,C+z+1);
                    for (k=1;k<=z;k++)
                        if (a[A[i]][B[j]]<p && c[B[j]][C[k]]<p && b[A[i]][C[k]]<p)
                        {
                            a[A[i]][B[j]]++;
                            b[A[i]][C[k]]++;
                            c[B[j]][C[k]]++;
                            s.push_back(make(A[i],B[j],C[k]));
                        }
                }
            }
            if (s.size()>v.size())
            {
                v=s;
            }
            s.resize(0);
        }
        g << v.size() << "\n";
            for (i=0;i<v.size();i++)
                g << v[i].x << ' ' << v[i].y << ' ' << v[i].z << "\n";
        v.resize(0);
    }
    return 0;
}
