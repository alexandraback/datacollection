#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

long long pow(int n, int p){

	if(p == 0) return 1;
	else if(p == 1) return n;

	long long temp = pow(n,p/2);
	if(p%2 == 0){
		return temp*temp;
	}
	else{
		return temp*temp*n;
	}
}

int main(){
	int T;
	scanf("%d",&T);

	for(int test_case = 1; test_case <= T; test_case++){
		int K,C,S;
		scanf("%d %d %d",&K,&C,&S);

		bool success = true;
		vector<long long> ans;

		if(K > C*S) success = false;
		else{
			//possible
			queue<int> q;
			for(int i = 0 ; i < K ; i++) q.push(i);
			if(K%C != 0) for(int i = 0 ; i < C-K%C ; i++) q.push(0);

			while(!q.empty()){
				long long elem = 1;
				for(int i = C-1 ; i >= 0 ; i--){
					int x = q.front();q.pop();
					elem = elem + pow(K,i)*x;
				}
				ans.push_back(elem);
			}
		}

		if(success){
			printf("Case #%d:",test_case);
			int size = ans.size();
			for(int i = 0 ; i < size ; i++){
				printf(" %lld",ans[i]);
			}
			printf("\n");
		}
		else{
			printf("Case #%d: IMPOSSIBLE\n",test_case);
		}

	}

	return 0;
}
