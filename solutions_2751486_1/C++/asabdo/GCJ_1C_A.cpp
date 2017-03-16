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
char str[10000000];
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
		long long res = 0;
		long long k = 0;
		long long last = 0;
		for(int i=0;i<s.size();++i)
		{
			for(int j=0;j<v.size();j++)
			{
				if( s[i] == v[j])
					k = -1;
			}
			++k;
			if( k >= n )
			{
				res += (i-n+1 - last+1) * (((long long)s.size())-i);
				last = i-n+2;
			}

		}
		//printf("Case #%d: %d\n",tc,res);
		cout<<"Case #"<<tc<<": "<<res<<endl;
	}
	return 0;
}