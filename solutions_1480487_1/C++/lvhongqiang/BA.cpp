#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>

using namespace std;


//#define SMALL
#define LARGE

int main() {

#ifdef SMALL
	freopen("A-small-attempt1.in","rt",stdin);
	freopen("A-small.out","wt",stdout);
#endif
#ifdef LARGE
	freopen("A-large.in","rt",stdin);
	freopen("A-large.out","wt",stdout);
#endif
	
	int N,num;
	cin >> N;
	for(int n=1;n<N+1;n++)
	{	
		cin>>num;
		int a[200];  
		for(int i=0;i<num;i++)
		{
			cin>>a[i];
		}
		printf("Case #%d: ", n);
		int count=0;
		for(int i=0;i<num;i++)
		{
			count+=a[i];
		}
		float avg=(float)(count*2)/(float)num;
		int count2=count*2;
		int num2=num;
		for(int i=0;i<num;i++)
		{
			double p=0;
			if(a[i]>=avg)
			{
				num2=num2-1;
				count2=count2-a[i];
			}
			
		}
		avg=(float)count2/(float)num2;
		for(int i=0;i<num;i++)
		{
			double p=0;
			if(a[i]>=avg)
			{
				printf("%.6f",p);
			}
			else
			{
				p=(float)((avg-a[i])*100)/(float)count;
				printf("%.6f",p);
			}
			cout<<" ";
		}

		cout<<endl;
	
	}
	
	return 0;
}
