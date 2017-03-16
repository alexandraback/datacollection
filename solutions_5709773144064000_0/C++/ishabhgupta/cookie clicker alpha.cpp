#include<iostream>
#include<cstdio>
#include<cmath>
#include<fstream>

using namespace std;

int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin >> t;
    for(int te=1;te<=t;te++) {
        double c,f,x;
        cin >> c >> f >> x;
        double r,l;
        r = 2.0;
        l = x;
        double tim = 0.0;
        double ans = x/r;
        while(l>=c) {
            tim = tim + c/r;
            r += f;
            l -= c;
            double temp = tim + x/r;
            if(temp < ans) ans = temp;
        }
        tim = tim + x/r;
        if(floor(tim-ans)<0) ans = tim;
        cout << "Case #" << te << ": ";
        printf("%.7lf\n",ans);
    }
}
