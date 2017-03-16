#include<iostream>
#include<string>

using namespace std;
int n;
string v = "aeiou";
int ok(string s)
{
	int k=0;
	for(int i=0;i<s.size();i++)
	{
		for(int j=0;j<v.size();j++)
			if( s[i] == v[j])
			{
				k=-1;
				break;
			}
			k++;
			if( k == n )
				return 1;
	}
	return 0;
}
char str[10000];
int main()
{
	freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);
	int TC;
	scanf("%d",&TC);
	for(int tc=1;tc<=TC;tc++)
	{
		scanf("%s %d",str,&n);
		string s(str);
		int res = 0;
		for(int i=0;i<s.size();++i)
			for(int j=0;i+j<s.size();j++)
			{
				res += ok(s.substr(i,j+1));
			}
		printf("Case #%d: %d\n",tc,res);
	}
	return 0;
}