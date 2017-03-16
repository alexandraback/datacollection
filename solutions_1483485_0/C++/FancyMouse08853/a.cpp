#include<cstdio>
#include<cstring>
using namespace std;

const int Samples = 4;
char samples[Samples][2][1024] = {
	{"ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand"},
	{"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities"},
	{"de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up"},
	{"y qee", "a zoo"},
};
char map[26] = {0};
bool build_map();
int main()
{
	if(!build_map())
	{
		printf("Fail to build map. Give more info!\n");
		return 1;
	}
	int T;
	scanf("%d", &T);
	char buf[1024];
	for(int _=1;_<=T;_++)
	{
		scanf(" %[^\n]", buf);
		printf("Case #%d: ",_);
		for(int i=0;buf[i];i++)
			printf("%c", buf[i]==' ' ? buf[i] : map[buf[i]-'a']);
		printf("\n");
	}
	return 0;
}
bool build_map()
{
	for(int i=0;i<Samples;i++)
		for(int j=0;samples[i][0][j];j++)
		{
			if(samples[i][0][j] == ' ') continue;
			char& t = map[samples[i][0][j]-'a'];
			if(t == 0) t = samples[i][1][j];
			else if(t != samples[i][1][j])
			{
				printf("Inconsistent map\n");
				return false;
			}
		}
	int filled = 0, missed;
	bool f[26];
	memset(f,false,sizeof(f));
	for(int i=0;i<26;i++)
		if(map[i])
		{
			filled++;
			f[map[i]-'a'] = true;
		}
		else
			missed = i;
	if(filled < 25)
	{
		printf("Insufficient info\n");
		return false;
	}
	if(filled == 25)
		for(int i=0;i<26;i++)
			if(!f[i])
				map[missed] = 'a'+i; //called only once
	return true;
}
