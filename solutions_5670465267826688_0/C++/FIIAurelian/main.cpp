#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;


int T,N,L,X, ok, i, j, x,prod,sign, minuss[4][4],res[4][4] = {{0,1,2,3},{1,0,3,2},{2,3,0,1},{3,2,1,0}};
string S,SS;

int main()
{
    freopen("file.in","r",stdin);
    freopen("file.out","w",stdout);
    minuss[1][1] = minuss[1][3] = minuss[2][1] = minuss[2][2] = minuss[3][2] = minuss[3][3] = 1;

    cin>>T;
    for(int t = 1; t <= T; t++)
    {
        cout<<"Case #"<<t<<": ";
        cin>>L>>X;
        cin>>SS;
        ok = 0;
        S.clear();
        while(X--)
        {
            S = S + SS;
        }
        prod = 0;
        sign = 0;
        for(int i = 0; i < S.size(); i++)
        {
            x = S[i] - 'i' + 1;
            sign = sign ^ minuss[prod][x];
            prod = res[prod][x];
            if(sign == 0 && prod == 1 && ok == 0)
                ok = 1;
            if(sign == 0 && prod == 3 && ok == 1)
                ok = 2;
        }
        if(ok == 2 && prod == 0 && sign == 1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
