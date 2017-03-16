#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <string.h>
#define MOD 1000000007

using namespace std;

long long int countt;
int n;
void check(string full)
{
	int a[26]={0};
	a[full[0]-'a']=1;
	for (int i = 1; i < full.length(); ++i)
	{
		if(full[i]!=full[i-1])
		{
			if(a[full[i]-'a']) return;
			a[full[i]-'a']=1;
		}
	}
	countt++;

}

void recurse(string car[], int * isused, int level,string full)
{
	if(level==n) check(full);

	for (int i = 0; i < n; ++i)
	{
		if(!isused[i])
		{
			isused[i]=1;
			recurse(car,isused,level+1,full+car[i]);
			isused[i]=0;
		}
	}
}

int main()
{
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		string car[11];
		//int n;
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			cin>>car[i];
		}
		int same[26];
		countt=0;
		int isused[11]={0};
		string full;
		recurse(car,isused,0,full);
		printf("%lld\n",countt );
	}

}