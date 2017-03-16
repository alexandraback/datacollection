#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;

int t;
int r,c,w;

int main()
{
	freopen("A.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin>>t;
	for(int files=1; files<=t; files++)
	{
		cin>>r>>c>>w;
		int ans=0;
		ans = c/w;
		ans *=r;
		ans += w;
		if(c%w==0)
			ans--;
		printf("Case #%d: %d\n", files, ans);
	}
	//system("pause");
	return 0;
}




