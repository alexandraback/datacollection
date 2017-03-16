/*************************************************************************
    > File Name: A.cpp
    > Author: hnu0314
    > Mail: hnu0314@126.com 
    > Created Time: 2013/4/27 9:16:08
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;
typedef long long LL;

const int MAXN = 0; 
const int INF = 0;

int main(){
	
	int test, cas(1);
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("a-small.out", "w", stdout);
	scanf("%d", &test);
	while(test--){
		LL use(0.0), have, r; 
		cin>>r>>have;
		LL res(0);
		while(1){
			use +=  ( 2 * r + 1);
			if(use > have)  break;
			r += 2;	
			++res;
		}
		printf("Case #%d: %d\n", cas++, res);
	}

		return 0;
}
