#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

#define INF (0x7FFFFFFF)

using namespace std;

int memoSqrt[1024];

int findSqrt(int x)
{
	int left = 1, right = x ,mid;
	while(left <= right)
	{
		mid = (left + right) / 2;
		if(mid * mid == x)
		{
			return mid;
		}
		if(mid * mid > x)
		{
			right = mid - 1;
		}
		else if(mid * mid < x)
		{
			left = mid + 1;
		}
	}
	if(mid * mid > x) mid--;
	return memoSqrt[x] = mid;
}

int findAnswer(int panPerPlate, int maxPancake, vector<int> plateCount)
{
    int ret,timeline = 0;
    for(int i = maxPancake; i > panPerPlate; i--)
	{
	    if(plateCount[i] == 0) continue;
	    plateCount[i - panPerPlate] += plateCount[i];
	    plateCount[panPerPlate] += plateCount[i];
	    timeline += plateCount[i];
	    plateCount[i] = 0;
	} 
	for(int i = panPerPlate; i >= 0 ; i--)
	{
	    if(plateCount[i] > 0)
	    {
	        ret = timeline + i;
	        break;
	    }
	}
	return ret;
}

int solve(int totalPancake, int & maxPancake, vector<int> & plateCount)
{
	int ret = INF,a,b,timeline = 0;
//	int panPerPlate = findSqrt(totalPancake);
//	if(totalPancake > panPerPlate * panPerPlate) panPerPlate++;
//	
//	for(int i = 0; i < panPerPlate; i++)
//	{
//	    totalPancake -= plateCount[i] * i;
//	}
//	
//	panPerPlate = findSqrt(totalPancake);
//	if(totalPancake > panPerPlate * panPerPlate) panPerPlate++;
//	
//	for(int i = maxPancake; i > panPerPlate; i--)
//	{
//	    if(plateCount[i] == 0) continue;
//	    plateCount[i - panPerPlate] += plateCount[i];
//	    plateCount[panPerPlate] += plateCount[i];
//	    timeline += plateCount[i];
//	    plateCount[i] = 0;
//	} 
//	for(int i = panPerPlate; i >= 0 ; i--)
//	{
//	    if(plateCount[i] > 0)
//	    {
//	        ret = timeline + i;
//	        break;
//	    }
//	}
    for(int i = 1; i <= maxPancake; i++)
    {
        ret = min(ret,findAnswer(i,maxPancake,plateCount));
    }
    
	return ret;
}

int main()
{
	int t;
	scanf("%d",&t);
	
	for(int ca = 1; ca <= t; ca++)
	{
		int n,x,maxPancake = 0,totalPancake = 0;
		vector<int> plateCount(1024);
		scanf("%d",&n);		
		for(int i = 0 ; i < n; i++)
		{
			scanf("%d",&x);
			plateCount[x]++;
			maxPancake = max(maxPancake,x);
			totalPancake += x;
		}				
		printf("Case #%d: %d\n",ca,solve(totalPancake,maxPancake,plateCount));
	}
	
	return 0;
}
