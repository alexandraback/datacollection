#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long a[10000];
int all=0;

long long work1(int i)
{
    long long rul=i;
    i/=10;
    while (i)
    {
        rul*=10;
        rul+=(i%10);
        i/=10;
    }
    return rul;
}

long long work2(int i)
{
    long long rul=i;
    while (i)
    {
        rul*=10;
        rul+=(i%10);
        i/=10;
    }
    return rul;
}

bool check(long long i)
{
    int a[20];
    int all=0;
    i*=i;
    while (i)
    {
        a[++all]=i%10;
        i/=10;
    }
    int b=1;
    int e=all;
    while (b<e)
    {
        if (a[b]!=a[e]) return false;
        b++;
        e--;
    }
    return true;
}


void prework()
{
    for (int i=1;i<=9999;i++)
    {
        long long k=work1(i);
        if (check(k)) a[++all]=k*k;
        k=work2(i);
        if (check(k)) a[++all]=k*k;
    }
    sort(a+1,a+all+1);
    //cout << all << endl;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    prework();
    int T;
    long long l,r;
    cin >> T;
    for (int t=1;t<=T;t++)
    {
        int ans=0;
        cin >> l >> r;
        for (int i=1;i<=all;i++)
            if (a[i]>=l && a[i]<=r) ans++;
        printf("Case #%d: %d\n",t,ans);
    }
}
