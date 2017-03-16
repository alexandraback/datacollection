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
ll is[1000010];


 int main()
{
	//freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
	//freopen("AA.in","r",stdin);freopen("AA.out","w",stdout);
	int testcase;
	
	ll ans=0;
	
	scanf("%d",&testcase);
	for (int case_id=1;case_id<=testcase;case_id++)
	{
		ans=0;
		printf("Case #%d: ",case_id);


		string s;
		int n;
		cin>>s>>n;

		int l=s.length();

		int cur=0;
		int flg=0;
		is[0]=0;
		for(int i=0;i<l;i++)
		{
			if(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u')
			{
				cur++;
				if(cur>=n)
				{
					is[i+1]=is[i]+i-n+2;
					flg=i;
				}
				else
				{
					if(flg-n+2>0&&flg>0)
						is[i+1]=is[i]+flg-n+2;
					else
						is[i+1]=is[i];
				}
			}
			else
			{
				cur=0;
				if(flg-n+2>0&&flg>0)
						is[i+1]=is[i]+flg-n+2;
					else
						is[i+1]=is[i];
			}
		}
		ans=is[l];


		printf("%I64d",ans);
		printf("\n");
	}
	return 0;
}

