#include <cstdio>
#include <iostream>
using namespace std;

int T, N;

int digits_mask(int x)
{
    int result = 0;
    while(x > 0)
    {
        int last_digit = x % 10;
        result = result | (1 << last_digit);
        x = x / 10;
    }
    return result;
}

int main()
{
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cin >> N;
        
        if(N == 0)
        {
            cout << "Case #" << t << ": INSOMNIA\n";
            continue;
        }
        
        int mask = 0;
        int done = 0;
        int result = 0;
        while(!done)
        {
            result = result + N;
            mask = mask | digits_mask(result);
            if(mask == 1023)
                done = 1;
        }
        cout << "Case #" << t << ": " << result << "\n";
    }
    return 0;
}
