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

bool allQ(string& a ,string& b)
{
	int n = a.size();

	for (int i = 0 ; i < n; ++i)
	{
		if ( a[i] != '?' || b[i] != '?')
			return false;
	}

	for (int i = 0 ; i < n; ++i)
		cout << 0;
	cout << " ";
	for (int i = 0 ; i < n; ++i)
		cout << 0;
	puts("");

	return true;
}

bool canSame(string& a ,string& b)
{
	int n = a.size();

	for (int i = 0 ; i < n; ++i)
	{
		if (a[i] == '?' || b[i] == '?')
			continue;
		if (a[i] ==  b[i])
			continue;

		return false;
	}
	string oo;
	
	for (int i = 0 ; i < n; ++i)
	{
		if (a[i] == '?' && b[i] != '?')
			oo.push_back(b[i]); 
		else if (a[i] != '?' && b[i] == '?')
			oo.push_back(a[i]); 
		else if (a[i] == '?' && b[i] == '?')
			oo.push_back('0'); 
		else 
			oo.push_back(a[i]);
	}
	cout << oo << " " << oo << endl;

	return true;
}


int main(int __an, char **__ag)
{	
	int Case, cases = 0;
	scanf("%d" , &Case);
	while (Case--)	
	{
		string a , b;
		cin >> a >> b;

		printf("Case #%d: " , ++cases);

		if (allQ(a,b))
		{
			continue;
		}
		if ( canSame(a,b))
			continue;

		int n = a.size();
		string aa , bb;
		long long curA = 0 , curB = 0;
		for (int i = 0; i < n; ++i)
		{
			if ( a[i] == '?' ||  b[i] == '?')
			{
				long long diff = LLONG_MAX;
				int cc , jj;
				for (int c = 0; c < 10; ++c)
				{
					if ( a[i] != '?' && c != a[i]-48)
						continue;

					for (int j = 0; j < 10; ++j)					
					{
						if ( b[i] != '?' && j != b[i]-48) continue;
						long long diffA;
						if ( i+1 < n)
						{
							int A = c*10 + (a[i+1] == '?' ? 0 : a[i+1]-48);
							int B = j*10 + (b[i+1] == '?' ? 0 : b[i+1]-48);
							diffA = abs(A-B);
						}
						else if ( i-1 >= 0)
						{
							long long A = (long long)c + curA*10LL;
							long long B = (long long)j + curB*10LL;
							diffA = abs(A-B);
						}
						else
						{
							int A = c;
							int B = j;
							diffA = abs(A-B);
						}
						if ( diffA < diff)
						{
							diff = diffA;
							cc = c;
							jj = j;
						}
					}
				}
				aa.push_back(cc+48);
				bb.push_back(jj+48);

				curA*=10;
				curB*=10;
				curA += (long long)(cc);
				curB += (long long)(jj);
			}
			else
			{
				aa.push_back( a[i]);
				bb.push_back( b[i]);

				curA*=10;
				curB*=10;
				curA += (long long)(a[i]-48);
				curB += (long long)(b[i]-48);
			}
		}

		cout << aa << " " << bb << endl;
	}

	return 0;
}

