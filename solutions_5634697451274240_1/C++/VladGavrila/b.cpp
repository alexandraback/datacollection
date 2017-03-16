#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int t, n, m;
string s;

int main()
{
    freopen("B-Large.in", "r", stdin);
    freopen("data.out", "w", stdout);

    cin>>t;
    for(int test=1; test<=t; ++test)
    {
        cin>>s;
        n=s.size();

        int flip=0, sol=0;

        for(int i=n-1; i>=0; --i)
        {
            if((s[i]=='-' && flip==0) || (s[i]=='+' && flip==1))
            {
                flip=1-flip;
                ++sol;
            }
        }
        printf("Case #%d: %d\n", test, sol);
    }

    return 0;
}
