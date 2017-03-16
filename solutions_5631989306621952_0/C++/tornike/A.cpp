#include <iostream>
#include <cstdio>
using namespace std;

string s,ans;
int mas[1001];
void solve()
{
	ans="";
	//ans+=s[0];
	int biggest = s[0];
	mas[0] = 1;
	for(int i = 1 ; i < s.length();i++)
	{
		if(s[i] >= biggest)
		{
			biggest = s[i];
			mas[i] = 1;
		}else{
			mas[i] = -1;
		}
	}
	ans = "";
	for(int i = s.length() - 1 ; i >= 0 ; i --)
			if(mas[i]==1)
		 ans+=s[i];	
	for(int i =0 ; i < s.length() ; i ++)
			if(mas[i]==-1)
		 ans+=s[i];	
		
}
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("1.out","w",stdout);
	int t;
	cin >> t;
	for(int i = 0 ; i < t ; i++)
	{
		cin >> s;
		solve();
		printf("Case #%d: %s\n",i+1,ans.c_str());
	}
	
}
