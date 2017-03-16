#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

double besttime;

double ct[123456];

int main()
{
    cout << fixed << setprecision(7);
    int T;
    cin >> T;
    
    for(int tt = 0; tt < T; tt++)
    {
        double C, F, X;
        
        cin >> C >> F >> X;
        
        double v = 2.0;
        
        double t = 0.0;
        
        besttime = (X / v);
        
        ct[0] = t;
        
        for(int c = 1; c < (int)(X / C) + 7; c++)
        {
            ct[c] = ct[c - 1] + (C / v);
            
            v += F;
            
            double time = ct[c] + (X / v);
            
            besttime = min(besttime, time);
        }
        
        cout << "Case #" << tt + 1 << ": " << besttime << '\n';
    }
    
    return 0;
}
