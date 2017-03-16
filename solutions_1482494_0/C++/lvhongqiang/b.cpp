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


#define SMALL
//#define LARGE

int findb(int *a,int *b,int length,int star)
{
	int r=-1;
	for(int i=0;i<length;i++)
	{
		if(b[i]<=star&&b[i]!=-1)
		{
			if(r==-1)
				r=i;
			else
			{
				if(a[i]!=-1)
					r=i;
			}
		}
	}
	return r;
}
int finda(int *a,int *b,int length,int star)
{
	int r=-1;
	for(int i=0;i<length;i++)
	{
		if(a[i]<=star&&a[i]!=-1)
		{
			if(r==-1)
				r=i;
			else
			{
				if(b[i]>b[r])
					r=i;
			}
		}
	}
	return r;
}
int main() {

#ifdef SMALL
	freopen("B-small.in","rt",stdin);
	freopen("B-small.out","wt",stdout);
#endif
#ifdef LARGE
	freopen("B-large.in","rt",stdin);
	freopen("B-large.out","wt",stdout);
#endif
	
	int N,num;
	int *a,*b;
	int star=0,count=0;
	int r=0;
	cin >> N;
	for(int n=1;n<N+1;n++)
	{	
		star=0;
		count=0;
		cin>>num;
		a=new int[num];
		b=new int[num];
		printf("Case #%d: ", n);
		for(int i=0;i<num;i++)
		{
			cin>>a[i]>>b[i];
		}
		if(n==100)
		{
			n=100;
		}
		while(star<num*2)
		{
			r=findb(a,b,num,star);
			if(r==-1)
			{
				r=finda(a,b,num,star);
				if(r==-1)
				{
					break;
				}
				else
				{
					a[r]=-1;
					star++;
					count++;
				}
			}
			else
			{
				if(a[r]!=-1)
				{
					a[r]=-1;
					b[r]=-1;
					star+=2;
					count++;
				}
				else
				{
					b[r]=-1;
					star++;
					count++;
				}
			}
		}
		if(star==num*2)
			cout<<count;
		else
			cout<<"Too Bad";
		cout<<endl;
	
	}
	
	return 0;
}
