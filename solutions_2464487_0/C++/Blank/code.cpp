#include <iostream>
using namespace std;
void main()
{
    int T;
    cin >> T;
    for(int C=0; C<T; ++C)
    {
        int r, t;
        cin >> r >> t;
        int s = r;
        int result = 0;
        int n=s+1;
        while(true)
        {
            int val = (n * n) - ((n-1)*(n-1));
            //cout << ":" << val << "," << n << endl;
            if(t - val<0)
            {
                break;
            }
            ++result;
            t-=val;
            n+=2;
        }
        printf("Case #%d: %d\n", C+1, result);
    }

}