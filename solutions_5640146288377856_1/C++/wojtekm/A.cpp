#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for(int t=1; t<=T; t++)
    {
        int r, c, w;
        cin >> r >> c >> w;

        cout << "Case #" << t << ": " << ((c/w)*r)+(w-1)+(c%w==0?0:1) << "\n";
    }

    return 0;
}

