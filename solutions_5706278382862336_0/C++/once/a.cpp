#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define LL long long
using namespace std;
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    LL a,b,c;
    int cnt,run;
    char ch;
    scanf("%d",&run);
    for (int cas=1;cas<=run;cas++)
    {
        cnt=0;
        cin >> a >> ch >> b;
        c=gcd(a,b);
        a/=c;b/=c;
        c=b;
        while (b%2==0)
        {
            cnt++;
            b/=2;
        }
        //printf("%I64d %d\n",b,cnt);
        printf("Case #%d: ",cas);
        if (b==1)
        {
            cnt=0;
            while (a<c)
            {
                a<<=1;
                cnt++;
            }
            cout << cnt << endl;
        }
        else
            cout << "impossible\n";
    }
    return 0;
}
