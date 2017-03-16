#include <cstdio>
char map[256]={};

void solve(int t)
{
	char s[110];
	gets(s);
	printf("Case #%d: ",t);
	for (char *c=s;*c;++c)
		if (map[*c])
			putchar(map[*c]);
		else
			throw;
	putchar('\n');
}

int main()
{
	freopen("input.txt","r",stdin);
	map['q'] = 'z';
	char in[] = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
	char ou[] = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";
	for (char *i=in,*o=ou;*i;++i,++o)
		map[*i] = *o;
	bool used[256]={};
	for (char c = 'a';c<='z';++c)
		used[map[c]] = 1;
	for (char c = 'a';c<='z';++c)
		if (!used[c])
			map['z'] = c;
	int T;
	scanf("%d",&T);
	gets(in);
	for (int t=0;t<T;++t)
		solve(t+1);
	return 0;
}
