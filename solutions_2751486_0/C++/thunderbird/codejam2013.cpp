#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long ll;

 int main()
{
	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
	//freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
	//freopen("AA.in","r",stdin);freopen("AA.out","w",stdout);
	int testcase;
	
	int ans=0;
	
	scanf("%d",&testcase);
	for (int case_id=1;case_id<=testcase;case_id++)
	{
		ans=0;
		printf("Case #%d: ",case_id);

		string s;
		int n;
		cin>>s>>n;

		int l=s.length();
		for(int i=0;i<l;i++)
		{
			if(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u')
				s[i]='c';
			else
				s[i]='v';
		}
		for(int i=0;i<l;i++)
		{
			int num=0;
			int cur=0;
			for(int j=i;j<l;j++)
			{
				if(s[j]!='v')
				{
					cur++;
					num=num>cur?num:cur;
					
				}
				else
					cur=0;
				if(num>=n) ans++;
			}
		}



		printf("%d",ans);
		printf("\n");
	}
	return 0;
}

