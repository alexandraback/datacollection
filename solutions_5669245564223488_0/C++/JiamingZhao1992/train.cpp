#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
int arran(int i)
{
	if(i == 1 || i == 0)
		return 1;
	else return (i * arran(i - 1)) % 1000000007;
}

int main(int argc, char *argv[]) {
	ifstream fin("B-small-attempt3.in");
	ofstream fout("train.out");
	
	int free[26];
	bool visit[26][2];
	int nextend[26][2];
	bool final[26];
	int nums[26];
	int cases, n;
	string strs[101];
	fin >> cases;
	for(int cnt = 1; cnt <= cases; ++cnt)
	{
		int result = 1;
		int nu = 0;
		memset(free, 0, sizeof(free));
		memset(visit, false, sizeof(visit));
		memset(nums, 0, sizeof(nums));
		memset(final, true, sizeof(final));
		memset(nextend, 0, sizeof(nextend));
		fout << "Case #" << cnt << ": ";
		fin >> n;

		for(int i = 0; i < n; ++i)
			fin >> strs[i];
		for(int i = 0; i < n; ++i)
		{
			bool fr = true;
			for(int j = 1; j < strs[i].size(); ++j)
			{
				if(strs[i][j] != strs[i][0])
				{
					fr = false;
				}
				if(strs[i][j] != strs[i][j - 1] && strs[i][j] != strs[i][0] && strs[i][j] != strs[i][strs[i].size() - 1])
				{
					if(visit[strs[i][j] - 'a'][0] || visit[strs[i][j] - 'a'][1])
					{
						fout << "0" << endl;
						goto nextloop;
					}
					visit[strs[i][j] - 'a'][0] = visit[strs[i][j] - 'a'][1] = true;
					final[strs[i][j] - 'a'] = false;
				}
				
			}
			if(fr)
			{
				free[strs[i][0] - 'a'] ++;
			}
			else
			{
				if(strs[i][0] == strs[i][strs[i].size() - 1])
				{
				fout << "0" << endl;
				goto nextloop;					
				}
				visit[strs[i][0] - 'a'][0] = true;
				nextend[strs[i][0] - 'a'][0] = strs[i][strs[i].size() - 1] - 'a';
				visit[strs[i][strs[i].size() - 1] - 'a'][1] = true;
				nextend[strs[i][strs[i].size() - 1] - 'a'][1] = strs[i][0] - 'a';
			}
		}
		for(int i = 0; i < 26; ++i)
		{
			cout << char('a' + i) << " " << visit[i][0] << visit[i][1] << endl;
		}
		for(int i = 0; i < 26; ++i)
		{
			nums[i] = arran(free[i]);
		}
		for(int i = 0; i < 26; ++i)
			cout << free['s' - 'a'] << endl;
		for(int i = 0; i < 26; ++i)
		{
			if(visit[i][1] == false && visit[i][0] == true)
			{
				int tem = nextend[i][0];

				while(true)
				{
//					cout << i << char('a' + tem) << endl;
					nums[i] = (nums[i] * nums[tem]) % 1000000007;
					final[tem] = false;
					if(visit[tem][0] == false)
						break;
					tem = nextend[tem][0];
				}
			}
			if(free[i] == 0 && !visit[i][0] && !visit[i][1])
				final[i] = false;
		}
		for(int i = 0; i < 26; ++i)
		{
			cout << char('a' + i) << " " << final[i] << endl;
		}
		for(int i = 0; i < 26; ++i)
		{
			if(final[i])
			{
				nu ++;
				result = (result * nums[i]) % 1000000007;
			}
		}
		result = (result * arran(nu)) % 1000000007;
		fout << result << endl;
nextloop:
;
	}
	
}