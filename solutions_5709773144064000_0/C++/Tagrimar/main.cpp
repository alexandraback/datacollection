#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;


int main(int argc, const char * argv[])
{
    ifstream cin("B-small-attempt1.in.txt");
    ofstream cout("B-small-attempt1.out.txt");
    
    int T;
    cin>>T;
    for(int q = 0; q < T; q++)
    {
        long double c, f, x;
        cin >> c >> f >> x;
        long double result = 1e15;
        long double current_time = 0;
        long double inc = 2;
        for(int i = 0;; i++) {
            result = min(result, current_time + x/inc);
            if(result + 1< current_time + x/inc)
                break;
            current_time += c/inc;
            inc += f;
        }
        cout << fixed << setprecision(8) << "Case #" << q + 1 << ": " << result << "\n";

    }
    
}

