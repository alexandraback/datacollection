#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;

double c[100000];
double d[100000];

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int t;
    cin>>t;
    for (int no = 1; no <= t; no++)
    {
        int a, b;
        cin>>a>>b;
        c[0] = 1;
        for (int i = 1; i <= a; i++)
        {
            cin>>c[i];
        }
        d[0] = 1;
        for (int i = 1; i <= a; i++)
        {
            d[i] = c[i]*d[i-1];
        }
        double res = 1e100;
        double ex;

        ex = d[a]*(b-a+1)+(1-d[a])*(b-a+1+b+1);// keep typing
        res = min(res, ex);
        //cout<<ex<<endl;

        for (int i = 1; i <= a; i++)// press backspace i-th
        {
            ex = (d[a-i]*(b-a+2*i+1)) + ((1-d[a-i])*(b-a+1+2*i+b+1));
            res = min(res, ex);
            //cout<<ex<<endl;
        }

        ex = 2+b;// press enter right away
        res = min(res, ex);
        //cout<<ex<<endl;
        cout<<setprecision(9)<<fixed<<"Case #"<<no<<": "<<res<<endl;
    }
}
