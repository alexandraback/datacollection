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
int test;
scanf("%d",&test);
string A , B , P , Q , ansA , ansB;

int min_diff , N , X , Y , m , n;
char y;
int flag = 0;
for(int o=1;o<=test;o++)
{
	printf("Case #%d: ", o);
	cin >> A >> B;
	min_diff = 1000000;
	int len = A.length();
	N = 1;
	flag = 0;

	for(int v=1;v<=len;v++)
			N*=10;


	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			flag = 0;
			X = i;
			Y = j;
			// while(X!=0)
			P = "";
			Q = "";

			for(int v=1;v<=len;v++)
			{
				m = (X%10);
				y = m + '0';
				X =(X/10);
				P = P + y;
			}

			for(int v=1;v<=len;v++)
			{
				m = (Y%10);
				y = m + '0';
				Y =(Y/10);
				Q = Q + y;
			}
			// cout << i << " " << j << " " << P << " " << Q << endl;
			for(int v=0;v<len;v++)
			{
				if(A[v]!='?' && P[len - v - 1]!=A[v])
					flag = 1;
			}
			
			for(int v=0;v<len;v++)
			{
				if(B[v]!='?' && Q[len - v -1]!=B[v])
					flag = 1;
			}
			if(flag==0)
			{
			if(abs(j-i) < min_diff)
			{
				
				min_diff = abs(j - i);
				ansA = P;
				ansB = Q;
			}
			}	


		}
	}
	// cout << ansA << " " << ansB << endl;
	for(int v=len-1;v>=0;v--)
		cout << ansA[v];
	cout << " ";
	for(int v=len-1;v>=0;v--)
		cout << ansB[v];
	printf("\n");
}
return 0;
}






