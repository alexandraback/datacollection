#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <cstdlib>

using namespace std;

const int tmax = (int)1e5 + 100;

#define pb push_back
#define mp make_pair

long long arr[] = {1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,12345654321,40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004};

int main()
{
	/*freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-outp.out", "w", stdout);*/
	int t, tt = 1;
	scanf("%d", &t);
	while(t--){
		long long a,b;
		scanf("%lld %lld", &a, &b);
		int cc = 0;
		for( int i = 0; i < 39; i++)		
			if( arr[i] >= a && arr[i] <= b ) cc++;
		printf("Case #%d: %d\n",tt++, cc);
	}
	
	return 0;
}

