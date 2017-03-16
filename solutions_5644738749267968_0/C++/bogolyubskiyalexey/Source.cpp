#include<iostream>
#include<algorithm>
using namespace std;
double a[2000],b[2000];



void solve(int test)
{
	int N,i,l,r,answer1=0,answer2=0;
	scanf("%d",&N);
	for(i=0;i<N;i++) scanf("%lf",&a[i]);
	for(i=0;i<N;i++) scanf("%lf",&b[i]);
	sort(a,a+N);	sort(b,b+N);

	
	l=0;	r=N-1;
	for(i=0;i<N;i++)
	{
		if(a[i]<b[l])
		{
			r--;
		}
		else
		{
			answer1++;
			l++;
		}
	}


	r=0;
	for(l=0;l<N;l++)
	{
		while(a[l]>b[r]&&r<N) r++;
		if(r>=N) answer2++;
		r++;
	}
	printf("Case #%d: %d %d\n",test,answer1,answer2);

	
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int Tests,i;
	scanf("%d",&Tests);
	for(i=1;i<=Tests;i++) solve(i);
	return 0;
}