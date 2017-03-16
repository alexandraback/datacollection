
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
        
using namespace std;

#define LL long long
LL gcd(LL x,LL y)
{
	if(y==0)return x;
	x=x%y;
	return gcd(y,x);
}
bool bitcheck(LL x)
{
	while(x>1){
		if(x%2)return false;
		x/=2;
	}
	return true;
}

int main()
{
	int t;
	cin>>t;
	for(int cas=1;cas<=t;cas++){
		LL P,Q;
		scanf("%I64d/%I64d",&P,&Q);
		int cnt=0;
		while(P>0){
			cnt++;
			if(2*P<Q)P=2*P;
			else{
				P=2*P-Q;
				LL d=gcd(P,Q);
				P/=d;Q/=d;
				if(!bitcheck(Q))cnt=-1;
				break;
			}
		}
		printf("Case #%d: ",cas);
		if(cnt>=0)cout<<cnt<<endl;
		else printf("impossible\n");
	}
	return 0;
}