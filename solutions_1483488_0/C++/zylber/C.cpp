#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <math.h>
#include <set>
using namespace std;

int main()
{
    freopen("testC.in","r",stdin);
    freopen("testC.out","w",stdout);

    int T;
    cin >> T;
    for(int tc=1; tc<=T; tc++)
    {
        int A, B;
        cin >> A >> B;
        int s=B, c=1, d=0;
        while(s>0)
        {
            c*=10;
            d++;
            s/=10;
        }

        int cant=0;
        for(int i=A; i<B; i++)
        {
            int n=i;
            int a=0, b=1;
            for(int j=1; j<d; j++)
            {
                n+=c*(n%10);
                n/=10;
                if(n<=B && n>i)
                {
                    a++;
                }
                else
                if(n==i)
                b++;
            }
            cant+=a/b;
        }

        cout << "Case #" << tc << ": " << cant << endl;
    }
    return 0;
}
