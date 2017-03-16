#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

bool isPowerOf2(long long int n)
{
    long long int t=1;
    while(t<=n)
    {
        if(t==n)
            return true;
        t*=2;
    }
    return false;
}

inline long long int mcd(long long int a, long long int b)
{
    long long int temp;
    if(a<b)
    {
        swap(a, b);
    }
    while(b!=0)
    {
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

int main(int argc, char* argv[])
{
    (void)argc; (void)argv;
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int t;
    cin >> t;
    for(int caso=1; caso<=t; caso++)
    {
        long long int num, den;
        char fuffa;
        cin >> num;
        cin >> fuffa;
        cin >> den;
        long long int m=mcd(num, den);
        num/=m;
        den/=m;
        if(isPowerOf2(den))
        {
            if(num>=den/2)
            {
                cout << "Case #" << caso << ": 1";
            }
            else
            {
                long long int sol=1;
                while(num<den/2)
                {
                    sol++;
                    num*=2;
                    m=mcd(num, den);
                    num/=m;
                    den/=m;
                }
                cout << "Case #" << caso << ": " << sol;
            }
        }
        else
        {
            cout << "Case #" << caso << ": impossible";
        }
        if(t!=caso)
            cout << endl;
    }
    return 0;
}
