//by jackyliuxx
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int main () {
	int t,cs=1;
	scanf("%d",&t);
	while(t--){
		int a,b,k;
		scanf("%d%d%d",&a,&b,&k);
		int i,j,ans=0;
		for(i=0;i<a;i++)
			for(j=0;j<b;j++)
				if((i&j)<k)
					ans++;
		printf("Case #%d: %d\n",cs++,ans);
	}
}
