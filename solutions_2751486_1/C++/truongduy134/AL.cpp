#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_LEN 1000000

bool hasNConsecutiveConsonant(char str[], int s, int n);
unsigned long long getNValue(char str[], unsigned long long n);
bool isConsonant(char c);

int main(void)
{
	int T, n, caseId;
	char str[MAX_LEN + 1];

	scanf("%d", &T);
	caseId = 1;
	while(caseId <= T)
	{
		scanf("%s %d", str, &n);

		printf("Case #%d: %llu\n", caseId, getNValue(str, n));

		caseId++;
	}
	return 0;
}

unsigned long long getNValue(char str[], unsigned long long n)
{
	int len = (int) strlen(str);
	unsigned long long count = 0;

	int start = 0;
	bool startFlg = true, notCheck = false;
	for(int i = 0; i < len;)
	{
		if(notCheck || hasNConsecutiveConsonant(str, i, n))
		{
			count += (len - i - n + 1) * (unsigned long long) (i - start + 1);
	
			if(i + n < len && isConsonant(str[i + n]))
			{
				start = i + 1;
				i++;
				notCheck = true;
			}
			else
			{
				start = i + 1;
				i += n;
				startFlg = false;
				notCheck = false;
			}
		}
		else
		{
			if(startFlg)
			{
				startFlg = false;
				start = i;
			}
			i++;
			notCheck = false;
		}
	}

	return count;
}

bool hasNConsecutiveConsonant(char str[], int s, int n)
{
	int i, maxLen = 0, len = 0, count = 0;

	for(i = s; i < s + n; i++)
		if(!isConsonant(str[i]))
			return false;
		else
			count++;

	if(count == n)
		return true;
	return false;
}

bool isConsonant(char ch)
{
	if(ch != 'a' && ch != 'e' && ch != 'i'
			&& ch != 'o' && ch != 'u')
		return true;
	return false;
}
