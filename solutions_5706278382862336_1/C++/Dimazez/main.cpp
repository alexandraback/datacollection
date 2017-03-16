#include <iostream>
#include <fstream>
#include <string>

using namespace std;
long long Nod(long long a, long long b)
{
    long deg = 0;
    if (a == 0 || b == 0)
        return a | b;
    while (((a | b) & 1) == 0)
    {
        deg++;
        a >>= 1;
        b >>= 1;
    }
    while (a && b)
    {
        if (b & 1)
            while ((a & 1) == 0)
                a >>= 1;
        else
            while ((b & 1) == 0)
                b >>= 1;
        if (a >= b)
            a = (a - b) >> 1;
        else
            b = (b - a) >> 1;
    }
    return ((a | b) << deg);
}
int main()
{
    long long t,p,q,c;
    bool f;
    FILE* in;
    in=fopen("A.in","r+");
    ofstream out("A.out");
    fscanf(in,"%I64d",&t);
    for(int Case=1;Case<=t;Case++)
    {
        f=false;
        fscanf (in,"%I64d/%I64d ", &p, &q );
        c=Nod(p,q);
        q=q/c;
        p=p/c;
        c=q;
        while (c%2!=1)
        {
            c/=2;
        }
        if (c==1) f=true;
        if (!f)  {out<<"Case #"<<Case<<": impossible"<<endl;continue;}
        f=false;
        c=1;
        for (int i=1;i<=40;i++)
        {
            c=c*2;
            if (c*p>=q)
            {
                out<<"Case #"<<Case<<": "<<i<<endl;
                f=true;
                break;

            }
        }
        if (!f)  out<<"Case #"<<Case<<": impossible"<<endl;
    }

    return 0;
}
