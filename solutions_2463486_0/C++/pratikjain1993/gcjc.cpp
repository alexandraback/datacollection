#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
bool pal(int n)
{
    char str[101];
    sprintf(str,"%d",n);
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
    int t,a,b;
    //freopen("a2.in","r",stdin);
    scanf("%d",&t);
    for(int i = 1; i <= t; i++)
    {
        int ans = 0;
        scanf("%d%d",&a,&b);
        int x;
        for( x = 1 ; x*x<=b; x++)
        {
            if( pal(x) && pal(x*x) && x*x >= a)
            {
                ans++;
            }
        }
        printf("Case #%d: %d\n",i,ans);
    }
}
