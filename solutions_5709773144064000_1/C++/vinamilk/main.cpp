#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <sstream>

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long

using namespace std;

const double eps=1E-6;

double c,f,x,v,tg;

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("vd2.out","w",stdout);
    int t,it,k,i;double kq1,kq2,kq3;
    scanf("%d",&t);
    for(it=1;it<=t;++it)
    {
        scanf("%lf%lf%lf",&c,&f,&x);
        kq1=x/2.0;
        k=int((x*f-2.0*c)/(c*f));
        kq2=0;
        for(i=0;i<k;++i) kq2+=c/(i*f+2.0);
        kq2+=x/(double(k)*f+2.0);
        kq3=0;
        for(i=0;i<k+1;++i) kq3+=c/(i*f+2.0);
        kq3+=x/(double(k+1)*f+2.0);
        printf("Case #%d: %.7lf\n",it,min(kq1,min(kq2,kq3)));
    }
}
