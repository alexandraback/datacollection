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

int op[5] = {1,4,9,121,484};

int main()
{
    //freopen("C-small-attempt0.in","r",stdin);
    //freopen("out.txt","w",stdout);
    
    int T,t,A,B,i,j;
	scanf(" %d",&T);
	for(t=1;t<=T;t++){
		scanf(" %d %d",&A,&B);
		int ans = 0;
		for(i=0;i<5;i++)
			if(op[i]>=A && op[i]<=B)
				ans++;
		printf("Case #%d: %d\n",t,ans);
	}
    
    return 0;
}