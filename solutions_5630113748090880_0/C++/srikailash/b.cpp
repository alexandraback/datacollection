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
int test , N , temp;
scanf("%d",&test);
set<int > S;
for(int o=1;o<=test;o++)
{
	S.clear();
	scanf("%d",&N);
	for(int i=1;i<=((2*N)-1);i++)
	{
		for(int j=1;j<=N;j++)
		{
			scanf("%d",&temp);
			if(S.find(temp)==S.end())
				S.insert(temp);
			else
				S.erase(S.find(temp));
		}
	}
	set<int >::iterator it = S.begin();
	printf("Case #%d: ",o );
	cout << *(S.begin());
	it++;
	while(it!=S.end())
	{
		cout << " " << *it ;
		it++;
	}
	cout << endl;
}
return 0;
}






