#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#define cin fin
#define cout fout
using namespace std;

int a[200];

int main()
{
    ifstream fin("A-small-attempt0.in");
    ofstream fout("out.txt");
    int i,j,k,CASE,t,ans,n,now,A;
    cin >> CASE;
    for (t=1;t<=CASE;t++)
    {
        cin >> A >> n;
        for (i=1;i<=n;i++)
            cin >> a[i];
        sort(a+1,a+1+n);
        ans = n;
        now=0;
        i=1;
        if (A!=1)
        while (i<=n)
        {
            if (A>a[i])
            {
                A+=a[i];
                ans = min(ans,now+n-i);
                i++;
            }
            else {
                A+=A-1;
                now++;
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }


    return 0;
}
