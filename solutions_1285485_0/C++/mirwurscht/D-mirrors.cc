#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <utility>
#include <cassert>
using namespace std;

typedef set<int> tSI;
typedef vector<string> tVS;
typedef pair<int,int> tPII;
typedef set<tPII> tSP;

int sqr(int a)
{
    return a*a;
}


int gcd(int a, int b)
{
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main()
{
    int T;
    cin >> T;

    for (int cases=1; cases<=T; cases++)
    {
        int H, W, D;
        cin >> H >> W >> D;
        string row;

        // We only solve the easy case and discard of most of the input.
        int xi = 0;
        int xj = 0;

        for (int i=0; i<H; i++)
        {
            cin >> row;
            size_t pos = row.find('X');
            if (pos != string::npos)
            {
                xi = i;
                xj = pos; 
            }
        }

        H -= 2;
        W -= 2;
        int two_x = 2*(xj-1)+1;
        int two_y = 2*(xi-1)+1;


        tSP good;
        int kup = int(double(D+two_x)/(2*W))+1;
        int lup = int(double(D+two_y)/(2*H))+1;
        for (int k=-kup; k<=kup; k++)
            for (int l=-lup; l<=lup; l++)
                for (int deltak=0; deltak<=1; deltak++)
                    for (int deltal=0; deltal<=1; deltal++)
                    {
                        int xoff = 2*k*W - deltak*two_x;
                        int yoff = 2*l*H - deltal*two_y;
                        if (abs(xoff) > D || abs(yoff) > D) continue;
                        if (abs(xoff) + abs(yoff) == 0) continue;

                        int dist2 = sqr(xoff) + sqr(yoff);
                        if (dist2 > D*D) continue;

                        int d = gcd(abs(xoff),abs(yoff));
                        xoff /= d;
                        yoff /= d;
                        
                        good.insert(tPII(xoff, yoff));
                    }
            
        int res = good.size();

        cout << "Case #" << cases << ": " << res << endl;
    }
}
