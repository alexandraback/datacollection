#include <iostream>
#include <cstdio>

using namespace std;

bool jd1(char s[][5])
{
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j)
		{
			if(s[i][j]=='.')return true;
		}
		return false;
}

char jd2(char a[4])
{
	for(int i = 0; i <4; ++i)
		if(a[i]=='.')return 0;
	char c = a[0];
	if(c=='T') c = a[1];
	for(int i = 1; i < 4; ++i)
	{
		if(a[i]=='T')continue;
		if(c!=a[i])return 0;
	}
	return c;
}

char judge(char s[][5])
{
	bool flag = false;
	char tmp[4];
	for(int i = 0; i <4;++i)
	{
		for(int j = 0; j < 4; ++j)
			tmp[j] = s[i][j];
		int x= jd2(tmp);
		if(x)return x; 
	}
	for(int i = 0; i <4;++i)
	{
		for(int j = 0; j < 4; ++j)
			tmp[j] = s[j][i];
		int x= jd2(tmp);
		if(x)return x; 
	}
	for(int i = 0; i <4;++i)
		tmp[i] = s[i][i];
	int x= jd2(tmp);
	if(x)return x; 
	for(int i = 0; i <4;++i)
		tmp[i] = s[3-i][i];
	x= jd2(tmp);
	if(x)return x; 
	return false;
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A.out","w",stdout);
	int T;
	char s[4][5];
	scanf("%d",&T);
	for(int i = 0; i < T; ++i)
	{
		for(int j = 0; j < 4; ++j)
		{
			scanf("%s",s[j]);
			//printf("test: %s\n",s[j]);
		}
		//scanf("\n");
		cout<<"Case #"<<i+1<<": ";
		char ss= judge(s);
		if(ss)
		{
			cout<<ss<<" "<<"won"<<endl;
		}
		else
		{
			if(!jd1(s))
			{
				cout<<"Draw"<<endl;
			}
			else
			{
				cout<<"Game has not completed"<<endl;
			}
		}
	}
	return 0;
}