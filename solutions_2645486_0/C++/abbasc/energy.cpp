#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int compare (const void * a, const void * b)
{
  return ( *(int*)b - *(int*)a );
}


int main()
{
	freopen("energy3.in","r",stdin);
	freopen("energy.txt","w",stdout);
	int t,x;
	cin>>t;
	for(x = 1; x <= t; x++)
	{
		int e,r,n,i,j,a,y = 0,used,max;
		int arr[10000];
		cin>>e>>r>>n;
		for(i = 0;i < n;i++)
		{
			cin>>arr[i];
		}
		a = e;
		for(i = 0;i < n;i++)
		{
			max = i;
			for(j = i+1;j < n;j++)
			{
				if(arr[j] > arr[max])
				{
					max = j;
					break;
				}
			}
			if(max == i)
				used = a;
			else
			{
				if(r*(max-i) > e)	used = a;
				else if(r*(max-i) + a > e)	used = (r*(max-i) + a - e);
				else used = 0;
			}
			y += used*arr[i];

			a = a - used + r;
		}
		cout<<"Case #"<<x<<": "<<y<<endl;
	}
	return 0;
}
