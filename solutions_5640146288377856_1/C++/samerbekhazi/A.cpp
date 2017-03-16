#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T;
    cin >> T;
    int R,C,W;
    for(int t=0; t<T; t++)
    {
        cin >> R >> C >> W;

        int res;
        if(C%W==0)
            res = R*(C/W) + (W-1);
        else
            res = R*(C/W) + W;

        cout << "Case #" << t+1 << ": " << res << endl;
    }
    return 0;
}
