#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

template <typename T>
std::string toString(T t)
{
	std::ostringstream oss;
	oss << t;
	return oss.str();
}

template <typename T>
T fromString(std::string s)
{
	std::istringstream iss(s);
	T t;
	iss >> t;
	return t;
}

std::string do_operation(std::string s, int m)
{
	return s.substr(m) + s.substr(0, m);
}

int main() {
	int tn;
	cin >> tn;

	for (int ti = 0; ti < tn; ti++) {

		int a;
		int b;

		cin >> a >> b;

		std::set<std::pair<int, int> > s;

		for (int akt = a; akt <= b; ++akt)
		{
			string aktstr = toString(akt);
			for (int i = 1; i <= static_cast<int>(aktstr.size()) - 1; ++i)
			{
				string other = do_operation(aktstr, i);
				if ('0' == other[0]) continue;
				int othern = fromString<int>(other);
				if (othern == akt) continue;
				if (othern < akt) continue;
				if (a > othern) continue;
				if (b < othern) continue;
				//cerr << akt << " " << othern << endl;
				s.insert(make_pair(akt, othern));
			}
		}
		int result = s.size();

		cerr << "Sol: " << result << endl;
		std::cout << "Case #" << ti+1 << ": " << result << endl;
	}
}

