
#include <iostream>
#include <istream>
#include <stdio.h>
#include <string>
#include <vector> 
#include <fstream>
#include <queue>
#include <algorithm>
#define INF 2147483647
#define BIG 1000000007

using namespace std; 

int main ()
{
    freopen ("A-small-attempt0 (5).in", "r", stdin);
	freopen ("A.out", "w", stdout); 
 	int tt; 
 	cin >> tt; 
 	for (int cases = 1; cases <= tt; cases++)
 	{
 		int n; 
		cin >> n; 
		string s;
		cin >> s;
		int count = s.at(0)-48, friends = 0;
		for (int x = 1; x <= n; x++)
		{
			if (count < x)
			{
				friends += x - count; 
				count = x;	
			}
			count += s.at(x)-48;
		}
		cout << "Case #" << cases << ": " << friends << "\n";	
	}
}
