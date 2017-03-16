#include<iostream>
#include<string>
#include<map>
#include<hash_map>
using namespace std;
hash_map<char,char> Mapping;
void GETMapping()
{
	string END[3] = {
		"ejp mysljylc kd kxveddknmc re jsicpdrysi",
		"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
		"de kr kd eoya kw aej tysr re ujdr lkgc jv"
	};
	string REAL[3] = {
		"our language is impossible to understand",
		"there are twenty six factorial possibilities",
		"so it is okay if you want to just give up"
	};
	Mapping['q']='z';
	Mapping['z']='q';
	for(int i=0;i<3;++i)
		for(int j=0;j<END[i].length();++j)
			Mapping[END[i][j]]=REAL[i][j];

}
void Process()
{
	freopen("A-small-attempt.in", "r", stdin);
	freopen("A-small_out.txt", "w", stdout);
	int n;
	scanf("%d\n",&n);
	string s;
	for(int i=1;i<=n;i++)
	{
		getline(cin, s);
		for(int j=0;j<s.length();++j)
		{
			s[j]=Mapping[s[j]];
		}
		printf("Case #%d: %s\n", i, s.c_str());
	}
}
int main()
{
	GETMapping();
	Process();
	return 0;
}