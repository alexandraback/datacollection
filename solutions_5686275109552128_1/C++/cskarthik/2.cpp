#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int T;
    cin >> T;
    for(int k=1; k<=T; k++)
    {
        int D, *a;
        cin >> D;
        a = new int[D];
        int max=0, res=0;
        for(int i = 0; i<D; i++)
        {
            cin >> a[i];
            if(a[i] > max)
                max = a[i];
        }
        res = max;
        int e = 2;
        while(e < res)
        {
            int sum = 0;
            for(int i=0; i<D; i++)
            {
                sum += (a[i] - 1)/e;
            }
            sum += e;
            res = (res < sum) ? res : sum; 
            e++;
        }
        cout << "Case #" << k << ": " << res << endl;  
        delete[] a;
    }
    return 0;
}