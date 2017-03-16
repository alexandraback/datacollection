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

map<char,int> mp,tmp;
map<char,int>::iterator it;
vector<int> vec;
bool check(string s)
{
	tmp = mp;
	for(int i = 0;i < s.length();i ++)
	{
		if(tmp.find(s[i]) == tmp.end())
			return false;
		tmp[s[i]] --;
		if(tmp[s[i]] == 0)
			tmp.erase(s[i]);
	}
		
	return true;
}
string str[10] = {
	"ZERO",  "TWO", "SIX", "EIGHT", "THREE", "SEVEN", "FOUR","ONE", "FIVE", "NINE"
};
int num[10] = {
	0,2,6,8,3,7,4,1,5,9
};
int main()
{
	freopen("A-small-attempt1.in","r",stdin);
	freopen("A-small-attempt1.out","w",stdout);
	int T;
	string s;
	cin>>T;
	for(int cas = 1;cas <= T;cas ++)	
	{
		cin>>s;
		cout<<"Case #"<<cas<<": ";
		int len = s.length(),tmplen = len;
		mp.clear();
		for(int i = 0;i < len;i ++)
			mp[s[i]]++;

		//for(it = mp.begin();it != mp.end();it++)
		//	cout<<it->first<<" "<<it->second<<endl;
		while(len)
		{
			for(int i = 0;i < 10;i ++)
			{
				while(check(str[i]))
				{
					//cout<<str[i]<<endl;
					for(int j = 0;j < str[i].length();j ++)
					{
						mp[str[i][j]] --;
						if(mp[str[i][j]] <= 0)
							mp.erase(str[i][j]);	
					}
					len -= str[i].length();
					vec.push_back(num[i]);
				}
				if(len <= 0) break;
			}
		}
		sort(vec.begin(),vec.end());
		for(int i = 0;i < vec.size();i ++)
			cout<<vec[i];
		cout<<endl;
		vec.clear();
	}
	return 0;
}