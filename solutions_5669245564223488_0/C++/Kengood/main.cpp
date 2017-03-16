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
#include <string>
#include <complex>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <ctime>

#include<unordered_map>
#include<unordered_set>
using namespace std;

int cases , Case = 1;
////////////

char v[10];
int brute(vector<string>& in, int n, int cur, int prev = -1 , string aa ="" )
{
	if( cur == n )
	{
		char as[26]={0};
		for(int i = 0 ; i < aa.size(); ++i)
		{
			if( as[ aa[i]-'a'] )
			{
				if( i && aa[i] != aa[i-1] )
					return 0;
			}
			else
			{
				as[ aa[i]-'a'] = 1;
			}
			
		}
		
		return 1;
	}

	int ans = 0;
	for(int i = 0 ; i < n; ++i)
	{
		if( !v[i] )
		{
			string ab = aa ;
			ab += in[i];
			 v[i] = 1;
			ans +=  brute(in,n,cur+1, -1 , ab );
			 v[i] = 0;
		}
	}

	//int ans = 0;
	//for(int i = 0 ; i < n; ++i)
	//{
	//	if( !v[i] )
	//	{

	//		if(  prev != -1)
	//		{
	//			if( in[prev].back() != in[i].front()  )
	//			{
	//				if( in[prev].size() >= 2 &&
	//					in[prev][in[prev].size()-2] == in[prev][in[prev].size()-1] )
	//				{
	//				}
	//				else
	//				{
	//					continue;
	//				}
	//			}
	//		}

	//		int c = i;
	//		if( prev != -1 &&  in[i].size() == 1 && ( in[prev].back() == in[i].front()  ) )
	//			c = -1;
	//		/*string ab = aa + " ";
	//		ab += in[i];*/
	//		 v[i] = 1;
	//		ans +=  brute(in,n,cur+1, c/* , ab*/ );
	//		 v[i] = 0;
	//	}
	//}

	return ans;
}

int main()
{	

	scanf("%d" , &cases);	
	while( cases-- )
	{			
		printf("Case #%d: " , Case++ );
		
		int n;
		cin >> n;

		vector<string> in(n);
		for(int i = 0 ; i < n; ++i)
		{
			cin >> in[i];
			 v[i] = 0;
		}

		cout << brute(in,n,0) << endl;
	}

	

	return 0;
}

