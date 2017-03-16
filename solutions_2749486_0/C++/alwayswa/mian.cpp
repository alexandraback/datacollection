/*题意:黑书295
 *解法：黑书295
 */
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<map>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
string a="EW";
string b="WE";
string c="NS";
string d="SN";

int main()
{
	freopen("data.in","r",stdin);
	freopen("data1.out","w",stdout);
	int t;
	scanf("%d",&t);
	int cas=0;
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		printf("Case #%d: ",++cas);
		if(x>0)
		for(int i=0;i<x;i++)
			cout<<b;
		else
		for(int i=0;i<-x;i++)
			cout<<a;
		if(y>0)
			for(int i=0;i<y;i++)
			cout<<d;
		else
			for(int i=0;i<-y;i++)
				cout<<c;
		cout<<endl;

	}
}
