#include <bits/stdc++.h>
using namespace std;

int arr[1000];
int memo[1000];
int len[1000];
int p[1000];
int in[1000];
int cycle[1000];
int instack[1000];

int rec(int pos, int curr)
{
	if(memo[pos]!=-1)
	{
		if(instack[pos])
		{
			int cpos = pos;
			while(1)
			{
				cycle[cpos] = 1;
				cpos = arr[cpos];
				if(cpos==pos)
					break;
			}

			return curr-memo[pos];
		}
		return 0;
	}
	memo[pos] = curr;
	instack[pos] = 1;
	int ret = rec(arr[pos],curr+1);
	instack[pos] = 0;
	return ret;
}

int main()
{
	int t;
	scanf("%d",&t);

	for(int cn=1; cn<=t; cn++)
	{
		int n;
		scanf("%d",&n);

		for(int i=0; i<n; i++)
			in[i] = 0;

		for(int i=0; i<n; i++)
		{
			scanf("%d",arr+i);
			arr[i]--;
			in[arr[i]] = 1;
			instack[i] = 0;
			cycle[i] = 0;
		}

		for(int i=0; i<n; i++)
			memo[i] = -1;

		int ans = 2;
		for(int i=0; i<n; i++)
			ans = max(ans,rec(i,0));
		/*
		for(int i=0; i<n; i++)
			cout << memo[i] << endl;
		/*
		for(int i=0; i<n; i++)
			cout << memo[i] << endl;
		*/

		for(int i=0; i<n; i++)
		{
			if(arr[arr[i]]==i)
				p[i] = 1;
			else
				p[i] = 0;
		}

		for(int i=0; i<n; i++)
			len[i] = 0;


		for(int i=0; i<n; i++)
			if(in[i]==0)
			{
				//cout << i << endl;
				int cnt = 0;
				int pos = i;
				while(!cycle[pos])
				{
					cnt++;
					pos = arr[pos];
				}
				if(p[pos])
					len[pos] = max(len[pos],cnt);
			}
		//puts("HURRAH");
		set<int> pool;
		int curr = 0;
		for(int i=0; i<n; i++)
			if(p[i] && pool.find(i)==pool.end())
			{
				curr += 2+len[i]+len[arr[i]];
				pool.insert(i);
				pool.insert(arr[i]);
			}

		printf("Case #%d: %d\n",cn,max(ans,curr));
	}
}