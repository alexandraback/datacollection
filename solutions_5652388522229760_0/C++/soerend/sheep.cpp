#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    for (int x = 1; x <= t; ++x)
    {
        int n;
        cin >> n;
        if (n == 0) {
            cout << "Case #" << x << ": INSOMNIA" << endl;
            continue;
        }
        int seen = 0;
        int nums[10];
        memset(nums,0,sizeof(nums));
        for (unsigned long long i = n; ; i += n)
        {
            unsigned long long y = i;
            while (y > 0) {
                if (nums[y%10] == 0) {
                    ++seen;
                    nums[y%10] = 1;
                }
                y /= 10;
            }
            if (seen == 10) {
                cout << "Case #" << x << ": " << i << endl;
                break;
            }
        }
    }
}
