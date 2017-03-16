#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

string ans;

int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int ca,cn,i,x,y;

    cin >> cn;

    for(ca = 1;ca <= cn;ca++)
    {
        cin >> x >> y;

        ans = "";

        int n = abs(x),m = abs(y);

        for(i = 0;i < n;i++)
        {
            if(x > 0)
                ans.append("WE");
            else if(x < 0)
                ans.append("EW");
        }

        for(i = 0;i < m;i++)
        {
            if(y > 0)
                ans.append("SN");
            else if(y < 0)
                ans.append("NS");
        }

        cout << "Case #"<< ca <<": " << ans << endl;
    }
    return 0;
}
