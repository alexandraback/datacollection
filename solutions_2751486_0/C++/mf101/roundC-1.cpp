#include <iostream>
#include<algorithm>
#include<cstring>


using namespace std;

const int MAX = (int)1e6 + 5;
char str[MAX];

bool is_vowel(char c)
{
	if(c == 'a'|| c == 'e'|| c == 'i' || c == 'o' || c=='u')
		return true;
	
	return false;
}

int main()
{

	int test;
	scanf("%d",&test);

	for(int t = 1 ; t <= test; t++)
	{
		int n;

		scanf("%s %d", str,&n);

		int len = strlen(str);
		int cut = 0, prev = 0, next = 0, n_cnt = 0;
		
		long long ans = 0;

		for(int i = 0 ; i < len; i++)
		{
			if(is_vowel( str[i]))
			{
				prev = str[i+1];
				n_cnt = 0;
			}
			else
			{
				if(!n_cnt) prev = i;
				if(n_cnt < n)n_cnt++;
			}

			if(n_cnt == n)
			{
				next = i;
				ans += (long long)(len - next) * (long long)(prev - cut+1);
				cut = ++prev;
			}

		}

		printf("Case #%d: %d\n",t,ans);
	}

	return 0;
}