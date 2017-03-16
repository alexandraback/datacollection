#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int T,L;
int n;
char word[1000001];
int suc[1000001];
int len;

bool isVowel(char ch)
{
	return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main(void)
{
	int i,j;
	scanf(" %d",&T);
	for(i=1;i<=T;i++)
	{
		scanf(" %s %d",word, &n);
		len = strlen(word);
		int curr = 0;
		for(j=len-1;j>=0;j--)
		{
			if(!isVowel(word[j])) curr ++;
			else curr = 0;
			if(curr >= n) suc[j] = 1;
			else suc[j] = 0;
		}
		
		long long int res = 0;
		curr = 0;
		for(j=0;j<len;j++)
		{
			if(suc[j])
			{
				res = res + (j - curr + 1) * (len - (j + n) +1);
				curr = j + 1;
				
			}	
		}

		printf("Case #%d: %lld\n",i,res);
		
	}
	return 0;
}
