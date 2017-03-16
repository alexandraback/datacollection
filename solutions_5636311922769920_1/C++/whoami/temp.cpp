#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
long long n, m;
long long gob[101] = { 1, };
int main(){
	int testt;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &testt);
	for (int test = 1; test <= testt; test++){
		printf("Case #%d: ", test);
		int s;
		scanf("%lld %lld %d", &n, &m, &s);
		if (m * s < n){
			printf("IMPOSSIBLE\n");
			continue;
		}
		for (int i = 1; i < m; i++)
			gob[i] = gob[i - 1] * n;

		long long factor = 1;

		vector<long long> temp;
		for (int i = 0; i < n; i++){
			if (temp.size() == m){
				long long ans = 1;
				for (int j = 0; j < m; j++){
					ans += gob[m - j - 1] * temp[j];
				}
				printf("%lld ", ans);
				temp.clear();
			}
			temp.push_back(i);
		}
		if (temp.size() != 0){
			long long ans = 1;
			for (int j = 0; j < temp.size(); j++){
				ans += gob[m - j - 1] * temp[j];
			}
			printf("%lld ", ans);
			temp.clear();
		}
		printf("\n");
	}
	return 0;
}
