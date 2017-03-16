#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
string s;
int n,ans;
char x;
int main()
{
	//freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int casei=1;casei<=n;casei++)
	{
		cin>>s;ans=0;x='+';
		for(int i=s.length()-1;i>=0;i--)
		{
			if(s[i]!=x)
			{
				x=s[i];
				ans++;
			}
		}
		printf("Case #%d: %d\n",casei,ans);
	}
}
