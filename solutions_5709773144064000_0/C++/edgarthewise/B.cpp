#include <iostream>
#include <iomanip>
using namespace std;

const double R = 2.0; // base rate w/o factories

int main()
{
    int T; cin >> T;
    std::cout << std::fixed;
    std::cout << std::setprecision(7);
    
    for(int t=1; t<=T; t++)
    {
        double C, F, X;
        cin >> C >> F >> X;
        
        double bestTime = X / R;

        double timeToFactories = 0;
        double capacity = R;
        while (true)
        {
            timeToFactories += C / capacity;
            capacity += F;
            /*cerr << timeToFactories << endl << capacity << endl <<
                bestTime << endl<< endl;*/
            double currTime = timeToFactories + X / capacity;
            if (bestTime > currTime)
                bestTime = currTime;
            else
                break;
        }
        
        cout << "Case #"<<t<<": "<<bestTime << endl;
        //cerr <<t<<endl;
    }
}
