	#include <cstdio>
    #include <cstdlib>
    #include <iostream>
    #include <vector>
    #include <map>
    #include <set>
    #include <algorithm>
    #include <string>
    #include <cstring>
    #include <deque>
    #include <cmath>
    #include <ctime>
    

    using namespace std;

    typedef long long int i64;
    typedef vector<int> vi;
    typedef vector<vi > vvi;
    typedef pair<int, int> pii;

    const double eps = 10e-9;
    const int MOD = 1000000007;
    const int MOD2 = 1000000013;
    const int INF = MOD;


	
	int m[256], s[256];

	string ans(int x, int y)
	{
		string ans = "" ;

		for(int i = 0; i < abs(y); i++)
			ans += y > 0 ? "SN" : "NS";

		for(int i = 0; i < abs(x); i++)
			ans += x > 0 ? "WE" : "EW";
		 


		return ans;
	}

    int main()
    {
		freopen("input.in", "r", stdin);
		freopen("output.txt", "w", stdout);
        //std::ios_base::sync_with_stdio(false);
        int t = 0;
		cin >> t;
		for(int tcase = 1; tcase <= t; tcase++)
		{
			int x, y;
			cin >> x >> y;
			cout << "Case #" << tcase << ": " << ans(x, y) << endl;
		}




        //cerr << "Time -- " << clock() - t << endl;
        //system("PAUSE");
        return 0;
    }