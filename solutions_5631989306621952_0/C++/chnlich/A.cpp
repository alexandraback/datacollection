#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
int T,n;
char s[1010];

int main()
{
	freopen("A.in","r",stdin);
	
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		printf("Case #%d: ", tt);
		scanf("%s",s);
		n=strlen(s);
		char top = s[0];
		string output(1, top);
		for(int i=1;i<n;i++)
		{
			string tmp(1, s[i]);
			if (s[i]>=top) output = tmp + output, top=s[i];
			else output = output + tmp;
		}
		printf("%s\n", output.c_str());
	}
	return 0;
}