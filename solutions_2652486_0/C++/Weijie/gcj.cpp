#include<stdio.h>
#include<string.h>
#include<vector>
#include<set>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>

using namespace std;

FILE *fin;
FILE *fout;

int n,m,k;
int a[20];
int num[20];
map<int,int> mymap;

int isPossible(int x,int product){

	int p = 1;
	for(int i = 0;i < n;++i){
		if(x & (1 << i))
			p *= num[i + 1];
	}	
/*	if(num[1] == 3 && num[2] == 4 && num[3] == 3){
		printf("find! %d %d %d\n",x,p,product);	
	}*/
	if(p != product)
		return 0;
	return 1;
}

int tmpa[10];
int maxcnt, ans;

void calc(){
	/*for(int i = 1;i <= n;++i)
		printf("%d ",num[i]);
	printf("\n");*/
	int cnt = 0;
	for(int i = 1;i <= k;++i){
		int sum = 0;
		bool ok = false;
		for(int x = 0;x < (1 << n);++x)
			if(isPossible(x,a[i])){
				ok = true;
				break;
			}
		if(!ok)
			break;
		cnt += 1;
	}
	if(cnt != k)
		return;
	/*printf("%d\n",cnt);
	system("pause");*/
	for(int i = 1;i <= n;++i)
		tmpa[i] = num[i];
	sort(tmpa + 1,tmpa + 1 + n);
	int key = 0;
	for(int i = 1;i <= n;++i)
		key = key * 10 + tmpa[i];
	if(mymap.find(key) == mymap.end())
		mymap[key] = 0;
	mymap[key] += cnt;
	if(mymap[key] > maxcnt){
		maxcnt = mymap[key];
		ans = key;
	}
}

void dfs(int pos){
	if(pos == n + 1){
		calc();
		return;
	}
	for(int i = 2;i <= m;++i){
		num[pos] = i;
		dfs(pos + 1);
	}
}

int solve(){
	dfs(1);
	return ans;
}

int main() {
	fin = fopen("C-small-1-attempt0.in","r");
	fout = fopen("gcjout.txt","w");
	int T;
	fscanf(fin,"%d",&T);
	fscanf(fin,"%d%d%d%d",&T,&n,&m,&k);
	fprintf(fout, "Case #1:\n");
	for(int caseT = 1;caseT <= T;++caseT){
		mymap.clear();
		maxcnt = 0;
		ans = 0;
		for(int i = 1;i <= k;++i)
			fscanf(fin,"%d",&a[i]);
		fprintf(fout,"%d\n",solve());
	/*	system("pause");
		break;*/
	}
	fclose(fin);
	fclose(fout);
	return 0;
}

