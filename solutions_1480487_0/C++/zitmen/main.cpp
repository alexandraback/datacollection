#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int sorted[200];
int s[200];
double ss[200];
bool active[200];

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        double sum = 0.0, min = INT_MAX, max = 0.0, rest = 0.0;
        int contestants;
        cin >> contestants;
        for(int c = 0; c < contestants; c++)
        {
            cin >> s[c];
            //sorted[c] = s[c];
            active[c] = true;
            sum += s[c];
            if(s[c] < min) min = s[c];
        }
        rest = sum;
        // vyradit zabezpeceny jedince
        bool removed = true;
        int rem = 0;
        while(removed)
        {
            removed = false;
            for(int c = 0; c < contestants; c++)
            {
                if(active[c])
                {
                    if(double(s[c]) >= ((sum / double(contestants-rem-1)) + min))
                    {
                        active[c] = false;
                        rem++;
                        removed = true;
                    }
                }
            }
        }
        //
        for(int c = 0; c < contestants; c++)
            if(active[c])
                if(s[c] > max)
                    max = s[c];
        //
        for(int c = 0; c < contestants; c++)
        {
            if(!active[c])
            {
                ss[c] = 0.0;
            }
            else
            {
                ss[c] = max - s[c];
                rest -= ss[c];
            }
        }
        rest = rest / double(contestants-rem);
        //
        cout << "Case #" << t << ':';
        for(int c = 0; c < contestants; c++)
        {
            cout << ' ' << setprecision(8) << (((ss[c] + (int(active[c])*rest)) / sum) * 100.0);
        }
        cout << '\n';
    }
    return 0;
}