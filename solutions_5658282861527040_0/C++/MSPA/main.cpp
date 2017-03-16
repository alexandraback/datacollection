#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <assert.h>

#define file_name ""

typedef long long ll;

const int N = 1e5+5;

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int countTests;
	scanf("%d",&countTests);
	for(int numTest=1;numTest<=countTests;++numTest)
	{
		int a, b,k;
		scanf("%d%d%d",&a,&b,&k);
		int ans =0;
		for(int i=0;i<a;++i)
			for(int j=0;j<b;++j)
				if ((i&j)<k) ++ans;
		printf("Case #%d: ", numTest);
		printf("%d\n",ans);
	}
	return 0;
}
