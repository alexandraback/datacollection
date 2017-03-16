#include <bits/stdc++.h>
using namespace std;

int gen(int n)
{
    int N=0;
    while(n>0)
    {
        N = N*10 + (n%10);
        n/=10;
    }
    return N;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("in.in","r",stdin);
    freopen("output.out","w",stdout);
    int cases,caseno=0,n,i,temp,a[1000005];

    cin >> cases;

    memset(a,-1,sizeof(a));

    a[0] = 0;

    for(i=1; i<11; i++)
        a[i] = a[i-1]+1;

    for(i=11; i<1000001; i++)
    {
        temp = gen(i);
        if(temp!=i && i%10!=0 && a[temp]!=-1)
            a[i] = min(a[temp]+1, a[i-1]+1);
        else
            a[i] = a[i-1]+1;
    }

    while(cases--)
    {
        cin >> n;

        cout << "Case #" << ++caseno << ": " << a[n] << '\n';
    }

    return 0;
}


