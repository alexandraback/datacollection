#include <cstdio>
#include <cassert>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
int N,A[MAXN];

int f(int val){
	int special = 0,maxval = 0;
	for(int i=1;i<=N;i++){
		if(A[i] > val){
			int times = (A[i]+val-1)/val;
			int at_this = (A[i]+times-1)/times;
			assert(at_this <= val);

			special += times-1;
			maxval = max(maxval,at_this);
		}else{
			maxval = max(maxval,A[i]);
		}
	}
	return maxval + special;
}

void run(int test){
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&A[i]);

	int ans = 1e9;
	for(int i=1;i<=1000;i++) ans = min(ans,f(i));
	printf("Case #%d: %d\n",test,ans);
}

int main(){
	freopen("B-small-attempt2.in","r",stdin);
	freopen("B-small-attempt2.out","w",stdout);

	int T; scanf("%d",&T);
	for(int i=1;i<=T;i++) run(i);
	return 0;
}