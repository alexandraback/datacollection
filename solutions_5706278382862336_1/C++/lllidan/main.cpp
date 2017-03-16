#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
#include <iomanip>
#include <ctime>
using namespace std;
#define INF 2147483646//0x7ffffff
#define eps 1e-9
#define pi 3.14159265358979626
#define LL long long
#define ULL unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define exch(a,b) {int t111=a;a=b;b=t111;}
#define zero(x) (((x)>0?(x):-(x))<eps)
#define read(a) scanf("%d",&a);
#define write(a) printf("%d\n",a);

#define N 50
#define MOD 1000000007
#define M 30005
#define NUM '0'

void ss()
{
    struct fac
    {
        int p, q;
    }s[2000];

    int num = 2;
    s[1].p = 0;
    s[1].q = 1;
    s[2].p = 1;
    s[2].q = 1;
    FOR(i, 1, 5)
    {
        int newnum = num;
        FOR(j, 1, num-1)
        FOR(k, j, num)
        {
            int a, b, c, d;
            a = s[j].p;
            c = s[j].q;
            b = s[k].p;
            d = s[k].q;
            int s1, s2;
            s1 = a*d + b*c;
            s2 = c*d*2;

            int s3 = __gcd(s1, s2);
            s1 /= s3;
            s2 /= s3;

            bool flag = true;
            FOR(l, 1, newnum)
            {
                if (s[l].p == s1 && s[l].q == s2)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                newnum++;
                s[newnum].p = s1;
                s[newnum].q = s2;
            }
        }

        num = newnum;
    }

    cout<<num<<endl;
    FOR(i, 1, num)
    {
        cout<<s[i].p<<' '<<s[i].q<<endl;
    }
}

int main()
{
    //freopen("A-large.in","r",stdin);
    //freopen("b.txt","w",stdout);
    //freopen("a.txt","r",stdin);
    //ss();
    //return 0;

    int T;
    LL p, q;
    LL a[42];
    a[0] = 1;
    a[1] = 2;
    FOR(i, 1, 40)
    a[i] = a[i-1] * 2;

    read(T);
    FOR(kk,1,T)
    {
        printf("Case #%d: ",kk);
        scanf("%lld/%lld", &p, &q);
        LL s = __gcd(p, q);
        p /= s;
        q /= s;
        //cout<<p<<' '<<q<<endl;

        s = q;
        while (s % 2 == 0)
            s /= 2;
        //cout<<s<<endl;
        if (s > 1)
        {
            //cout<<kk<<endl;
            puts("impossible");
            continue;
        }
        if (q == 1)
        {
            if (p != 0 && p != 1)
            {
                //cout<<kk<<endl;
                puts("impossible");
                continue;
            }
        }
        else
        {
            if (p >= q || (q % 2) !=0)
            {
                //cout<<kk<<endl;
                puts("impossible");
                continue;
            }
        }

        FOR(i, 1, 40)
        if (p * a[i] >= q && p * a[i-1] < q)
        {
            cout<<i<<endl;
            break;

        }
    }

    return 0;
}
