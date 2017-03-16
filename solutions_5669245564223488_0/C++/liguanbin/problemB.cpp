#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

string train[500];
int N;

bool isvalid(int *q)
{
	bool test[30]; 
	fill(test,test+30,false);
	char curr = train[q[0]][0]; 
	test[curr-'a'] = true;
	for (int i = 0; i < N; ++i)
	{
		string s = train[q[i]];
		for (int j = 0; j < s.size(); ++j)
		{
			if (s[j] != curr) {
				if (test[s[j]-'a']) return false;
				test[s[j]-'a'] = true;
				curr = s[j];
			}
		}
	}
	return true;
}



int main()
{
 	freopen("B-small-attempt1.in","r",stdin);
 	freopen("B-small-attempt1.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int i = 1; i <= T; ++i)
	{
		int q[100];

		cin >> N;
		for (int j = 0; j < N; ++j)
		{
			cin >> train[j];
		}
		for (int j = 0; j < N; ++j)
		{
			q[j] = j;
		}
		int sum = 0;
		while (true)
		{
			if (isvalid(q))
			{
				sum++;
			}
			if (!next_permutation(q,q+N))
			{
				break;
			}

		}
		printf("Case #%d: %d\n",i,sum);
	}
	
	return 0;
}
