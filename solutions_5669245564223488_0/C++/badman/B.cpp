#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <map>
#include <iostream>
#include <string>

using namespace std;

char buffer[2048];

#define FILE_NAME "B-small-attempt0"
#define ULL unsigned long long
#define CASET int _t=0, case_num;cin>>case_num;while(++_t<=case_num)

typedef vector<int> VI;
typedef vector<VI> VVI;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char dir[4] = {'E', 'S', 'W', 'N'};

vector<string> arr;

ULL solve()
{
	ULL ans = 1;
	vector<vector<string>> groupStr;
	for(int i=0;i<arr.size();i++)
	{
		vector<string> tGroup;
		tGroup.push_back(arr[i]);
		while((i+1)<arr.size() && (arr[i].back()==arr[i+1].front()))
		{
			tGroup.push_back(arr[i+1]);
			i++;
		}
		groupStr.push_back(tGroup);
	}
	if(groupStr.size()==1)
		return 1;
	else if(groupStr.size()==arr.size())
		return 0;
	VI tmp;
	for(int i=0;i<groupStr.size();i++)
	{
		map<string, int> temp;
		for(int j=0;j<groupStr[i].size();j++)
		{
			string t;
			t.append(1, groupStr[i][j].front());
			t.append(1, groupStr[i][j].back());
			if(temp.count(t)>0)
				temp[t]+=1;
			else
				temp[t] = 1;
		}
		map<string, int>::iterator it;
		for(it=temp.begin();it!=temp.end();it++)
		{
			for(int j=1;j<=(*it).second;j++)
				ans*=j;
		}
	}
	for(int i=1;i<=groupStr.size();i++)
		ans*=i;
	
	return ans;
}	

map<string, int> mp;

int main()
{
	sprintf(buffer, "%s.in", FILE_NAME);
	freopen(buffer, "r", stdin);
	sprintf(buffer, "%s.out", FILE_NAME);
	freopen(buffer, "w", stdout);

	CASET
	{
		printf("Case #%d: ", _t);
		int n;
		cin>>n;
		arr.clear();
		for(int i=0;i<n;i++)
		{
			string s;
			cin>>s;
			arr.push_back(s);
		}
		ULL ans = solve();
		printf("%u", ans);
		printf("\n");
	}
		
	return 0;
}