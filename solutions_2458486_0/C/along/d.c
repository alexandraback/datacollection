#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <string.h>
#include <algorithm>
using namespace std;

int K,N;
int keys[300];
set<int> keyset;

int box_open[300];
set<int> box_index[300];
vector<int> box_has[300];
int opened[300];

vector<int> r1;
int target;
int r[300];
int found;
int result[300];

inline void subkey(int key)
{
	keys[key]--;
	if (keys[key] == 0)
		keyset.erase(key);
}

inline void addkey(int key)
{
	keys[key]++;
	if (keys[key] == 1)
		keyset.insert(key);
}

void search(int depth)
{
	int i,j,k;
/*	if (depth == target-1)
	{
		for(i=0; i<depth; i++) printf("%d ", r[i]);
		printf("\n");
	} */
	if (depth == target)
	{
		found = 1;
		memcpy(result, r, sizeof(r));
		return;
	}
//	printf("%d %d\n", depth, keyset.size());
	vector<int> cv;
	vector<int> kv;
	for(set<int>::iterator p = keyset.begin(); p != keyset.end(); p++)
		kv.push_back(*p);
	for(vector<int>::iterator p = kv.begin(); p != kv.end(); p++)
	{
		if (box_index[*p].size() == 0) continue;
		for(set<int>::iterator pp = box_index[*p].begin(); pp != box_index[*p].end(); pp++)
			cv.push_back(*pp);
	}
	sort(cv.begin(), cv.end());
	for(i=0; i<cv.size(); i++)
	{
		int boxid = cv[i];
		int need_key = box_open[boxid];
		r[depth] = boxid;
		subkey(need_key);
		for(j=0; j<box_has[boxid].size(); j++)
			addkey(box_has[boxid][j]);
		box_index[need_key].erase(boxid);
		search(depth+1);
		if (found) return;
		box_index[need_key].insert(boxid);
		for(j=0; j<box_has[boxid].size(); j++)
			subkey(box_has[boxid][j]);
		addkey(need_key);
	}
}

int greedy()
{
	int i,j,k;
	for(i=0; i<N; i++)
	{
		if (opened[i]) continue;
		k = box_open[i];
		if (keys[k] == 0) continue;
		for(j=0; j<box_has[i].size(); j++)
			if (box_has[i][j] == k)
				break;
		if (j < box_has[i].size())
		{
			opened[i] = 1;
			for(j=0; j<box_has[i].size(); j++)
				keys[box_has[i][j]]++;
			keys[k]--;
	//		printf("remove box %d\n", i);
			r1.push_back(i);
			return 1;
		}
	}
	return 0;
}

int quicktest1()
{
	int i,j,k;
	int total_need[300];
	memset(total_need, 0, sizeof(total_need));
	for(i=0; i<N; i++)
	{
		if (opened[i]) continue;
		total_need[box_open[i]]++;
	}
	int total_has[300];
	memset(total_has, 0, sizeof(total_has));
	for(i=0; i<300; i++) total_has[i] += keys[i];
	for(i=0; i<N; i++)
	{
		if (opened[i]) continue;
		for(j=0; j<box_has[i].size(); j++)
			total_has[box_has[i][j]]++;
	}
	for(i=0; i<300; i++)
		if (total_need[i] > total_has[i])
			return 0;
	return 1;
}

int main()
{
	int i,j,k;
	int cc,ca;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		memset(keys, 0, sizeof(keys));
		memset(opened, 0, sizeof(opened));
		r1.clear();
		keyset.clear();

		cin >> K >> N;
	//	cout << K << ' ' << N << endl;
		for(i=0; i<K; i++)
		{
			cin >> j;
			keys[j]++;
		}
		for(i=0; i<N; i++) box_has[i].clear();
		for(i=0; i<N; i++)
		{
			cin >> box_open[i];
			cin >> k;
			for(j=0; j<k; j++)
			{
				int t;
				cin >> t;
				box_has[i].push_back(t);
			}
//				printf("%d\n", box_open[i]);
//				for(j=0; j<box_has[i].size(); j++)
//					printf("%d ", box_has[i][j]);
//				printf("\n");

		}

		while(1)
		{
			if (!greedy()) break;
		}

		if (!quicktest1())
		{
			printf("Case #%d: IMPOSSIBLE\n", cc);
			continue;
		}

		for(i=1; i<=200; i++)
			if (keys[i] > 0)
				keyset.insert(i);

		for(i=1; i<300; i++) box_index[i].clear();
		target = 0;
		for(i=0; i<N; i++)
		{
			if (opened[i]) continue;
			box_index[box_open[i]].insert(i);
			target++;
		//	printf("target %d\n", i);
		}

		found = 0;
		search(0);
		if (found)
		{
			printf("Case #%d:", cc);
			for(i=0; i<r1.size(); i++) printf(" %d", r1[i]+1);
			for(i=0; i<target; i++) printf(" %d", result[i]+1);
			printf("\n");
		}
		else
			printf("Case #%d: IMPOSSIBLE\n", cc);
	}
}
