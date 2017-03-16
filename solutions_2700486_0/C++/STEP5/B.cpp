#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 20202;

double C[MAXN][MAXN/2+30];

void calc()
{
    C[0][0] = 1.0;
    for(int i=1; i<MAXN; i++)
    {
        for(int j=0; j<=i && j<=10010; j++)
        {
            //if(j>0)C[i][j] = C[i][j-1];
            if(j>0)C[i][j] += C[i-1][j-1]*0.5;
            if(j<i)C[i][j] += C[i-1][j]*0.5;
        }
    }

    for(int i=1; i<MAXN; i++)
    {
        for(int j=1; j<=i && j<=10010; j++)
        {
            C[i][j] += C[i][j-1];
            //if(i<10)cout<<i<<"/"<<j<<":"<<C[i][j]<<endl;
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);
    calc();

    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        int N, X, Y;
        cin>>N>>X>>Y;
        int l = (abs(X) + Y) / 2;
        int rem = N - l*(2*l-1);

        double ans;
        ///cout<<l<<" / "<<rem<<endl;
        if(X==0)
        {
            if(rem >= 4*l+1) ans = 1.0;
            else ans = 0.0;
        }
        else if(rem <= 2*l - abs(X))ans = 0.0;
        else if(rem > 4*l - abs(X))ans = 1.0;
        else
        {
        	int q = 2*l-abs(X);
        	///cout<<q<<endl;
        	if(q<=rem/2)ans = 1 - C[rem][q];
        	else ans = C[rem][rem-q-1];
            //ans = 0.5;
        }
        printf("Case #%d: %.7f\n", t, ans);
    }

    return 0;
}
