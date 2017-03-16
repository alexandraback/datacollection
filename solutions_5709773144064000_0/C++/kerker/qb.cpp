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
	cin >> T;
	for(int t=0;t<T;t++){
		double c,f,x,r = 2.0f,ans = 100000000.0f,now = 0.0f,need;
		cin >> c >> f >> x;
		for(int i=0;i<200000;i++){
			need = x/r;
			if(now+need < ans)
				ans = now+need;
			else break;
			need = c/r;
			now += need;
			r += f;
		}
		printf("Case #%d: %.7lf\n",t+1,ans);
	}
    
    return 0;
}