#include <iostream>
#include <sstream>
#include <set>
#include <cstdlib>
using namespace std;

int A, B;
int get(int x)
{
	ostringstream oss; oss << x;
	string s = oss.str();
	set<int> st; int k; char c;
	for (int i = 0; i < s.size(); ++i)
	{
		c = s[0];
		s = s.substr(1); s += c;
		k = atoi( s.c_str() );
		do
		{
			if (k > x and k >= A and k <= B) st.insert(k);
			k *= 10;
		} while (k <= B);
	}
	
	return st.size();
}

int main()
{
	int T; cin >> T;
	for (int t = 0; t < T; ++t)
	{
		cout << "Case #" << t+1 << ": ";
		cin >> A >> B;
		
		long long ret = 0, aa;
		for (int i = A; i <= B; ++i)
		{
			aa = get(i);
			ret += aa;
			//cout << i << ": " << aa << endl;
		}
		cout << ret << endl;
	}
}

