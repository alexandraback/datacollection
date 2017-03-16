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
#include <queue>

using namespace std;

void process(){
	double cost,get,op,ans;
	scanf("%lf %lf %lf",&cost,&get,&op);
	ans=op/2;
	double a=op,gt=0.0;
	for(int i=0;;i++){
		if(i!=0){
			gt+=cost/(2+get*(i-1));
			a+=cost+gt*get;
		}
		double b=2+get*i;
		double an=ans;
		ans=min(ans,a/b);
		if(i>=1 && an==ans) break;
	}
	printf("%.9lf\n",ans);
}

int main(){
	int t;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		printf("Case #%d: ",i);
		process();
	}
	return 0;
}