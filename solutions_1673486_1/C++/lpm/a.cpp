#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <valarray>

using namespace std;

#define ALL(v) (v).begin(),(v).end()
typedef pair<int,int> pii;

#define MAXN (100010)
double nerrei[MAXN];

int main(){
	int nteste,nt;
	
	scanf("%d",&nteste);
	for(nt = 1;nt<=nteste;nt++){
		int a,b,i;
		double p;
		
		scanf("%d %d",&a,&b);
		
		for(i=0;i<a;i++){
			scanf("%lf",&p);
			if(i==0)
				nerrei[i] = p;
			else	nerrei[i] = nerrei[i-1]*p;
		}
		
		double resp = 2+b;
		double est1 = (b-a+1)*nerrei[a-1] + (b-a+1+b+1)*(1 - nerrei[a-1]);
		
		resp = min(resp,est1);
		
		for(int k=1;a-k >= 1;k++){
			double est3 = (k+b-a+k+1)*nerrei[a-k-1] + (k+b-a+k+1+1+b)*(1-nerrei[a-k-1]);
			resp = min(resp,est3);
		}
		printf("Case #%d: %f\n",nt,resp);
	}
	
}
