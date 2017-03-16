#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

long long ar[102][102];

int main() 
{
	freopen("input.txt","r",stdin);
	freopen("outputA.txt","w",stdout);
	long long T,t,i,j,n,r,c,w,ans;
	cin>>T;
	for(t=0;t<T;t++)
	{
		cin>>r>>c>>w;
		memset(ar,0,sizeof(ar));
		ans=0;
		cout<<"Case #"<<t+1<<": "<<(r-1)*(c/w)+(ceil((c*1.0)/w)-1+w)<<"\n";
	}
	return 0;
}
