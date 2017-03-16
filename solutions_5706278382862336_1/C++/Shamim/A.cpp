#include<cstdio>
#include<ctype.h>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include<iostream>
#include<sstream>


using namespace std;

#define re return
#define co continue
#define pb push_back
#define br break
#define sz size


#define pf printf
#define sf scanf

long long GetGCD(long long A, long long B)
{
    if (A%B == 0 )
        return B;
    return GetGCD(B,A%B);
}

bool IsTwoPower(long long A)
{
   // cout<<A<<" ";
    long long num = 1;
    while ( num< A)
        num *= 2;
    if ( num == A)
        return true;
    return false;
}

int main()
{

   //freopen("sample.txt","r",stdin);
    freopen("A.in","r",stdin);
    freopen("ans.txt","w",stdout);

    int t;
    cin>>t;
    int kase=1;
    while ( t--)
    {
        pf("Case #%d: ",kase++);
        long long P,Q;
        sf("%lld/%lld",&P,&Q);
        int counter=40;
        int gen = 0;
        while (counter--)
        {
            gen++;
            long long C = P*2-Q;
            long long D = Q;
            long long GD = GetGCD(C,D);
            C /= GD;
            D /= GD;

            if ( C >= 0 && C<=D ) // valid fraction
                if ( IsTwoPower(D))
                    break;
            // invalid fraction
            long long X = P*2;
            long long Y = Q;
            long long GCD = GetGCD(X,Y);
            //long long GCD = 1;
            X /= GCD;
            Y /= GCD;
            P = X;
            Q = Y;
           // cout<<P<<" "<<Q<<" ";
            if ( P > Q)
            {
                counter = 0;
                break;
            }
        }
        if ( counter > 0)
            cout<<gen;
        else
            cout<<"impossible";
        cout<<endl;

    }
    return 0;
}
