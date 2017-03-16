#include <bits/stdc++.h>
using namespace std;

int k,l,s;
string sa, sb;
char sc[10000];
double maxn;
double sum;

void dfs(int n){
	if( n == s ){
		double num=0;
		int i,j;
		for( i = 0; i + l <= s;i++){
			int flag = 1;
			for( j = 0; j < l && i + j < s; j++){
				if( sc[ i + j ] != sb[ j ]){
					flag = 0;
					break;
				}
			}
			if(flag==1)
				num++;
		}
		sum += num;
		maxn = max(num, maxn);
	}
	else{
		for(int i = 0; i < k; i++){
			sc[n] = sa[i];
			dfs(n+1);
		}
	}
}
int main(){
	int t;
	cin >> t;
	for( int ii = 1; ii <= t; ii++ ){
		cin >> k >> l >> s;

		cin >> sa >> sb;

		maxn = sum = 0;
		dfs(0);
		while(s--) {
			sum /= k;
		}

		printf("Case #%d: %.7lf\n",ii,maxn-sum);
	}
}