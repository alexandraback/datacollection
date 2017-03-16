#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

string ans,s;
int T;

int main()
{
//	freopen("A-small-attempt0.in","r",stdin);
//	freopen("A-small-attempt0.out","w",stdout);
	scanf("%d",&T);
	for (int id=1; id<=T; id++)
	{
		cin >> s;
		ans="";
		int n=s.size();
		for (int i=0; i<n; i++)
		  if (ans[0]<=s[i])
		    ans=s[i]+ans; else
		    ans=ans+s[i];
		cout << "Case #" << id << ": " << ans << endl;
	}
	return 0;
}
