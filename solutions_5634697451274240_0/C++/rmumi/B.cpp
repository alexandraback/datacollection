#include <bits/stdc++.h>
#define mp make_pair
#define xx first
#define yy second
#define pb push_back
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    char s[150];
    for(int CASE=1;CASE<=T;CASE++)
    {
        scanf(" %s",s);
        int len=strlen(s),raz=1;
        for(int i=1;s[i];i++)
            if(s[i]!=s[i-1])raz++;
        printf("Case #%d: %d\n",CASE,raz+(s[len-1]=='-')-1);
    }
    return 0;
}
