//Author: net12k44
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

int d[5][5] = { 
		{0,0,0,0,0},
		{0,1,2,3,4}, 
		{0,2,-1,4,-3},
		{0,3,-4,-1,2},
		{0,4,3,-2,-1}
	};
	
const char* YES = "YES";
const char* NO = "NO";
char a[10000 + 5];
	
int sign(int x){
	if (x > 0) return 1;
	return -1;
}	

int mul(int x, int y){
	return d[abs(x)][abs(y)] * sign(x) * sign(y);
}

int power(int x, long long y){
	if (y == 0) return 1;
	int res = power(x, y/2);
	res = mul(res, res);
	if (y&1) res = mul(res, x);
	return res;
}

const char* solve(){
	int n; long long x;
	cin >> n >> x >> a;
	map<char, int> value;
	value['i'] = 2;
	value['j'] = 3;
	value['k'] = 4;
	
	int cur = 1;
	for(int i = 0; i < n; ++i)
		cur = mul(cur, value[ a[i] ]);
	cur = power(cur, x);	
	if (cur != -1) return NO;
	
	int i_length = 0;
	int nn=4;
	for(int k=0, cur=1; k<nn; ++k){
		for(int i = 0; i < n; ++i){
			cur = mul(cur, value[ a[i] ]);
			if (cur == value['i']) {
				i_length = k*n + i + 1;
				k = nn;
				i = n;
			}
		}			
	}
	if (!i_length) return NO;
	
	int k_length = 0;
	for(int k=0, cur=1; k<nn; ++k){
		for(int i = n-1; i>=0; --i){
			cur = mul(value[ a[i] ], cur);
			if (cur == value['k']){
				k_length = k*n + n - i;
				k = nn;
				i = -1;
			}
		}
	}
	if (!k_length) return NO;
	
	if (i_length + k_length >= x*n) return NO;
	return YES;
}


int main(){
	freopen("file.inp","r",stdin);
	int test; scanf("%d",&test);
	freopen("file.out","w",stdout);
	for(int i = 1; i<=test; ++i){
		printf("Case #%d: %s\n", i, solve());
	}
}
