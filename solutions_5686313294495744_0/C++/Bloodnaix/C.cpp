#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <cmath>
#include <memory.h>
#include <string>
#include <vector>
using namespace std;


int main()
{
    ifstream f1("C-small-attempt0.in");
    ofstream f2("C-small-attempt0.out");
    int T;
    f1 >> T;
    for(int t = 0; t < T; ++t)
    {
        f2 << "Case #" << t+1 << ": ";
        cout << "Case #" << t+1 << ": \n";
        int n;
        f1 >> n;
        string a[20], b[20];
        for(int i = 0; i < n; ++i)
        {
            f1 >> a[i] >> b[i];
        }
        int ans = -1;

        int mask;
        for(mask = 0; mask < (1 << n); ++mask)
        {
            //cout << mask << endl;
            bool flag = true;
            for(int i = 0; i < n ; ++i)
            {
                if(!(mask & (1 << i)))
                {
                    //cout << i << ' ';
                    // chech fake
                    bool f1 = false, f2 = false;
                    for(int j = 0; j < n; ++j)
                    {
                        if(mask & (1 << j))
                        {
                            if(a[i] == a[j])
                            {
                                f1 = true;
                            }
                            if(b[i] == b[j])
                            {
                                f2 = true;
                            }
                        }
                    }
                    if(!f1 || !f2)
                    {
                        flag = false;
                    }
                }
            }
            if(flag)
            {
                int kol = 0;
                for(int i = 0; i < n; ++i)
                {
                    if(!(mask & (1 << i)))
                        {
                            ++kol;
                        }
                }
                ans = max(ans, kol);
            }
            //cout << '-' <<flag << endl;
        }

        f2 << ans << endl;
    }
    return 0;
}

