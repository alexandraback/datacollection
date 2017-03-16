#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);
	int t, K, C, S, cases, i, j, cnt;
	long long tmp, cur;
	vector<long long> ans;
	scanf("%d", &t);
	for(cases=1;cases<=t;cases++){
		scanf("%d %d %d", &K, &C, &S);
		if(C*S<K) printf("Case #%d: IMPOSSIBLE\n", cases);
		else{
			ans.clear();
			cnt=0;
			cur=1;
			tmp=1;
			for(i=0;i<K;i++){
				tmp+=cur*i;
				cur*=K;
				cnt++;
				if(cnt==C&&i<K-1){
					ans.push_back(tmp);
					cur=1;
					cnt=0;
					tmp=1;
				}
			}
			if(cnt!=0) ans.push_back(tmp);
			printf("Case #%d: ", cases);
			for(i=0;i<ans.size()-1;i++) printf("%lld ",ans[i]);
			printf("%lld\n", ans[i]);
		}
	}
	return 0;
}
