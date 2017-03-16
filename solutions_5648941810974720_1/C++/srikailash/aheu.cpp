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

int freq[50];

int main()
{
int test;
scanf("%d",&test);

string ip;
// while(test--)
int arr[12];
for(int o=1;o<=test;o++)
{
	cin >> ip;
	memset(freq  , 0 , sizeof(freq));
	printf("Case #%d: ", o);
	for(int j=0;j<ip.length();j++)
	{
		freq[ip[j] - 'A' + 1]++;
	}
	arr[0] = freq['Z' - 'A' + 1];
	arr[2] = freq['W' - 'A' + 1];
	arr[4] = freq['U' - 'A' + 1];
	arr[6] = freq['X' - 'A' + 1];
	arr[8] = freq['G' - 'A' + 1];
	arr[7] = freq['S' - 'A' + 1] - arr[6];
	arr[5] = freq['V' - 'A' + 1] - arr[7];
	arr[3] = freq['H' - 'A' + 1] - arr[8];
	arr[9] = freq['I' - 'A' + 1] - arr[5] - arr[6] - arr[8];
	arr[1] = freq['O' - 'A' + 1] - arr[0] - arr[2] - arr[4];


	for(int i=0;i<=9;i++)
	{
		for(int j=1;j<=arr[i];j++)
			printf("%d", i);
	}
	printf("\n");
}
return 0;
}




