#include <iostream>
#include <iomanip>


void cookie()
{
    int nb_case;
    cin >> nb_case;

    long double C, F, X;

    long double tmp, prec;

    int n;

    for(int i=0; i<nb_case; i++)
    {
        cin >> C;
        cin >> F;
        cin >> X;

        tmp = X/2;
        prec = tmp;
        n = 0;
        while(tmp<=prec)
        {
            prec = tmp;
            tmp = tmp + C/(2+n*F) - X/(2+n*F) + X/(2+(n+1)*F);
            n++;
        }

        cout << "Case #" << i+1 << ": " << fixed <<  setprecision(7) << prec << "\n";

    }
}

int main()
{
    cookie();
    return 0;
}
