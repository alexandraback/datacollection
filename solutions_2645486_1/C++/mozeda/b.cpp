#include <cstdio>
#include <iostream>

using namespace std;
struct node{
	int l, r;
	int start, end;
	bool operator<(node b)
	{
		return l<b.l;
	}
};

long long int a[11000];
long long int ma[11000][30];
int mai[11000][30];
long long int e, rr, n;
int findmax(int l, int r)
{
	int i=0;
	if (l==r) return l;
	while (l+(1<<i)-1<r) ++i;
	--i;
	if (ma[l][i]>ma[r+1-(1<<i)][i])
		return mai[l][i];
	return mai[r+1-(1<<i)][i];
}
long long int calc(int l, int r, long long int start, long long int end)
{
//	printf("%d %d %d %d\n", l, r, start, end);
	int ti = findmax(l, r);
	long long int tmax = start+(ti-l)*rr;
	long long int tmust = end-(r-ti+1)*rr;
	if (tmust<0) tmust=0;
	if (tmax>e) tmax=e;
//	printf("%d %d %d\n", ti, tmax, tmust);
	long long int tl=0, tr=0;
	if (ti>l) tl=calc(l, ti-1, start, tmax);
	if (ti<r) tr=calc(ti+1, r, tmust+rr, end);
	return tl+tr+(tmax-tmust)*a[ti];
}
int T;
int main()
{
	cin>>T;
	for (int I=1;I<=T;++I)
	{
		cin>>e>>rr>>n;
		for (int i=0;i<n;++i)
			cin>>a[i];
		for (int i=0;i<n;++i)
		{
			ma[i][0]=a[i];
			mai[i][0]=i;
		}
		for (int j=1;j<=15;++j)
			for (int i=0;i+(1<<j)<=n;++i)
			{
				if (ma[i][j-1]<ma[i+(1<<j-1)][j-1])
				{
					ma[i][j]=ma[i+(1<<j-1)][j-1];
					mai[i][j]=mai[i+(1<<j-1)][j-1];
				}
				else
				{
					ma[i][j]=ma[i][j-1];
					mai[i][j]=mai[i][j-1];
				}
			//	printf("c%d %d %d\n", i, j, mai[i][j]);
			}
		cout<<"Case #"<<I<<": "<<calc(0,n-1,e,0)<<endl;
		//printf("Case #%d: %d\n",I, calc(0,n-1,e,0)); 
	}
}
