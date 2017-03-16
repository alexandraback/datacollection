#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
vector <long long> fns;
bool pal(long long n)
{
    char str[101];
    sprintf(str,"%lld",n);
    int i = 0, j = strlen(str)-1;
    while( i <= j)
    {
        if(str[i] != str[j])
        {
            return 0;
        }
        i++,j--;
    }
    return 1;

}
int main()
{
    int t;
    long long a,b;
    //freopen("a2.in","r",stdin);
    long long x;
    for( x = 1 ; x <= 10000000; x++)
    {
        if( pal(x) && pal(x*x))
        {
            fns.push_back(x*x);
        }
    }
    scanf("%d",&t);
    for(int i = 1; i <= t; i++)
    {
        scanf("%lld%lld",&a,&b);
        int ans = 0;
        for( int j = 0; j <= fns.size(); j++)
        {
            if( fns[j] >= a && fns[j] <= b)
            {
                ans++;
            }
            if(fns[j]>b)
                break;
        }
        printf("Case #%d: %d\n",i,ans);
    }
}
