#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<ctime>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cassert>
#include<bitset>

using namespace std;
typedef long long LL;
string s,ans;
int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int numcase;
	cin>>numcase;
	scanf("\n");
	for(int ii=1;ii<=numcase;ii++)
	{
		cin>>s;
		ans="";
		int len=s.length();
		for(int i=0;i<len;i++)
		{
			char ch=s[i];
			ans = max(ans+ch,ch+ans);
		}
		printf("Case #%d: ",ii);
		cout<<ans<<endl;
	}
	return 0;
}
