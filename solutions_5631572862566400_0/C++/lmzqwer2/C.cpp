#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int nex[1010];
int hav[20];
int used[20];

int n, total;

void printhav(int len){
	for (int i=0; i<len; i++){
		printf(" %d", hav[i]);
	}
	putchar('\n');
}

int valid(int index, int len){
	int left = (index==0) ? (len - 1) : (index - 1);
	int right = (index==len-1) ? 0 : (index + 1);
	//printf("v: %d %d %d %d\n", left, index, right, len);
	int lv = hav[left];
	int rv = hav[right];
	int nv = hav[index];
	return (nex[nv] == lv || nex[nv] == rv);
}

void check(){
	//printhav(n);
	for (int i=2; i<=n; i++){
		int j;
		for (j=0; j<i; j++){
			if (!valid(j, i))
				break;
		}
		if (j == i){
			total = max(total, i);
			//printhav(i);
		}
	}
}

void dfs(int index){
	if ( index >= n){
		check();
		return;
	}else{
		for (int j=1; j<=n; j++){
			if (!used[j]){
				hav[index] = j;
				used[j] = 1;
				dfs(index+1);
				used[j] = 0;
				hav[index] = 0;
			}
		}
	}
}

int main(){
	int times;
	scanf("%d\n", &times);
	for (int t=1; t<=times; t++){
		total = 0;
		scanf("%d", &n);
		for (int i=1; i<=n; i++){
			scanf("%d", &nex[i]);
		}
		dfs(0);
		printf("Case #%d: %d\n", t, total);
		//if (t==1) while(1);
	}
	return 0;
}
