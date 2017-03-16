#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <deque>
#include <set>
using namespace std;

string ans;
bool OK (int n, int x, int y)
{
	ans.clear();
	int left,right,top,bottom,M,i;
	while (n)
	{
		left=0;right=0;top=0;bottom=0;
		//cout<<x<<" "<<y<<endl;
		if (x>=0) left=x;
		if (x<0) right=-x;
		if (y>=0) bottom=y;
		if (y<0) top=-y;
		//cout<<left<<" "<<right<<" "<<bottom<<" "<<top<<endl;
		M=max(max(left,right),max(top,bottom));
		if (M==left) {x-=n; ans+='W'; n--; continue;}
		if (M==right) {x+=n; ans+='E'; n--; continue;}
		if (M==bottom) {y-=n; ans+='S'; n--; continue;}
		y+=n; n--;  ans+='N';
	}
	if (x || y) return false;
	for (i=ans.size()-1; i>=0; i--) 
	{
		if (ans.at(i)=='W') cout<<'E';
		if (ans.at(i)=='E') cout<<'W';
		if (ans.at(i)=='S') cout<<'N';
		if (ans.at(i)=='N') cout<<'S';
	}
	cout<<endl;
	return true;
}

int main()
{
    freopen("B-small-attempt0.in", "r", stdin); freopen("output.txt", "w", stdout);
	int i,t,x,y,j=0;
	cin>>t;
	for (i=1; i<=t; i++)
	{
		cin>>x>>y;
		cout<<"Case #"<<i<<": ";
		j=1;
		while (1)
		{
			if (OK(j,x,y)) break;
			j++;
		}
	}
    return 0;
}