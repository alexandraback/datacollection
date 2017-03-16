#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <memory.h>
#include <math.h>


using namespace std;
#define MAX 5000
#define MAX_INT 1000000000
int mas[MAX];

int main()
{
	//garbled_email_dictionary.txt
	FILE * dicf = fopen("garbled_email_dictionary.txt", "r");
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);

	vector<string> dic;
	char s[10000];
	while (fscanf(dicf, "%s", s) > 0)
	{
		string str = s;
		dic.push_back(str);
	}
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		scanf("%s", s);
		int len = strlen(s);
		for (int i = 0; i < MAX; i++)
			mas[i] = MAX_INT;
		mas[0] = 0;
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < dic.size(); j++)
				if (dic[j].size() + i <= len)
				{
					int q = 0;
					for (int k = 0; k < dic[j].size(); k++)
						if (s[i+k] != dic[j][k])
							q++;
					mas[i + dic[j].size()] = min(mas[i + dic[j].size()], mas[i] + q);
				}
		}
		printf("Case #%d: %d\n", t+1, mas[len]);
	}

	fclose(dicf);
	fclose(stdin);
	fclose(stdout);

	return 0;
}