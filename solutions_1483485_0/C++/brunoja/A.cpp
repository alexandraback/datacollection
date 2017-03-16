#include <cstdio>
#include <cstring>

char m[256], g[1000];
const char* a = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
const char* ra = "our language is impossible to understand";
const char* b = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
const char* rb = "there are twenty six factorial possibilities";
const char* c = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
const char* rc = "so it is okay if you want to just give up";

void build(const char* one, const char* two)
{
	for (int i = 0; one[i]; ++i)
		m[one[i]] = two[i]; 
	m['q'] = 'z';
	m['z'] = 'q';
}

bool check()
{
	for (int i = 'a'; i <= 'z'; ++i) if (!m[i])
	{
		printf("%c\n", i);
	}
}

int main()
{
	build(a, ra);
	build(b, rb);
	build(c, rc);
	//check();
	
	int t;
	scanf("%d ", &t);
	
	for (int q = 1; q <= t; ++q)
	{
		gets(g);
		printf("Case #%d: ", q);
		for (int i = 0; g[i]; ++i)
			printf("%c", m[g[i]]);
		printf("\n");
	}
	
	return 0;
}

