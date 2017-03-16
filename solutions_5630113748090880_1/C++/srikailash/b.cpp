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
std::vector<int > answer;
int main()
{
int test , N , temp;
scanf("%d",&test);
// set<int > S;
int freq[2504];
for(int j=0;j<2504;j++)
	freq[j] = 0;
for(int o=1;o<=test;o++)
{
	answer.clear();
	for(int j=0;j<2504;j++)
		freq[j] = 0;
	// S.clear();
	scanf("%d",&N);
	for(int i=1;i<=((2*N)-1);i++)
	{
		for(int j=1;j<=N;j++){
			scanf("%d",&temp);
			freq[temp] = 1 - freq[temp];

		}
	}
	printf("Case #%d: ",o );
	for(int i=1;i<=2500;i++)
	{
		if(freq[i]==1)
			answer.push_back(i);
	}
	// printf("\n");
	printf("%d", answer[0]);
	for(int i=1;i<answer.size();i++)
		printf(" %d", answer[i]);
	printf("\n");
}
return 0;
}






