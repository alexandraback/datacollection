#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

map<string,int> mp1,mp2;
const int Maxn = 20;
struct str{
	string s1,s2;
	bool operator < (const str& x) const{
		if(x.s1!= s1)
			return s1 < x.s1;
		return s2 < x.s2;
	}
}s[Maxn],p[Maxn];
int main()
{
	freopen("C-small-attempt2.in","r",stdin);
	freopen("C-small-attempt2.out","w",stdout);
	int T,N;
	
	cin>>T;
	for(int cas = 1;cas <= T;cas ++)	
	{
		cin>>N;
		cout<<"Case #"<<cas<<": ";
		int ans = 0;
		for(int i = 0;i < N;i ++)
		{
			cin>>s[i].s1>>s[i].s2;
		}
		sort(s,s + N);
		
		//cout<<endl;
		//for(int i = 0;i < N;i ++)
		//	cout<<s[i].s1<<" "<<s[i].s2<<endl;
		int cnt = 0;
		for(int i = 0;i < N;i ++)
		{
			if(mp1.find(s[i].s1) == mp1.end() && mp2.find(s[i].s2) == mp2.end())
			{
				mp1[s[i].s1]++,mp2[s[i].s2]++;
			}
			else
				p[cnt].s1 = s[i].s1,p[cnt++].s2= s[i].s2;
				
		}
		for(int i = 0;i < cnt;i ++)
		{
			if(mp1.find(p[i].s1) != mp1.end() && mp2.find(p[i].s2) != mp2.end())
				ans ++;
			else 
				mp1[p[i].s1]++,mp2[p[i].s2]++;
		}
		cout<<ans<<endl;
		mp1.clear();
		mp2.clear();
	}
	return 0;
}