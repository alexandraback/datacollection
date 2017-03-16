#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;



int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    
    int T;
	scanf(" %d",&T);
	for(int t=0;t<T;t++){
		int a,b,k;
		scanf(" %d %d %d",&a,&b,&k);
		int ans = 0;
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
				if((i&j) < k)
					ans++;
		printf("Case #%d: %d\n",t+1,ans);
	}
    
    return 0;
}