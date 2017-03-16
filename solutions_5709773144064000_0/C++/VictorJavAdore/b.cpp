#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

int T;
double C,F,X;
double speed,elapsed;

int main()
{
    cin >> T;
    for(int t=1; t<=T; t++)
    {
        cin >> C >> F >> X;
        elapsed = 0;
        speed = 2;
        //cout << "Initial speed: " << speed << endl;
        while(C/speed + X/(speed+F) < X/speed)
        {
            //cout << "\tBuying a new farm..." << endl;
            elapsed += C/speed;
            //cout << "\t\tIt took " << C/speed << " seconds." << endl;
            speed += F;
            //cout << "\tNew speed: " << speed << endl;
        }
        //cout << "\tNow going for the final goal of " << X << " cookies!" << endl;
        elapsed += X/speed;
        //cout << "\t\tIt took " << X/speed << " seconds." << endl;

        printf("Case #%d: %.7f\n", t, elapsed);
    }
}
