#include <iostream>
#include <iomanip>

using namespace std;

void runTest()
{
    long double C, F, X;
    cin >> C >> F >> X;
    long double t = X/2.0, S=0;
    long double temp;
    int n=0;
    bool decr=true;
    while (decr)
    {
        S+=((n+1)*C+F*S)/(n*F+2);
        n++;
        temp = (X+n*C+F*S)/(n*F+2);
        if (temp < t) t = temp;
        else decr=false;
    }
    cout << t << endl;
}

int main()
{
    int T;
    cin >> T;
    cout << setprecision(20);
    for (int test=1; test<=T; test++)
    {
        cout << "Case #" << test << ": ";
        runTest();
    }
    return 0;
}
