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

long long op[39]={
1,
4,
9,
121,
484,
10201,
12321,
14641,
40804,
44944,
1002001,
1234321,
4008004,
100020001,
102030201,
104060401,
121242121,
123454321,
125686521,
400080004,
404090404,
10000200001,
10221412201,
12102420121,
12345654321,
40000800004,
1000002000001,
1002003002001,
1004006004001,
1020304030201,
1022325232201,
1024348434201,
1210024200121,
1212225222121,
1214428244121,
1232346432321,
1234567654321,
4000008000004,
4004009004004
};


int main()
{
    //freopen("C-large-1.in","r",stdin);
    //freopen("out.txt","w",stdout);
    
    int T,t,i,j;
	long long A,B;
	scanf(" %d",&T);
	for(t=1;t<=T;t++){
		scanf(" %lld %lld",&A,&B);
		int ans = 0;
		for(i=0;i<39;i++)
			if(op[i]>=A && op[i]<=B)
				ans++;
		printf("Case #%d: %d\n",t,ans);
	}
    
    return 0;
}