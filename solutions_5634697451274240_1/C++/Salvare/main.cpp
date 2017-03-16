#include<bits/stdc++.h>
using namespace std;


int main()
{
    freopen("1.in","r",stdin);
    freopen("2.txt","w",stdout);
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        char s[201];scanf("%s",s);
        int n=strlen(s),las=s[0],sum=0;
        for(int i=0;i<n;i++)
            if(las!=s[i])
            {
                sum++;
                las=s[i];
            }
        sum+=las=='-';
        printf("Case #%d: %d\n",ti++,sum);
    }
	return 0;
}
