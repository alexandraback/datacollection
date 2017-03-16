#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
#include <stack>
#include <fstream>
using namespace std;
#define mo 1000000007ll
#define eps 1e-8
#define inf 2147480000
ifstream in("B-small-attempt2.in");
ofstream out("ans.txt");
int t;
double c,f,x;
inline int sgn(double a,double b)
{
    if(fabs(a-b)<eps) return 0;
    else if(a>b+eps) return 1;
    else if(a+eps<b) return -1;
}
inline bool check(double a)
{
    double an=2*a;
    if(sgn(an,x)!=-1) return 1;
    double bn,cn=0;
    for(int i=1;i<=100000;i++)
    {
        cn+=c/(2+(i-1)*f);
        bn=an+(a-cn)*f-c;
        if(sgn(bn,an)==-1) break;
        if(sgn(bn,x)!=-1) return 1;
        an=bn;
    }
    return 0;
}
int main()
{
    in>>t;
    int cac=0;
    while(t--)
    {
        cac++;
        in>>c>>f>>x;
        double maxn=x/2;
        double an=x/2,bn,cn=0;
        for(int i=1;i<=100000;i++)
        {
            cn+=c/(2+(i-1)*f);
            bn=cn+x/(2+i*f);
            if(sgn(bn,an)==1) break;
            an=bn;
        }
        out<<"Case #"<<cac<<": ";
        out<<fixed<<setprecision(7)<<an<<endl;
    }
}
