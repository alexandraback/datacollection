// GCJ2014R2.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#pragma warning(disable:4996)

using namespace std;

int T,N;
int head[26],mid[26],tail[26],pure[26];
long long fact[120];
long long M = 1000000007;

void init()
{
	scanf("%d",&T);
	fact[0] = 1;
	for (int i=1; i<=100; i++) {
		fact[i] = fact[i-1] * i % M;
	}
}

long long solve()
{
	memset(head,0,sizeof(head));
	memset(mid,0,sizeof(mid));
	memset(tail,0,sizeof(tail));
	memset(pure,0,sizeof(pure));

	char train[128];
	int flag[128];	
	for (int i=0;i<N;i++) {
		scanf("%s", train);
		memset(flag,0,sizeof(flag));
		
		int len = strlen(train);


		for (int j=0; j<len; j++) {
			if (train[j] == train[0]) {
				flag[j] = 1;
			} else {
				break;
			}
		}
		if (flag[len-1] != 1) {
			for (int j=len-1; j>0; j--) {
				if (train[j] == train[len-1] && flag[j] == 0) {
					flag[j] = 2;
				} else {
					break;
				}
			}
			head[train[0]-'a']++;
			tail[train[len-1] - 'a']++;
		}
		else 
		{
			pure[train[0]-'a']++;
		}
		
		char tmp = '?';
		for (int j=0; j<len; j++) {
			if (flag[j] == 0) {
				if (tmp == '?') {
					tmp = train[j];
				}
				else
				{
					if (tmp != train[j]) {
						mid[tmp-'a']++;
						tmp = train[j];		
					}
				}
			}
		}
		if (tmp != '?') {
			mid[tmp-'a']++;	
		}
	}

	long long freehead = 0;
	for (int i=0;i<26;i++) {
		if (mid[i]>1) {
			return 0;
		}
		if (mid[i]>0 && (head[i]>0 || tail[i]>0 || pure[i]>0)) {
			return 0;
		}
		if (head[i]>1 || tail[i]>1) {
			return 0;
		}
		if ((head[i]>0 || pure[i]>0) && tail[i]==0) {
			freehead++;
		}
	}
	if (freehead == 0) {
		return 0;
	}

	long long ret = 1;
	for (int i=0;i<26;i++) {
		if (head[i] == 1 || tail[i] == 1 || pure[i] > 0) {
			ret = ret * fact[pure[i]] % M;
		}
	}
	ret = ret * fact[freehead] % M;

	return ret;
}

void work()
{
	for (int ca=1; ca<=T; ca++)
	{
		scanf("%d", &N);
				
		cout << "Case #" << ca << ": ";		
		long long ret = solve();
		cout << ret << endl;		
	}
}


int main()
{
	freopen("C:\\Users\\yuazh\\Downloads\\B--small-attempt2.in", "r", stdin);
	freopen("C:\\Users\\yuazh\\Downloads\\B--small-attempt2.out", "w", stdout);
	init();
	work();

	return 0;
}

