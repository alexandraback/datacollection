#include<iostream>
using namespace std;
int t,n,ans,a,b,tNum,dig;

int getDigits(int number)
{
    int t = 1;
    while (t * 10 <= number)
    {
          t *= 10;
    }
    return t;
}

int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out", "w", stdout);
    cin >> t;
    for (int test = 1; test <= t; ++test)
    {
        cin >> a >> b;
        ans = 0;
        for (int l = a; l <= b;++l)
        {
            tNum = l;
            dig = getDigits(tNum);
            while (1)
            {
                 int temp = (tNum % dig)*10 + tNum / dig;
                 if (temp > l && temp <=b)
                 {
                    ++ans;
                   // cout << l<< " " << temp <<endl;
                 }
                 tNum = temp;
                 if (tNum == l)
                    break;                      
            }
        }
        cout <<"Case #"<<test<<": "<<ans<<endl;
    }
}
