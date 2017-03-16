#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

using namespace std;

long long table[2600];
int main()
{
  	int T;
  	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cout << "Case #"<<t<<": ";
		int N;
  		cin >> N;
  		memset(table, 0, sizeof(table));
  		for(int i = 0; i < (2*N-1)*N; i++)
  		{
  			int temp;
  			cin >> temp;
  			table[temp]++;
  		}
  		for(int i = 0; i < 2600; i++)
  		{
  			if(table[i] % 2 == 1)
  				cout <<i << " ";
  		}
  		cout << endl;
  		
	}
  

  return 0;
}