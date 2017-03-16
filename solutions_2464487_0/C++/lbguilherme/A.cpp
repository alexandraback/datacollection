#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
    int tcs;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; ++tc)
    {
        cout << "Case #" << tc << ": ";
        
        int64_t r, t;
        cin >> r >> t;
        
        ++r;
        int64_t c = 0;
        
        while (t > 0)
        {
            t -= 2*r - 1;
            r += 2;
            c += 1;
        }
        if (t < 0) --c;
        
        cout << c << endl;
    }
    return 0;
}