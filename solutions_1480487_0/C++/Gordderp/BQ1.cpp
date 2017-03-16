#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

int T,n;
int s[300];
int x;
const double zero=1e-9;

double ans[300];

double Max(double a,double b)
{
    if (a>b) return a;else return b;
}

int main()
{
    freopen("A-small-attempt4.in","r",stdin);
    freopen("output4.out","w",stdout);
    cin >> T;
    int Ncase=0;
    while (Ncase<T)
    {
        Ncase++;
        
        cin >> n;
        for (int i=1;i<=n;i++) cin >> s[i];
        x=0;
        for (int i=1;i<=n;i++) x+=s[i];
        
        for (int i=1;i<=n;i++)
        {
            double l=0,r=1;
            while (l<r-zero)
            {
                double mid=(l+r)/2;
                double score=mid*x+s[i];

                double tot=1-mid;
                
//                cout << mid << ' ' << score << ' ' << tot << endl;
                for (int j=1;j<=n;j++) if (j!=i) tot=tot-Max(0,(score-s[j])/double(x));
                if (tot>-zero) l=mid;else r=mid;
                

            }
   //         printf("%lf\n",l);
            ans[i]=l;
        }
        printf("Case #%d:",Ncase);
        for (int i=1;i<=n;i++) printf(" %.6lf",ans[i]*100);printf("\n");
    }
}
                
        
        
    
