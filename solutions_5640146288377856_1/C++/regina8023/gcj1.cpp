#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int T,r,c,w;
int main()
{
	freopen("t.in","r",stdin);freopen("t.out","w",stdout);
	cin>>T;
	for (int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		scanf("%d%d%d",&r,&c,&w);
		int k=c/w-1;
		int le=c-k*w;
		cout<<(r-1)*(c/w)+(k+(le!=w)+w)<<endl;
	}
	return 0;
}
