#include <iostream>
#include <fstream>

using namespace std;

int t;
double c, f, x, tel, p;

void solve()
{
    double x1, x2;
    x1 = x2 = tel = 0;
    p = 2;
    if(c > x){
        tel = x/2;
        return;
    }
    while(1){
        tel+=c/p;
        x1 = (x-c)/p;
        x2 = x/(p+f);
        if(x1 <= x2){
            tel+= x1;
            return;
        }
        p+=f;
    }
}

int main()
{
    //ifstream fin("Input");
    //ofstream fout("Output");
    freopen("Input", "r", stdin);
    freopen("Output", "w", stdout);

    //fin >> t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++){
        //fin >> c >> f >> x;
        scanf("%lf %lf %lf", &c, &f, &x);
        solve();
        //fout << fixed << tel << "\n";
        printf("Case #%d: %.7lf\n", i, tel);
    }


    return 0;
}
