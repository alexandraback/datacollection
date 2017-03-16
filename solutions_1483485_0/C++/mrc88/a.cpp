#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

char s[200];
char d[300];

string fst = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
string snd = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";

void decode()
{
	d['q'] = 'z';
	d['z'] = 'q';
	for(int i = 0; i < fst.size(); ++i)
	{
		d[fst[i]] = snd[i];
	}
}

inline string S()
{
	string res = "";
	for(int i = 0; s[i] != '\0'; ++i)
	{
		if(s[i] == ' ') res += ' ';
		else res += d[s[i]];
	}
	return res;
}

int main()
{
	decode();
	//for(int i='a'; i<='z'; ++i) printf("%c = %c\n", i, d[i]);
	int cases;
	scanf("%d\n", &cases);
	for(int icases = 1; icases <= cases; ++icases)
	{
		gets(s);
		printf("Case #%d: %s\n", icases, S().c_str());
	}
	return 0;
}