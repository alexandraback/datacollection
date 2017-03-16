#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
int n;
string s;

bool vowel(char a)
{
	return (a=='a')||(a=='e')||(a=='i')||(a=='o')||(a=='u');
}
ll calc()
{
	ll ret=0;
	int l=s.size();
	int i=0,j=0; 
	int cnt=!vowel(s[0]);
	int x,y;
	if (cnt==1) x=y=0;
	else x=y=1;

	while(1)
	{
		while (cnt<n)
		{
			if (++j==l) return ret;
			if (!vowel(s[j]))
			{
				cnt++;
				y=j;
			}
			else
			{
				x=y=j+1;
			   	cnt=0;
			}
			if (cnt==n) break;
		}
		ret+=l-j;
		cnt-=(!vowel(s[i]) && x<=i && i<=y);
		i++;
	}
	return ret;
}
int main()
{
	int T;
	cin>>T;
	for (int run=1;run<=T;run++)
	{
		cin>>s>>n;
		printf("Case #%d: ",run);
		cout<<calc()<<endl;
	}
	return 0;
}
