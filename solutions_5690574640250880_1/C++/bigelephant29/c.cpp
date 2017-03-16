#include<cstdio>
#include<cstring>
#include<utility>
#include<queue>
using namespace std;
const int MAX = 50 + 10;
bool rec[MAX][MAX];
bool vis[MAX][MAX];
int sum[MAX][MAX];
int n, m, k;

queue< pair<int, int> > q;

void put(int x, int y){
	rec[x][y] = true;
	sum[x+1][y+1]++;
	sum[x-1][y+1]++;
	sum[x+1][y-1]++;
	sum[x-1][y-1]++;
	sum[x+1][y]++;
	sum[x-1][y]++;
	sum[x][y+1]++;
	sum[x][y-1]++;
}

void pull(int x, int y){
	rec[x][y] = false;
	sum[x+1][y+1]--;
	sum[x-1][y+1]--;
	sum[x+1][y-1]--;
	sum[x-1][y-1]--;
	sum[x+1][y]--;
	sum[x-1][y]--;
	sum[x][y+1]--;
	sum[x][y-1]--;
}
bool pp = false;
bool check(){
	bool flag = false;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			if(!rec[i][j] && sum[i][j]==0)
				flag = true;
		}
	}
	if(!flag) return false;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++) if(!rec[i][j] && sum[i][j]!=0){
			bool tmp = false;
			for(int p = max(1, i-1) ; p <= min(n, i+1) ; p++)
				for(int q = max(1, j-1) ; q <= min(m, j+1) ; q++) if(p!=i||q!=j)
					if(!rec[p][q] && sum[p][q] == 0) tmp = true;
			if(!tmp) return false;
		}
	}
	while(!q.empty()) q.pop();
	memset(vis, true, sizeof(vis));
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)
			vis[i][j] = false;
	flag = false;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			if(!rec[i][j] && sum[i][j] == 0){
				flag = true;
				q.push(make_pair(i, j));
				vis[i][j] = true;
				break;
			}
		}
		if(flag) break;
	}
	while(!q.empty()){
		int x = q.front().first, y = q.front().second;
		q.pop();
		if(!vis[x+1][y] && !rec[x+1][y] && sum[x+1][y]==0){
			q.push(make_pair(x+1, y));
			vis[x+1][y] = true;
		}
		if(!vis[x-1][y] && !rec[x-1][y] && sum[x-1][y]==0){
			q.push(make_pair(x-1, y));
			vis[x-1][y] = true;
		}
		if(!vis[x][y+1] && !rec[x][y+1] && sum[x][y+1]==0){
			q.push(make_pair(x, y+1));
			vis[x][y+1] = true;
		}
		if(!vis[x][y-1] && !rec[x][y-1] && sum[x][y-1]==0){
			q.push(make_pair(x, y-1));
			vis[x][y-1] = true;
		}
	}
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++){
			if(!rec[i][j] && !vis[i][j] && sum[i][j]==0){
				return false;
			}
		}
	return true;
}

bool canput(int x, int y){
	if(rec[x][y]) return false;
	put(x, y);
	if(x==2 && y==1) pp = true;
	if(check()){
			pp = false;
			return true;
	}
	pp = false;
	pull(x, y);
	return false;
}

void print(){
	bool c = false;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			if(!rec[i][j]&&sum[i][j]==0&&!c){
				putchar('c');
				c = true;
			}else{
				if(rec[i][j])
					putchar('*');
				else
					putchar('.');
			}
		}
		puts("");
	}
}

int main(){
	int TN;
	scanf("%d", &TN);
	for(int casen = 1 ; casen <= TN ; casen++){
		scanf("%d %d %d", &n, &m, &k);
		if(k==n*m-1){
			printf("Case #%d:\n", casen);
			for(int i = 1 ; i <= n ; i++){
				for(int j = 1 ; j <= m ; j++)
					if(i+j==2) putchar('c');
					else putchar('*');
				puts("");
			}
			continue;
		}
		int cnt = 0, h = 0, z = 0;
		memset(rec, 0, sizeof(rec));
		memset(sum, 0, sizeof(sum));
		int now = min(n-z, m-h);
		while(now > 0 && k - cnt >= now){
			if(n-z <= m-h){
				for(int i = 1 ; i <= n-z && cnt != k ; i++) if(!rec[i][m-h]){
					put(i, m-h);
					cnt++;
				}
				h++;
			}else{
				for(int i = 1 ; i <= m-h && cnt != k ; i++) if(!rec[n-z][i]){
					put(n-z, i);
					cnt++;
				}
				z++;
			}
			now = min(n-z, m-h);
		}
		for(int i = n-z ; i >= 1 && cnt != k ; i--){
			for(int j = m-h ; j >= 1 && cnt != k ; j--){
				if(canput(i, j)) cnt++;
			}
		}
		printf("Case #%d:\n", casen);
		if(cnt==k && check()){
			print();
		}else{
			puts("Impossible");
		}
	}
	return 0;
}
