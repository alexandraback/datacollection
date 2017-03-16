#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int N, M, a;
bool result;
bool path[1024][1024];
int set[1024];

void dfs(int child)
{
	for(int j = 1; j <= N; j++){
		if(path[child][j]){
			if(set[j] == 1){
				result = true;
				return;
			}
			set[j] = 1;
			dfs(j);
			if(result==true)
				return;
		}
	}
}

int main(int argc, const char *argv[])
{
	int cases, casen=0;

	cin >> cases;
	while(casen<cases){
		memset(path, 0, sizeof(path));
		cin >> N;
		for(int i = 1; i <= N; i++){
			cin >> M;
			while(M--){
				cin >> a;
				path[i][a] = true;
			}
		}
		result = false;
		
		for(int i = 1; result==false && i <= N; i++){
			memset(set, 0, sizeof(set));
			dfs(i);
		}

done:
		++casen;
		printf("Case #%d: %s\n", casen, result?"Yes":"No");
	}
	return 0;
}
