#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
#include <string>
#include <map>
#include <list>
#include <climits>

using namespace std;

string word;

set<string> dic;
int dic_maxLen;

int result;

int dp[5000][5000];

void pre()
{
	FILE* fp = fopen("dictionary.txt", "r");
	char word[1000];
	dic_maxLen = 0;

	while(fscanf(fp, "%s", word) == 1)
	{
		int len = strlen(word);
		dic.insert(string(word));
		dic_maxLen = max(dic_maxLen, len);
		for(int i = 0; i < len; i++){
			char temp = word[i];
			word[i] = '?';
			dic.insert(string(word));
			for(int j = i+5; j < len; j++){
				char temp2 = word[j];
				word[j] = '?';
				dic.insert(string(word));
				word[j] = temp2;
			}
			word[i] = temp;
		}
		static int counter = 0;
		counter++;
		if(counter % 1000 == 0)
		{
			fprintf(stderr, "complete %d\n", counter);
		}
	}

	fprintf(stderr, "complete all maximum len is %d\n", dic_maxLen);
}

int solve(int idx, int prevPix)
{
	if(word.length() <= idx){
		return 0;
	}

	int& ret = dp[idx][prevPix+1];
	if(ret != -1) return ret;
	
	ret = 10000;

	for(int i = 1; i <= dic_maxLen; i++)
	{
		if(word.length() < idx+i) break;
		string subWord = word.substr(idx, i);

		if(dic.find(subWord) != dic.end()){
			ret = min(ret, solve(idx+subWord.length(), prevPix));
		}
		else{
			for(int i = 0; i < subWord.length(); i++)
			{
				if(prevPix == -1 || prevPix+5 <= idx+i)
				{
					char temp = subWord[i];
					subWord[i] = '?';
					if(dic.find(subWord) != dic.end()){
						ret = min(ret, 1 + solve(idx+subWord.length(), idx+i));
					}else{
						for(int j = i+5; j < subWord.length(); j++)
						{
							char temp2 = subWord[j];
							subWord[j] = '?';
							if(dic.find(subWord) != dic.end()){
								ret = min(ret, 2 + solve(idx+subWord.length(), idx+j));
							}
							subWord[j] = temp2;
						}
					}
					subWord[i] = temp;
				}
			}
		}
	}
	return ret;
}

int main()
{	
	int C;
	scanf("%d", &C);

	pre();

	while(C --> 0)
	{
		//input
		char foo_word_input[5000];
		scanf("%s", foo_word_input);
		word = foo_word_input;
		result = 10000;
		memset(dp, -1, sizeof(dp));

		static int Case = 1;
		printf("Case #%d: %d\n", Case++, solve(0, -1));
		fprintf(stderr, "solve %d\n", Case-1);
	}

	return 0;
}
