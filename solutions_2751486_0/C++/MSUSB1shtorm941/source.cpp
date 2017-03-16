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


	
	int m[256];

	i64 calcAns(string name, int low)
	{
		vi s(name.size());
		vi b(name.size());


		i64 ans = 0;
		int count = 0;
		for(int i = 0; i < name.size(); i++)
			s[i] = m[ name[i] ];
		
		for(int i = 1; i < name.size(); i++)
			if(s[i] > 0)
				s[i] += s[i - 1];

		for(int i = name.size() - 1; i >= 0; i--)
			if(s[i] >= low)
				b[i] = i;
			else
				b[i] = i < name.size() - 1 ? b[i + 1] : name.size();

		for(int i = 0; i < name.size() - low + 1; i++)
			ans += name.size() - b[i + low - 1];
		


		
		return ans;
	}


    int main()
    {
		freopen("input.in", "r", stdin);
		freopen("output.txt", "w", stdout);
        //std::ios_base::sync_with_stdio(false);
        int t;
		for(int i = 0; i < 256; i++)
			m[i] = 1;
		m['a'] = 0;
		m['e'] = 0;
		m['i'] = 0;
		m['o'] = 0;
		m['u'] = 0;

		cin >> t;
		for(int tcase = 1; tcase <= t; tcase++)
		{
			string name;
			int l;
			cin >> name >> l;
			
			cout << "Case #" << tcase << ": " << calcAns(name, l) << endl;

		}



        //cerr << "Time -- " << clock() - t << endl;
        //system("PAUSE");
        return 0;
    }