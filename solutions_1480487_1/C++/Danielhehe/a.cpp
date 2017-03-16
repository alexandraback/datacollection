#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

double fabs(double x)
{
    if (x>0) return x;
    else return (-x);
}
int main()
{
//   freopen("A.in","r",stdin);freopen("result.out","w",stdout);
    freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
    int T;
    cin>>T;
    int a[1000],b[1000];
    double ans[1000];
    for (int N=1; N<=T; N++)
    {
        int n;
        double sum=0;
        cin>>n;
        for (int i=0; i<n; i++)
        {
            cin>>a[i];
            b[i]=i;
            sum+=a[i];
        }
        for (int i=0; i<n; i++)
        {
            double x=0,y=1;
            while (fabs(y-x)>0.000000001)
            {
                  double mid=(x+y)/2;
                  double s=1-mid;
                  double z=a[i]+(double)sum*(double)mid;
                  int t=0,j;
                  bool flag=true;
                  for (j=0; j<n; j++)
                      if ((j!=i) && (a[j]<z))
                      {
                         double u=(z-(double)a[j])/sum;
                         if (u<=s) s-=u; else {flag=false; break; }
                      }
                  if (flag) x=mid;
                  else y=mid;
             }
             ans[i]=x*100;
        }
        cout<<"Case #"<<N<<": ";
        for (int i=0; i<n; i++) printf("%.6f ",ans[i]);
        cout<<endl;
    }
    return 0;
}
