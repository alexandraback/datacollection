#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long testy,n,x,y,z,am,wyn,c;
string a,b;
int main()
{
    ios_base::sync_with_stdio(0);
    cin >> testy;
    for (int j=1; j<=testy; j++)
    {
        a.clear();
        b.clear();
        
        cin >> a >> n;
        for (int i=0; i<a.size(); i++)
        {
            if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
                b += '0';
            else
                b += '1';
        }
        
        x = 0;
        wyn = 0;
        am = 0;

        for (int i=0; i<b.size(); i++)
        {
            if (b[i] - 48 == 0)
                x = 0;
            else
            {
                x ++;
                if (x == n)
                {
                    y = i - n + 1 - am;
                    z = b.size() - i - 1;
                    c = 0;
                    y = max (c, y);
                    wyn += (z + z*y + 1 + y);
                    x --;
                    am = i - n + 2;
                }
            }
        }
        
        cout << "Case #" <<j<<": "<<wyn <<endl;
    }
    
cin.ignore(2);
return 0;
}
