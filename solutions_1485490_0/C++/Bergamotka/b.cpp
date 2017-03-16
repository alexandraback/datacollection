#include<cstdio>
#include<algorithm>

using namespace std;

typedef unsigned long long llu;

llu testcase(){
	int n,m;
	scanf("%d %d", &n, &m);
	int ta[n];
	llu ca[n];
	int tb[m];
	llu cb[m];
	int i;
	for(i=0;i<n;++i){
		scanf("%llu %d", ca+i, ta+i);
		if(i>0 && ta[i] == ta[i-1]){
			ca[i-1] += ca[i];
			--n;
			--i;
		}
	}
	for(i=0;i<m;++i)
		scanf("%llu %d", cb+i, tb+i);
/*
	for(i=0;i<n;++i)
		printf("%d (%llu) ", ta[i], ca[i]);
	printf("\n");
	for(i=0;i<m;++i)
		printf("%d (%llu) ", tb[i], cb[i]);
	printf("\n\n");
	*/	

	llu pref[n][m+1];
	int j;
	for(i=0;i<n;++i){
		pref[i][0] = 0;
		for(j=1;j<=m;++j){
			pref[i][j] = pref[i][j-1];
			if(ta[i] == tb[j-1])
				pref[i][j] += cb[j-1];
		}
	}
/*
	for(i=0;i<n;++i){
		for(j=0; j<=m;++j)
			printf("%lld ", pref[i][j]);
		printf("\n");
	}
*/
	llu best = 0;

	for(i=0;i<=m;++i){
		for(j=i;j<=m;++j){
			llu res = min(ca[0], pref[0][i]);
			if(n>1)
				res += min(ca[1], pref[1][j]-pref[1][i]);
			if(n>2)
				res += min(ca[2], pref[2][m]-pref[2][j]);

			if(res > best)
				best = res;
		}
	}
	
	if(n>2 && ta[0] == ta[2]){
		llu res = min(ca[0]+ca[2], pref[0][m]);
		if(res>best)
			best = res;
	}


	return best;
}

int t, ti;

int main(){
	scanf("%d", &t);
	for(ti=1;ti<=t;++ti)
		printf("Case #%d: %llu\n", ti, testcase());
}
