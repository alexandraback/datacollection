#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int t;
string s1;
string s2;

int out1,out2;
int minn;

int tab[4]={0,9,99,999};

bool pending(int x, int y)
{
	int i;
	for(i=s1.length()-1;i>=0;i--)
	{
		if(s1[i]!='?'&&(x%10)!=(s1[i]-'0'))return false;
		x/=10;
	}
	if(x)return false;
	for(i=s2.length()-1;i>=0;i--)
	{
		if(s2[i]!='?'&&(y%10)!=(s2[i]-'0'))return false;
		y/=10;
	}
	if(y)return false;
	return true;
}

int numlen(int x)
{
	if(x<10)return 1;
	if(x<100)return 2;
	return 3;
}

int main()
{
	int i,j,k;
	int tcase=1;

	freopen("B.in","r",stdin);
	freopen("B","w",stdout);

	cin>>t;
	for(i=1;i<=t;i++)
	{
		minn=1000000;
		cin>>s1>>s2;
		for(j=0;j<=tab[s1.length()];j++)
		{
			for(k=0;k<=tab[s2.length()];k++)
			{
				if(pending(j,k))
				{
					if(abs(j-k)<minn)
					{
						minn=abs(j-k);
						out1=j;
						out2=k;
					}
				}
			}
		}
		cout<<"Case #"<<tcase++<<": ";

		for(j=numlen(out1);j<s1.length();j++)cout<<"0";
		cout<<out1<<" ";
		for(j=numlen(out2);j<s2.length();j++)cout<<"0";
		cout<<out2<<endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
