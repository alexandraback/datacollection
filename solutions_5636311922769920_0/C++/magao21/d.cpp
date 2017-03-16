#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

int main(){
	int T,C,k,c,s;
	for (scanf("%d", &T), C = 1; C <= T; C++){
		printf("Case #%d:", C);
		scanf("%d%d%d", &k, &c, &s);
		int i,j;
		long long ans;
		for (i = 1; i <= s; i++){
			ans = i;
			for (j = 0; j < c - 1; j++)
				ans = (ans-1)*k+i;
			cout << ' ' << ans;
		}
		cout<<endl;
	}
	return 0;
}