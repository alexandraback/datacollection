#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std ;

int main()
{
    int T , test = 1;

    cin >> T ;
    while ( T-- )
    {
        double C , F , X ;
        cin >> C >> F >> X ;
        double ans = (double)X / 2 ;

        double acc = 0 ;
        for ( int i = 1 ; ; ++i )
        {
            double t = (double)X / (i*F+2) ;

            acc += (double)C / ((i-1)*F+2) ;
            if ( ans > t+acc )
                ans = t+acc ;
            else
                break;

        }
        printf("Case #%d: %.10f\n",test++,ans);
    }

    return 0;
}
