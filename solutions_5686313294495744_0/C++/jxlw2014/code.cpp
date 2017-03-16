#include <iostream>
#include <stdio.h>
#include <numeric>
#include <queue>
#include <string>
#include <cmath>
#include <vector>
#include <deque>
#include <iomanip>
#include <set>
#include <queue>
#include <bitset>
#include <iomanip>
#include <map>
#include <string.h>
#include <stack>
#include <algorithm>

#include <unordered_map>
#include <unordered_set>

using namespace std;

string input1[1010];
string input2[1010];

int main()
{
//	freopen("E:\\things for work\\google\\C-small-attempt1.in" , "r" , stdin);
//	freopen("E:\\things for work\\google\\out.txt" , "w" , stdout);

	int i , j , t , case_num = 1 , length , n;
	scanf("%d" , &t);
	while (t --)
	{
		unordered_set<string> s1 , s2;
		scanf("%d" , &n);
		for (i = 0;i < n;i ++)
		{
			cin >> input1[i] >> input2[i];
			s1.insert(input1[i]);
			s2.insert(input2[i]);	
		}
		int ans = n - max(s1.size() , s2.size());
		printf("Case #%d: %d\n" , case_num , ans);
		case_num ++;
	}	
	return 0;
}