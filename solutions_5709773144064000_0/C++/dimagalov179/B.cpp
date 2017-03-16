#include <fstream>

using namespace std;

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int t;
    cin >> t;
    for (int q = 0; q < t; ++q)
    {
        long double c, f, x;
        cin >> c >> f >> x;

        long double L = 0, R = 1000 * 1000;
        for (int it = 0; it < 300; ++it)
        {
            long double M = (L + R) / 2;
            long double time_left = M;
            long double current_speed = 2.0L;

            bool can_do = false;

            while (time_left > 0)
            {
                if (current_speed * time_left >= x)
                {
                    can_do = true;
                    break;
                }
                else
                {
                    if (c / current_speed <= time_left)
                    {
                        time_left -= c / current_speed;
                        current_speed += f;
                    }
                    else
                        break;
                }
            }
            if (can_do)
                R = M;
            else
                L = M;
        }
        cout.precision(200);
        cout << "Case #" << q + 1 << ": " << R << endl;
    }
}