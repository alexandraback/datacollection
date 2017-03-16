#include <algorithm>
#include <numeric>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include <stack>
using namespace std;

long long mas[100];
int A,N;

void solveCase(int t)
{	
	cin>>A>>N;
	for (int i=0;i<N;i++)
		cin>>mas[i];
	sort(mas,mas+N);
	long long mini=N;
	long long maxv=0;
	for (int i=0;i<N;i++)
		maxv=max(maxv,mas[i]);
	long long lft=0;
	long long cura=A, cnt=0;
	while (lft<N)
	{
		while (lft<N&&cura>mas[lft])
		{
			cura+=mas[lft];
			lft++;
		}
		mini=min(mini,cnt+(N-lft));
		cnt++;
		cura=cura*2-1;
		if (cura==1)
			break;
	}
	int m=(int)mini;
	printf("Case #%d: %d\n",t+1,m);
}

int main()
{
	freopen("in.in","rt",stdin);
	freopen("out.out","wt",stdout);
	int t;
	cin>>t;
	for (int i=0;i<t;i++)
		solveCase(i);
	return 0;
}