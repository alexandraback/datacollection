#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <string>

#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>

#include <sstream>
#include <iostream>
#include <fstream>

#include <cctype>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <assert.h>
using namespace std;

int dfs(long long p, long long q){
	if(q-p==1)
		return 1;
	else if(p>=q)
		return 0;
	else{
		return dfs(p,q/2)+1;
	}
}

long long gcd(long long a, long long b){
	long long rem;
	while(b>0){
		rem = a%b;
		a=b;
		b=rem;
	}
	return a;
}

int main(){
	freopen("E:\\C\\a4.in","r",stdin);
	freopen("E:\\C\\a4.out","w",stdout);
	int t;
	cin>>t;
//	cout<<sizeof(int);
	for(int cc=1;cc<=t;cc++){
		long long p,q;
		scanf("%lld/%lld",&p,&q);
		long long g=gcd(p,q);
		p /= g;
		q /= g;
		int count=0;
		long long tmp=q;
		while(tmp!=1 && tmp%2==0){
			tmp/=2;
		}
		if(tmp!=1){
			printf("Case #%d: impossible\n",cc);
			continue;
		}
		count=dfs(p,q);
		if(count<=40)
			printf("Case #%d: %d\n",cc,count);
		else
			printf("Case #%d: impossible\n",cc);
	}
	return 0;
}
