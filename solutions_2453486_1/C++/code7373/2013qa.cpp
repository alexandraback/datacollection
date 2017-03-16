#include <cstdio>
#include <conio.h>
#include <ctime>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>
using namespace std;

#define fr(a,b,c) for(a=(b); a<(c); ++a)
#define fo(a,c) fr((a),0,(c))
#define fo1(a,c) fr((a),1,(c))
#define fi(n) fo(i,(n))
#define fj(n) fo(j,(n))
#define fk(n) fo(k,(n))
#define fi1(n) fo1(i,(n))
#define fj1(n) fo1(j,(n))
#define fk1(n) fo1(k,(n))

#define ni(n) scanf("%d", &n)
#define nf(n) scanf("%f", &n)
#define nd(n) scanf("%lf", &n)
#define ns(n) scanf("%s", n)
#define nl(n) scanf("%ld", &n)
#define nll(n) scanf("%lld", &n)
#define nllu(n) scanf("%llu", &n)


int C, TC=1;

typedef long long ll;
int i,j;
int main()
{
    for (scanf ("%d", &C); TC <= C; TC++)
    {
////////////////////////////////////
        char s[5][5];
        bool bd=true;
        fi(4)
        {
            cin>>s[i];
            fj(4)
            if(s[i][j]=='O')s[i][j]=1;
            else if(s[i][j]=='X')s[i][j]=2;
            else if(s[i][j]=='T')s[i][j]=3;
            else {
                s[i][j]=0;
                bd=false;
            }
        }
        char res=3;
        fi(4)
        {
            res=3;
            fj(4)
                res &= s[i][j];
                if(res !=0)
                    goto out1;
        }
        fi(4)
        {
            res=3;
            fj(4)
                res &= s[j][i];
                if(res !=0)
                    goto out1;
        }
        res = 3;
        fi(4)
                res &= s[i][i];
                if(res !=0)
                    goto out1;
        res = 3;
        fi(4)
                res &= s[3-i][i];

        ;
out1:        if(res == 1)
            cout<<"Case #"<<TC<<": "<<"O won"<<endl;
        else if(res == 2)
            cout<<"Case #"<<TC<<": "<<"X won"<<endl;
        else if(bd)
            cout<<"Case #"<<TC<<": "<<"Draw"<<endl;
        else
            cout<<"Case #"<<TC<<": "<<"Game has not completed"<<endl;

////////////////////////////////////
    }
    return 0;
}
