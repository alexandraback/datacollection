#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

main()
{
    int T;
    cin >> T;

    for (int x = 1; x <= T; ++x)
    {
        double C, F, X;
        cin >> C >> F >> X;

        double n = X/C - 1 - 2/F; // can be negative (don't buy)
        
        double t = 0;
        int i;
        for (i = 0; i < n; ++i)
            t += 1/(2 + i*F); // buy ceil(n) farms after reaching C
        t *= C;
        
        t += X / (2 + i*F);   // then run straight to the finish!


        cout << "Case #" << x << ": " << fixed << setprecision(7) << t << endl;

    }
}
