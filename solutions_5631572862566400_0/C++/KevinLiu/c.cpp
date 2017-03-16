#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef vector<int> Vint;
typedef vector<LL> VLL;

void printV(Vint v)
{
	for (int i=0;i<v.size();i++) {
		printf("%d\n", v[i]);
	}
}

int bff[1000];
int find_circle1(int st, int N)
{
	int cnt=0;
	int entered[1000];
	for (int i=0;i<1000;i++) {
		entered[i]=0;
	}

	int p=st;
	while (true) {
		entered[p]=1;
		cnt++;
		int q=bff[p];
		if (bff[q]==p || q==st) {
			if (q!=st) {
				cnt++;
			}
			p=q;
			break;
		}
		if (entered[q]) {
			cnt=0;
			break;
		}
		p=q;
	}
	
	
	if (p!=st) {
		for (int i=0;i<N;i++) {
			if (bff[i]==p && !entered[i]) {
				cnt++;
				break;
			}
		}
	}
	return cnt;
}

int find_circle(int st, int N)
{
	int cnt=0;
	int exited[1000];
	int entered[1000];
	for (int i=0;i<1000;i++) {
	   	exited[i]=0;
	   	entered[i]=0;
	}

	int p=st;
	
	while (true) {
		// enter p
		entered[p]=1;
		cnt++;

		int q=bff[p];
		// exit p
		if (entered[q]) {
			break;
		} else {
			exited[p]=1;
			p=q;
		}
	}

	if (!exited[p]) {
		// add one more if possible

		for (int i=0;i<N;i++) {
			if (bff[i]==p && !entered[i]) {
				cnt++;
				break;
			}
		}

	}


	
	return cnt;
}

void solve()
{
	int N;
	scanf("%d", &N);
	for (int i=0;i<N;i++) {
		int x;
		scanf("%d", &x);
		bff[i]=x-1;
	}

	int cmax=0;

	for (int i=0;i<N;i++) {
		//int c=find_circle(i, N);
		int c=find_circle1(i, N);
		if (c>cmax) {
			cmax=c;
		}
	}

	printf("%d\n", cmax);
}

int main() 
{
	int T=0;
	scanf("%d", &T);
	for (int i=1;i<=T;i++) {
		printf("Case #%d: ", i);
		solve();
	}
	
	return 0;
}
