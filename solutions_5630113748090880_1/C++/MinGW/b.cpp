#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

const int MAXN=107;
const int MAXM=2507;

int i,j,k,n,m,t,x,y,tcase,xcase;
int lst[MAXN],cnt[MAXM];

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>tcase;
	xcase=0;
	while (xcase<tcase)
	{
		xcase++;
		cout<<"Case #"<<xcase<<": ";
		memset(cnt,0,sizeof(cnt));
		memset(lst,0,sizeof(lst));
		cin>>n;
		for (i=1;i<2*n;i++)
		{
			for (j=0;j<n;j++)
			{
				cin>>x;
				cnt[x]++;
			}
		}
		t=0;
		for (i=0;i<MAXM;i++)
		{
			if (cnt[i]%2==1)
			{
				lst[t++]=i;
			}
		}
		cout<<lst[0];
		for (i=1;i<n;i++)
		{
			cout<<" "<<lst[i];
		}
		cout<<endl;
	}
	return 0;
}

