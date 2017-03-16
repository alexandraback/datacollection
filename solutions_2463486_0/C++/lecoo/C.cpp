#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

bool isPalindroms(const char* buf)
{
	int len = strlen(buf);
	for(int i=0;i<len/2;i++)
	{
		if(buf[i]!=buf[len-1-i])
			return false;
	}
	return true;
}

bool isPalindroms(int n)
{
	char buf[128];
	sprintf(buf, "%d", n);
	return isPalindroms(buf);
}

bool isSq(int n)
{
	int r = (int)(sqrt(double(n))+0.5f);
	return r*r == n;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int kcase = 1; kcase <=T; kcase++)
	{
		int A,B;
		scanf("%d%d",&A,&B);
		int cnt = 0;
		for(int i=A;i<=B;i++)
		{
			if(isPalindroms(i) && isSq(i) && isPalindroms((int)(sqrt(double(i))+0.5f)) )
			{
				cnt++;				
			}
		}
		printf("Case #%d: %d\n", kcase, cnt);
	}
}
