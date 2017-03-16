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
char st[105];
int n;
bool isok(int i,int n)
{
    int k,flag=0;
    for(k=i;k<=i+n-1;k++)
    {
        if(st[k]=='a' || st[k]=='o' || st[k]=='e' || st[k]=='i' || st[k]=='u')
        {
            flag=1;break;
        }
    }
    if(flag==1) return false;
    return true;
}
bool check(int i,int j)
{
    int k,x,y;
    int flag=0;
    int s=0;
    for(k=i;k+n-1<=j;k++)
    {
        if(isok(k,n)) return true;
    }
    return false;
}
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
	    int ans=0;
	    for(i=0;i<len;i++)
	    {
	        for(j=i;j<len;j++)
	        {
	            if(check(i,j)) ans++;
	        }
	    }
	    cout<<ans<<endl;
	}
    return 0;
}
