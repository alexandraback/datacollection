#pragma comment (linker, "/STACK:64000000")
#include <memory.h>
#include <cstdio> 
#include <sstream> 
#include <iostream> 
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <cstring>
#include <list>
#include <cmath>

using namespace std;

typedef long long lint;
#define pb push_back
#define sz(a) (int)((a).size())


void prepare(string s){
//#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	return ;
//#else
	freopen((s + ".in").c_str(), "r", stdin); 
	freopen((s + ".out").c_str(), "w", stdout);
//#endif
}



struct Number
{
	int n;
	int a[10];
	int res;
	Number(int k){
		res = k;
		n = 0;
		while (k){
			a[n++] = k % 10;
			k /= 10;
		}
	}

	bool next(int &ans){
		for (int i = n; i > 0; -- i)
			a[i] = a[i - 1];
		a[0] = a[n];
		ans = 0;
		for (int i = n - 1; i >= 0; -- i)
		{
			ans *= 10;
			ans += a[i];
		}
		
		if (ans == res)
			return false;
		return true;
	}


};

bool solve(){
	
	int T;
	cin >> T;
	for (int test = 0; test < T; ++ test)
	{
		int a, b;
		cin >> a >> b;
		int ans = 0;
		for (int i = a; i <= b; ++ i)
		{
			Number n(i);
			int cur;
			while (n.next(cur))
			{
				if (cur >= a && cur <= b)
					++ ans;
			}
		}

		cout << "Case #" << test + 1 << ": " << ans / 2 << endl;
		cerr << test << endl;

	}
		
	
	return false;
}

int main(){

	prepare("problema");
	while (solve());



	return 0;
}