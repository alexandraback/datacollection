#include<stdio.h>
#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<string>
#include<cstring>
#include<cstdlib>
#include<math.h>
#include<algorithm>
#include<inttypes.h>
#include<stack>
#include<queue>
#include<set>
#define ull unsigned long long
#define ll long long
#define gc getchar_unlocked
#define pb push_back
#define mem(a,p) memset(a,p,sizeof(a))
#define ff first
#define ss second
using namespace std;

int retv(char c)
{
    if(c=='a')
        return 1;
    if(c=='e')
        return 1;
    if(c=='i')
        return 1;
    if(c=='o')
        return 1;
    if(c=='u')
        return 1;

     return 0;

}
int main()
{
    freopen("r.txt","r",stdin);
    freopen("first_small.txt","w",stdout);
    int t,l,i,j,c=1;
    scanf("%d",&t);
    int n;
    int res=0;
    char s[105];

    while(t--)
    {
        scanf("%s",s);
        l=strlen(s);
        scanf("%d",&n);
        res=0;
        for(i=0;i<l;i++)
        {
            for(j=i;j<l;j++)
            {
                int r=0;
                for(int k=i;k<=j;k++)
                {
                    if(retv(s[k])==0)
                      r++;
                     if(retv(s[k])==1)
                        r=0;
                    if(r==n)
                    {

                        res++;
                        break;
                    }

                }
            }
        }
        printf("Case #%d: %d\n",c++,res);
    }
    return 0;
}
