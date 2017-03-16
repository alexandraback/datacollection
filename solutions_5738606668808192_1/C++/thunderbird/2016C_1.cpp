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

vector<string> ans;
string base = "1001";
vector<string> temp;

void Generate(int l)
{
	temp.push_back(base);
	int s = 0;
	for (int i = 2; i <= l/4; i++)
	{
		int e = temp.size();
		for (int j = s; j < e; j++)
		{
			string z = "";
			while (1)
			{
				string tmp = temp[j] + z + base;
				if (tmp.length() <= l) 
					temp.push_back(tmp);
				else
					break;
				if (temp.size() >= 500) return;
				z = z + "0";
			}
		}
		s = e;
	}
}

int main()
{
	freopen("C-small-attempt0.in", "r", stdin); freopen("C-small-attempt0.out", "w", stdout);
	//freopen("B-large.in", "r", stdin); freopen("B-large.out", "w", stdout);
	//freopen("A.in","r",stdin);freopen("A.out","w",stdout);
	int testcase;
	string dis = "3 2 5 2 7 2 3 2 11";
	scanf("%d", &testcase);
	for (int case_id = 1; case_id <= testcase; case_id++)
	{

		int N, J;
		printf("Case #%d: ", case_id);
		printf("\n");
		Generate(24);
		
		
		for (int i = 0; i < temp.size(); i++){
			string z = "";
			if (ans.size() >= 500)
				break;
			while (1)
			{
				string tmp = z + temp[i];
				if (tmp.length() == 24)
					ans.push_back(base + tmp + base);
				else if (tmp.length() > 24)
					break;
				else
				{
					string y = "";
					for (int k = 0; k < 24 - tmp.length(); k++)
						y += "0";
					ans.push_back(base + tmp + y + base);
				}
				if (ans.size() >= 500)
					break;
				z += "0";
			}
		}

		for (vector<string>::iterator it = ans.begin(); it != ans.end(); ++it)
		{
			std::cout << *it << " ";
			std::cout << dis;
			std::cout << endl;
		}

	}
	return 0;
}

