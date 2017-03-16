#include <iostream>
#include <cstdio>
#include <sstream>
#include <set>
#include <vector>
using namespace std;
const int MAX = 2000000;
typedef vector<int> VI;
VI mem[MAX + 1];
VI get_rotations(int n)
{
	if (!mem[n].empty())
		return mem[n];
	ostringstream os;
	os << n;
	string s = os.str();
	set<string> st;
	for (int j=1; j<=(int)s.size(); j++)
		st.insert(s.substr(j) + s.substr(0, j));
	for (set<string>::iterator it = st.begin(); it != st.end(); ++it)
	{
		int m;
		istringstream is(*it);
		is >> m;
		mem[n].push_back(m);
	}
	return mem[n];
}
int main()
{
	int t;
	cin >> t;
	for (int tc=0; tc<t; tc++)
	{
		int a, b, res = 0;
		cin >> a >> b;
		for (int i=a; i<=b; i++)
		{
			VI v = get_rotations(i);
			for (VI::iterator it = v.begin(); it != v.end(); ++it)
				if (*it > i && *it <= b)
					res++;
		}
		cout << "Case #" << tc + 1 << ": " << res << endl;
	}
	return 0;
}
