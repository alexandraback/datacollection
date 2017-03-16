#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 9;
const int inf = 1e9 + 9;

int ans1[30],ans2[30];

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("out.txt","w",stdout);

	int t;
	scanf("%d", &t);
	int cass = 1;
	while (t--)
	{
	    string a,b;
	    cin>>a>>b;
	    int alen=a.length(),blen=b.length();
		printf("Case #%d: ", cass++);
		if(alen<blen)
        {
            for(int i=0;i<blen-alen;i++)
                a='0'+a;
        }
        else if(alen>blen)
        {
            for(int i=0;i<alen-blen;i++)
                b='0'+b;
        }
        int len=max(alen,blen);
        int flag=-1;
		for(int i=0;i<len;i++)
        {
            if(a[i]!='?' && a[i]!='0')
            {
                flag=i;break;
            }
            if(b[i]!='?' && b[i]!='0')
            {
                flag=i;break;
            }
            ans1[i]=ans2[i]=0;
        }
        for(int i=flag;i<len;i++)
        {
            if(a[i]=='?' && b[i]=='?')
            {
                if(i==0)
                {
                    ans1[i]=ans2[i]=0;
                }
                else
                {
                    if(ans1[i-1]==ans2[i-1])
                        ans1[i]=ans2[i]=0;
                    else if(ans1[i-1]>ans2[i-1])
                    {
                        ans1[i]=0,ans2[i]=9;
                    }
                    else if(ans1[i-1]<ans2[i-1])
                    {
                        ans1[i]=9,ans2[i]=0;
                    }
                }
            }
            else if(a[i]=='?' && b[i]!='?')
            {
                if(i==0)
                {
                    ans1[i]=ans2[i]=b[i]-'0';
                }
                else
                {
                    if(ans1[i-1]==ans2[i-1])
                        ans1[i]=ans2[i]=b[i]-'0';
                    else if(ans1[i-1]>ans2[i-1])
                    {
                        ans1[i]=0,ans2[i]=b[i]-'0';
                    }
                    else if(ans1[i-1]<ans2[i-1])
                    {
                        ans1[i]=9,ans2[i]=b[i]-'0';
                    }
                }
            }
            else if(a[i]!='?' && b[i]=='?')
            {
                if(i==0)
                {
                    ans1[i]=ans2[i]=a[i]-'0';
                }
                else
                {
                    if(ans1[i-1]==ans2[i-1])
                        ans1[i]=ans2[i]=a[i]-'0';
                    else if(ans1[i-1]>ans2[i-1])
                    {
                        ans1[i]=a[i]-'0';ans2[i]=9;
                    }
                    else if(ans1[i-1]<ans2[i-1])
                    {
                        ans1[i]=a[i]-'0';ans2[i]=0;
                    }
                }
            }
            else
            {
                ans1[i]=a[i]-'0',ans2[i]=b[i]-'0';
            }
        }
        for(int i=len-alen;i<len;i++)
            printf("%d",ans1[i]);
        printf(" ");
        for(int i=len-blen;i<len;i++)
            printf("%d",ans2[i]);
        printf("\n");
	}
	return 0;
}
