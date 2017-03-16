#include <iostream>
#include <limits>

using namespace std;

int i, t;
double c, f, x;
double speed, time;

int main()
{
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("output.out", "w", stdout);
    cout.precision(10);

    cin >> t;

    for(i = 1; i <= t; ++i)
    {
        cin >> c >> f >> x;
        speed = 2.0;
        time = 0.0;

        for(;;)
        {
            if(x / speed > c / speed + x / (speed + f))
            {
                time += c / speed;
                speed += f; 
            }
            else
            {
                time += x / speed;
                break;
            }
        }

        cout << "Case #" << i << ": " << time << endl;
    }

    return 0;
}