#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
string s;
int main()
{
	int t;
	freopen("C:\\Users\\Gaurav\\Desktop\\al.in","r",stdin);
    freopen("C:\\Users\\Gaurav\\Desktop\\output.txt","w",stdout);
	scanf("%d",&t);
	int ca=0;
	while(t--)
	{
		ca++;
		int l,x;
		cin>>l;
		cin>>s;
		int i;
		int in=s[0]-'0';
		int fr=0;
		for(i=1;i<=l;i++)
		{
			if(in<i)
			{
				fr++;
				in++;
			}
			in=in+(s[i]-'0');
		}
		printf("Case #%d: %d\n",ca,fr);
	}
}
