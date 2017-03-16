#include <stdio.h>
#include <string.h>

char name [1000001];
int n;
int len;
int lastConst = -1;
int lastSubstringStart = -1;

bool isVovel(int x)
{
	return x=='a' || x=='e' || x=='i' || x=='o' || x=='u';
}

int constSubstringLen(int start)
{
	return lastConst - start + 1;
}

bool isNextConst()
{
	return lastConst+1 < len && !isVovel(name[lastConst + 1]);
}

int isNSubstring(int start)
{
	if(isVovel(name[start])) return false;
	if(lastConst < start) lastConst = start;

	while(constSubstringLen(start) < n)
	{
		if(isNextConst())
		{
			lastConst++;
		}
		else break;
	}
	return constSubstringLen(start) == n;
}

long long getPostfixCoount(int start)
{
	return len - start - n + 1;
}

long long getPrefixCount(int start)
{
	return start - lastSubstringStart;
}

long long getSubstringWithNAt(int start)
{
	long long val = getPrefixCount(start) * getPostfixCoount(start);
	
	lastSubstringStart = start;

	return val;
}

long long getNValue()
{
	long long total = 0;
	lastConst = -1;
	lastSubstringStart = -1;
	for(int start = 0; start<len; start++)
	{
		if(isNSubstring(start))
		{
			total += getSubstringWithNAt(start);
		}
	}
	return total;
}

int main()
{

	int count;
	scanf("%d", &count);

	for(int i=0; i<count; i++)
	{
		scanf("%s%d", name, &n);
		len = strlen(name);

		printf("Case #%d: %lld\n", i+1, getNValue());
	}
	return 0;
}
