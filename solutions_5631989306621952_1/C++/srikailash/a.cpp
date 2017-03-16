#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 9223372036854775807LL
#define INF 2000000000
#define PI acos(-1.0)
#define inf INT_MAX
using namespace std;
typedef long long int LL;
int main()
{
int N , test;
string ip , ans ;
scanf("%d",&test);
for(int i=1;i<=test;i++)
{
ans = "";
cin >> ip;
for(int j=0;j<ip.length();j++)
{
	if(j==0)
		ans = ans + ip[0];
	else
	{
		if(ip[j]>=ans[0])
			ans = ip[j] + ans;
		else
			ans = ans + ip[j];
	}
}
cout << "Case #" << i << ": "<< ans << endl;
}

return 0;
}


