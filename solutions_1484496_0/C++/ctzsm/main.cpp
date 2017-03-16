#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>

using namespace std;

int T;
int n;
long long a[505];
map<int,int> hash;
void output(int x,int y){
	for(int i = 0;i < 20; ++i) if(x & (1 << i)) printf("%d ",a[i]);
	printf("\n");
	for(int i = 0;i < 20; ++i) if(y & (1 << i)) printf("%d ",a[i]);
	printf("\n");
}
void solve(){
	hash.clear();
	scanf("%d",&n);
	int up = 1 << n;
	for(int i = 0;i < n; ++i) scanf("%d",&a[i]);
	for(int i = 1;i < up; ++i){
		int sum = 0;
		for(int j = 0;j < 20; ++j){
			if(i & (1 << j)) sum += a[j];
		}
		if(hash.find(sum) == hash.end()){
			hash[sum] = i;
		}else{
			output(hash[sum],i);
			break;
		}
	}
}
int main(int argc, char** argv) {
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	scanf("%d",&T);
	for(int v = 1;v <= T; ++v){
		printf("Case #%d:\n",v);
		solve();
	}
	return 0;
}

