#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
using namespace std;
#define N 1001
vector<int> map[N];
int degree[N];
void init( int n ){
	memset(degree,0,sizeof(degree));
	for(int i=0;i<n;++i) map[i].clear();
	for( int i=0;i<n;++i ){
		int m; scanf("%d",&m);
		for( int j=0;j<m;++j ){
			int cnt; scanf("%d",&cnt);
			--cnt;
			map[i].push_back(cnt);
			++degree[cnt];
		}
	}
}

int st[N],et[N];
bool flag;
int _time;

void dfs( int s ){
	if( flag ) return ;

	st[s] = ++_time;
	for( int i=0;i<(int)map[s].size();++i ){
		if( -1 == st[ map[s][i] ] ){
			dfs(map[s][i]);
		}else{
			if( st[map[s][i]] != st[s]+1 ){
				flag = 1;
				return ;
			}
		}
	}
	//et[s] = ++_time; 
}

void solve( int n ){
	
	for(int i=0;i<n;++i) if( !degree[i] ){
		memset(st,-1,sizeof(st));
		//memset(et,0,sizeof(et));
		_time = 0;
		flag = 0;
		dfs(i);
		if(flag){
			puts("Yes");
			return ;
		}
	}	
	puts("No");
	return ;
}

int main(){
	int t,n;
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	scanf("%d",&t);
	for( int _case = 0; _case < t; ++_case ){
		scanf("%d",&n);
		init(n);
		printf("Case #%d: ",_case+1);
		solve(n);
	}	
	return 0;
}

/*
3
3
1 2
1 3
0
5
2 2 3
1 4
1 5
1 5
0
3
2 2 3
1 3
0

Case #1: No
Case #2: Yes
Case #3: Yes

*/