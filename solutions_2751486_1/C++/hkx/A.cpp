#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <ctime>
#include <stdio.h>
#include <memory.h>
#include <windows.h>
using namespace std;
char st[1000005];
int n;

int f[1000000+5];
int main()
{
	freopen("A.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T,cas=0;
	cin>>T;
	while(T--)
	{
	    cas++;
	    printf("Case #%d: ",cas);
	    cin>>st;
	    int len=strlen(st);
	    cin>>n;
	    int i,j;
	    int s=0;
	    memset(f,0,sizeof(f));
	    for(i=0;i<len;i++)
	    {
	        if(st[k]!='a' && st[k]!='o' && st[k]!='e' && st[k]!='i' && st[k]!='u') s++;
	        else
	        {
	            if(s>=n)
	            {
	                for(j=i-s;j<=i-n;j++) f[j]=1;
	            }
	            s=0;
	        }
	    }
	    if(s>=n)
	    {
	        for(j=i-s;j<=i-n;j++) f[j]=1;
	    }
	    for(i=2;i<len;i++) f[i]=f[i-1]+f[i];
	    long long ans=0;
	    for(j=0;j<len;j++)
	    {
	    }
	}
    return 0;
}
