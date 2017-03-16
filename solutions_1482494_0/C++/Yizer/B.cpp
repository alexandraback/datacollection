#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct node
{
	int a , b;
}all[1000];

bool visit[1000];

bool cmp(const node & a ,const node & b)
{
	if (a.b == b.b)
		return	a.a > b.a;
	else
		return	a.b < b.b;
}

int main()
{
	int nCase;
	scanf("%d",&nCase);
	for (int nc = 0; nc < nCase ; nc ++) {
		cerr << nc << endl;
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++)
			scanf("%d%d",&all[i].a,&all[i].b);

		memset(visit,0,sizeof(visit));
		
		sort(all,all+n,cmp);
		
		int ans = 0;
		int cnt = 0;
		bool noans = false;
		for (int i=0;!noans && (i<n);i++) {
			while (all[i].b > cnt) {
				bool found = false;
				for (int j=n-1;!found && (j>=i);j--) 
					if (all[j].a <= cnt && !visit[j] ) {
						cnt ++;
						ans++;
						visit[j] = true;
						found = true;
					}
				if (!found) {
					noans = true;
					break;
					}
			}
			
			if (all[i].b <= cnt) {
				ans++;
				if (visit[i])
					cnt++;
				else {
					cnt+=2;
					visit[i] = true;
				}
			}
		}
		printf("Case #%d: ",nc+1);
		if (noans)
			printf("Too Bad\n");
		else
			printf("%d\n",ans);
		
	}
//	while (1);
	return	0;
}
