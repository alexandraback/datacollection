#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

set<int> Val;
int C, D, V;
unordered_map<int, bool> exists;

void init()
{
	int temp;
	scanf("%d %d %d", &C, &D, &V);

	exists.clear();
	Val.clear();
	for(int i = 0; i<D; i++)
	{
		scanf("%d", &temp);
		Val.insert(temp);
	}
}

void calc(set<int> left, int pos)
{
	if(pos>V)
		return;
	exists[pos] = 1;
	if(left.empty())
		return;

	
	int temp;
	set<int> t;

	for(set<int>::iterator ii = left.begin(); ii!=left.end(); ii++)
	{
		t=left;
		temp = *ii;
		t.erase(temp);
		calc(t, pos + temp);
	}
}

inline unordered_map<int, bool> d(unordered_map<int, bool> curr, int val)
{
	int i;

	for(i=0; i + val<=V; i++)
		if(curr.find(i)!=curr.end())
			curr[i+val]=1;
	return curr;

}

int solve()
{
	deque< pair<unordered_map<int, bool>, set<int> > > Q;
	pair<unordered_map<int, bool>, set<int> > curr, temp;
	int i;

	Q.push_back(make_pair(exists, Val));

	while(1)
	{
		curr = Q.front();
		Q.pop_front();

		for(i=1; i<=V; i++)
		{
			temp = curr;
			if(curr.second.find(i) == curr.second.end())
			{
				temp.first = d(temp.first, i);
				temp.second.insert(i);

				if(temp.first.size() == V + 1)
					return temp.second.size() - D;
				Q.push_back(temp);
			}
		}
	}
}



int main()
{
	int T, i;

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d", &T);

	for(i=1; i<=T; i++)
	{
		init();
		calc(Val, 0);
		if(exists.size() == V + 1)
		{
			printf("Case #%d: 0\n", i);
			continue;
		}
		printf("Case #%d: %d\n", i, solve());
	}

	return 0;
}