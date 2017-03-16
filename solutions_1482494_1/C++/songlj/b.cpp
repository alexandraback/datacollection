#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
//#include <time.h>
//#include <stdlib.h>
//#include <math.h>
//#include <queue>
#include <vector>
//#include <stack>
//#include <set>
#include <map>
#include <algorithm>
//#include <sstream>
using namespace std;

const int maxn=1005;

struct Data {
	int a,b;
} data[maxn];

int n;
int ans;
int flag[maxn];

bool cmp(const Data &d1,const Data &d2) {
	return d1.b>d2.b;
}

void solve() {
	sort(data,data+n,cmp);
	ans=0;
	memset(flag,0,sizeof(flag));
	int now=0;
	bool changed;
	do {
		changed=false;
		for (int i=0;i<n;i++)
			if (now>=data[i].b&&flag[i]==0) {
				now+=2;
				flag[i]=2;
				changed=true;
				ans++;
				break;
			}
		if (!changed) {
			for (int i=0;i<n;i++)
				if (now>=data[i].b&&flag[i]==1) {
					now+=1;
					flag[i]=2;
					changed=true;
					ans++;
					break;
				}
		}
		if (!changed) {
			for (int i=0;i<n;i++)
				if (now>=data[i].a&&flag[i]==0) {
					now+=1;
					flag[i]=1;
					changed=true;
					ans++;
					break;
				}
		}
	} while (changed);

	for (int i=0;i<n;i++)
		if (flag[i]!=2) {
			printf("Too Bad\n");
			return;
		}
	printf("%d\n",ans);
}

int main() {
	int T,kase=0;
	cin>>T;
	while (T--) {
		cin>>n;
		for (int i=0;i<n;i++)
			scanf("%d%d",&data[i].a,&data[i].b);
		printf("Case #%d: ",++kase);
		solve();
	}
	return 0;
}

