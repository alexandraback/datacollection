#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>

using namespace std;

long double solve(int N, long double D, vector<long double> time, vector<long double> position, long double acceleration)
{
    if(N == 1)
    {
        return max((long double)sqrt((long double)2 * D / acceleration), D / position[0] * time[0]);
    }
    if(N == 2)
    {
        long double ratio = (position[1] - position[0]) / (D - position[0]);
        position[1] = position[0] + (position[1] - position[0]) / ratio;
        time[1] = time[0] + (time[1] - time[0]) / ratio;
        if(0.5 * acceleration * time[0] * time[0] < position[0])
        {
            if(0.5 * acceleration * time[1] * time[1] < position[1])
            {
                // Front car is not a limit
                return sqrt(2 * D / acceleration);
            }
            else
            {
                // Front car a limit only during the second half
                return time[1];
            }
        }
        else
        {
            long double speed = sqrt(2 * acceleration * position[0]);
            return max(time[1], time[0] + (-speed + sqrt(speed * speed - 2 * acceleration * (position[0] - D))) / acceleration);
            // return max(time[1], (-speed + sqrt(speed * speed + 2 * acceleration * D)) / acceleration);
        }
    }

    return -1;
}

int main(int argc, char *argv[])
{
    cout.unsetf(ios::floatfield);
    cout.precision(10);
    int T;
    cin >> T;

    for(int counter = 1; counter <= T; counter++)
    {
        long double D;
        cin >> D;
        int N, A;
        cin >> N >> A;

        vector<long double> time;
        vector<long double> position;
        for(int n = 0; n < N; n++)
        {
            long double t, p;
            cin >> t >> p;
            time.push_back(t);
            position.push_back(p);
        }

        vector<long double> acceleration;
        for(int a = 0; a < A; a++)
        {
            long double accel;
            cin >> accel;
            acceleration.push_back(accel);
        }

        cout << "Case #" << counter << ":\n";
        for(int a = 0; a < A; a++)
        {
            cout << solve(N, D, time, position, acceleration[a]) << "\n";
        }
    }

    return 0;
}
