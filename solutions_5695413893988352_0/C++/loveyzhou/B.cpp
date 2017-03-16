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

vector<int> vec;
void dfs(string s,int x,vector<int> &v)
{
	//cout<<s<<" "<<x<<endl;
	if(x >= s.length())
	{	
		int ans = 0;
		for(int i = 0;i < s.length();i ++)
		{
			ans = ans * 10 + vec[i];	
		}
		//cout<<ans<<endl;
		//cout<<endl;
		v.push_back(ans);
		return ;
	}
	for(int i = x;i < s.length();i ++)
	{
		if(s[i] == '?')
		{
			for(int j = 0;j < 10;j ++)
			{
				vec[i] = j;;
				dfs(s,max(i,x) + 1,v);
				//vec.erase(vec.end() - 1);
			}
		}
		else
		{
			vec[i] = s[i] - '0';
			//vec.push_back(s[i] - '0');
			dfs(s,i + 1,v);
		}
			
		
	}
}
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	vector<int> v1,v2;
	int T,len1,len2;
	string s1,s2;
	cin>>T;
	for(int cas = 1;cas <= T;cas ++)	
	{
		cin>>s1>>s2;
		cout<<"Case #"<<cas<<": ";
		len1 = s1.length();
		len2 = s2.length();
		v1.clear();
		v2.clear();

		for(int i = 0;i < max(len1,len2);i++)
			vec.push_back(0);
		dfs(s1,0,v1);
		for(int i = 0;i < len2;i++)
			vec[i] = 0;
		dfs(s2,0,v2);
		
		int Min = 100000,k1,k2;

		for(int i = 0;i < v1.size();i ++)
		{
			for(int j = 0;j < v2.size();j ++)
			{
				//cout<<v1[i]<<" "<<v2[j]<<endl;
				if(abs(v1[i] - v2[j]) < Min)
				{
					Min = abs(v1[i] - v2[j]);
					k1 = i;
					k2 = j;
				}
			}
		}
		int tmp = v1[k1];
		int cnt;
		if(tmp == 0)
		{
			for(int i = 0;i < len1;i ++)
				cout<<"0";
			cout<<" ";
		}
		else
		{
			cnt = len1;
			while(tmp)
			{
				cnt --;
				tmp /= 10;
			}
			for(;cnt > 0;cnt --)
				cout<<"0";
			cout<<v1[k1]<<" ";
		}
		
		tmp = v2[k2];
		cnt = len2;
		if(tmp == 0)
		{
			for(int i = 0;i < len2;i ++)
				cout<<"0";
			cout<<endl;
		}
		else
		{
			while(tmp)
			{
				cnt--;
				tmp /= 10;
			}
			for(;cnt > 0;cnt --)
				cout<<"0";
			cout<<v2[k2]<<endl;
		}
		
		//cout<<v1[k1]<<" "<<v2[k2]<<endl;
		
	}
	return 0;
}