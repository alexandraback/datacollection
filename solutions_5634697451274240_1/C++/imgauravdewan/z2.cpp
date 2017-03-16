#include <bits/stdc++.h>
using namespace std;

char s[102];

void flip(int idx, string& str)
{
			reverse(&str[0],&str[idx+1]);
			for(int i=0;i<=idx;i++)
			if(str[i]=='-')
				str[i]='+';
			else
				str[i]='-';
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int kase=1;kase<=t;kase++)
	{
		scanf("\n%s",s);
		string str(s);
		int lastminus = str.size()-1;
		int ans = 0;
		while(true)
		{
		while(lastminus >=0 && str[lastminus] == '+')
			lastminus--;
		if(lastminus < 0)
			break;
		
		if(str[0] == '-')
		{
			flip(lastminus,str);
		}
		else
		{
			int firstminus = 0;
			while(str[firstminus]=='+')
				firstminus++;
			flip(firstminus-1,str);
		}
		ans++;
		}
		printf("Case #%d: %d\n",kase,ans);
	}
	return 0;
}
