#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int kolor;
int byl[1011];

int t,n;
vector<int> sas[1011];

int dfs(int k) {
	if(byl[k] == kolor) return true;
	byl[k] = kolor;
	for(int i=0;i<sas[k].size();i++) {int v = sas[k][i];
		if(dfs(v)) return true;
	}
	return false;
}

int main() {
	scanf("%d",&t);
	kolor = 1;
	for(int ind = 1;ind<=t;ind++) {
		scanf("%d",&n);
		int ile;
		for(int i=0;i<n;i++) {
			sas[i].clear();
			scanf("%d",&ile);
			for(int i2=0;i2<ile;i2++) {
				int b;scanf("%d",&b);b--;
				sas[i].push_back(b);
			}
		}
		printf("Case #%d: ", ind);
		
		int ok = 0;
		for(int i=0;i<n;i++) {
			kolor ++;
			if(dfs(i)) {ok =1; break;}
		}
		printf("%s\n", ok ? "Yes" : "No");
	}
	return 0;
}
