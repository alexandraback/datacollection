#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <assert.h>

#define file_name ""

typedef long long ll;

const int N = 1e5+5;

using namespace std;

string s[15];
int a[15];
int b[30];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int countTests;
	scanf("%d",&countTests);
	for(int numTest=1;numTest<=countTests;++numTest)
	{
		int n;
		cin>>n;

		for(int i=0;i<n;++i)
		{
			cin>>s[i];
			a[i] = i;
		}
		int ans = 0;
		int f;
		int k;
		do
		{
			/*for(int i=0;i<n;++i)
				printf("%d ", a[i]);
				puts("");*/
			f=1;
			k=-1;
			memset(b, -1, sizeof(b));
			for(int i=0;i<n && f;++i)
				for(int j=0;j<s[a[i]].size();++j)
				{
					int &t = b[s[a[i]][j]-'a'];
					if (t != -1 && t != k)
					{
						f=0;
						break;
					}
					t = ++k;
				}
			ans+=f;
		}
		while (next_permutation(a,a+n));
		printf("Case #%d: ", numTest);
		printf("%d\n",ans);
	}
	return 0;
}
