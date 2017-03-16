#include<iostream>
using namespace std;
int t;
int a,b;
double p [100100];
double f[100100], g[100100];
double ans;
int main()
{
   freopen("a.in","r",stdin);
    freopen("a.out", "w", stdout);
   cin >> t;
   for (int l = 1; l <= t; ++l)
   {
  
       cin >> a >> b;
            ans = 2 + b;
       for (int i = 1 ; i <= a; ++i)
       {
            cin >> p[i];
       }
       f[0] = 0;
       g[0] = 1;
       for (int i = 1 ; i <= a ; ++i)
       {
           g[i] = g[i-1] * p[i];
           f[i] = 1 - g[i]; 
       }
       double temp;
       temp = (b - a + 1)*g[a] + (b - a + 1 + b +1) * f[a];
       //cout<< temp << endl;
       if (temp < ans)
          ans = temp;
       for (int i = 0; i < a;  ++i)
       {
           temp = g[i] * (a - i + b - i + 1) + (1-g[i]) *( a - i + b - i +1  + b + 1);
           if (temp < ans )
            ans = temp;
            //cout<< temp << endl;
       }
        cout <<"Case #"<<l<<": ";
       printf("%.6lf\n", ans);
   }
}
