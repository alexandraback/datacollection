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
	freopen("A-large.in", "r", stdin);
	freopen("a-large.out", "w", stdout);
	scanf("%d", &test);
	while(test--){
		LL have, rd; 
		cin>>rd>>have;
		/*
		LL use(0);
	    LL tesd = 10000;	
		LL tmp(rd);
		
		while(1){
			use +=  ( 2 * rd + 1);
			if(use > have)  break;
			rd += 2;
			++res;
			if(res >= tesd)   break;
		}
		rd = tmp;
		cout<<use<<endl;
		*/
		LL l(0),  r(have);
		//res = 0;
		LL res(0);
		//printf("%I64d  %I64d\n", have, rd);
		while(l <= r){
			LL mid = (l + r) >> 1;
			LL sum1 = mid;
			LL sum2 = (rd + (mid - 1) * 2 + rd) * mid / 2;
			//cout<<sum1<<"  "<<sum2<<"  "<<mid<<endl;
			if(mid != 0 && ( sum2 * 2 / mid != (rd + (mid - 1) * 2 + rd) ) ) {
				r = mid - 1;
			}
			else if(sum1 + 2 * sum2 - sum1 != 2 * sum2) {
				r = mid - 1;
			}else if(sum1 + 2 * sum2 > have){
				r = mid - 1;
			}else {
				l = mid + 1;
				res = max(res, mid);
			}
			//cout<<sum1 + 2 * sum2<<"   "<<sum1<<"   "<<sum2<<endl;

		}


		printf("Case #%d: ", cas++);  cout<<res<<endl;
	}

		return 0;
}
