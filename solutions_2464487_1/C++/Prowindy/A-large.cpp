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
#define maxn 100010
#define LL long long
LL r,tot;
LL cal(LL n)
{
	return n*(n+1)/2;
}
int main()
{
	freopen("A-large.in","r",stdin),freopen("A-large.out","w",stdout);
	int i,j,k,t,cas;
	scanf("%d",&t);
	for(cas=1;cas<=t;cas++){
		cin>>r>>tot;
		LL L=1,R=tot,res=0;
		while(L<=R){
			LL mid=(L+R)/2;
			if(2*mid+2*r-1<=tot/mid){
				res=mid;
				L=mid+1;
			}else R=mid-1;
		}
		printf("Case #%d: ",cas);
		cout<<res<<endl;
	}
}
