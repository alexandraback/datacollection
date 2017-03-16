#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

double C,F,X;
int T;

double time()
{
    double pt = 0.00000000;
    double pr = 2.00000000;
    double nt = X / pr;
    int fm = 0 ;
    while (true) {
        fm ++ ;
        pt = pt + (C/pr);
        pr += F;
        double ct = pt + (X/pr);
        if (ct>=nt) return nt;
        nt = ct;
    }
}
              

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>T;
    for (int i = 1 ; i <= T ; i ++ ) {
        cin>>C>>F>>X;
        cout<<"Case #"<<i<<": ";
        printf("%.7lf\n",time());
    }
    //while(1){};
    return 0;
}
