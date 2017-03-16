#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(){
	FILE *fp = fopen("cbig", "r");
	long long a, b, l[1000], sz=0;
	while(fscanf(fp,"%lld%lld", &a, &b)!=EOF)
		l[sz++] = b;
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase){
		cin >> a >> b;
		printf("Case #%d: ", kase);
		int ans = 0;
		for(int i = 0; i < sz; ++i)
			if(l[i] >= a && l[i] <= b) ++ans;
		cout << ans << endl;
	}
}

