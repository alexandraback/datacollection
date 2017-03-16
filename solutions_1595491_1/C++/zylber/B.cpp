#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <math.h>
#include <set>
using namespace std;

bool compa(int a, int b)
{
    return (a>b);
}

int main()
{
    freopen("testB.in","r",stdin);
    freopen("testB.out","w",stdout);
    int T;
    cin >> T;
    for(int tc=1; tc<=T; tc++)
    {
        int N, S, p, cant=0;
        cin >> N >> S >> p;
        vector <int> t(N);
        for(int i=0; i<N; i++)
        cin >> t[i];
        sort(t.begin(),t.end(),compa);

        for(int i=0; i<N; i++)
        {
            if(t[i]>=3*p-2)
            cant++;
            else
            if(t[i]>=max(3*p-4,2) && S>0)
            {
                S--;
                cant++;
            }
        }
        cout << "Case #" << tc << ": " << cant << endl;
    }
    return 0;
}
