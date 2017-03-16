#include <bits/stdc++.h>

using namespace std;

int t,tes,n,ans,ans2,x,y,i,j,len;
int a[10007];
bool flag[10007];
vector<int> back[10007];

int DFS(int pos, int bef) {
	int i;
	int tmp = 0;
	for (i=0 ; i<back[pos].size() ; i++) if (back[pos][i] != bef) {
		tmp = max(tmp,1+DFS(back[pos][i],pos));
	}
	
	return tmp;
}

int main() {
	scanf("%d",&t);
	for (tes=1 ; tes<=t ; tes++) {
		scanf("%d",&n);
		for (i=1 ; i<=n ; i++) {
			back[i].clear();
		}
		for (i=1 ; i<=n ; i++) {
			scanf("%d",&a[i]);
			back[a[i]].push_back(i);
		}
		printf("Case #%d: ",tes);
		
		ans = 0;
		for (i=1 ; i<=n ; i++) {
			for (j=1 ; j<=n ; j++) flag[j] = false;
			x = i;
			len = 0;
			while (!flag[x]) {
				flag[x] = true;
				len++;
				x = a[x];
			}
			if (x == i) ans = max(ans,len);
		}
		
		ans2 = 0;
		for (i=1 ; i<=n ; i++) flag[i] = false;
		for (i=1 ; i<=n ; i++) if (!flag[i]) {
			if (a[a[i]] == i) {
				x = i;
				y = a[i];
				flag[x] = true;
				flag[y] = true;
				ans2 += 2;
				ans2 += DFS(x,y);
				ans2 += DFS(y,x);
			}
		}
		
		printf("%d\n",max(ans,ans2));
	}
}