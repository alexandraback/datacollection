

#include "vector"
#include "string"
#include "set"
#include "map"
#include "sstream"
#include "algorithm"
#include "cmath"
#include "cassert"
#include "iostream"
#include "numeric"
#include "fstream"
#include "queue"
#include <functional>
#include  <climits>

#ifdef __GNUC__
#include  <tr1/unordered_map>
#define unordered_map tr1::unordered_map
#else
#include <unordered_map>
#endif

using namespace std;

#define int64 long long
#define F(vec, index) for (int index = 0; index  < vec.size(); ++index)
#define F2(index, vec) for (int index = 0; index  < vec.size(); ++index)
#define F3(index, from, vec) for (int index = from + 1; index  < vec.size(); ++index)




int main(int argc, char* argv[])
{
	int T;
	fstream cin("input.txt");
	fstream cout("result.txt",fstream::out);
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int n;
		cin >> n;
		vector<int> data(n);
		F2(i, data) cin >> data[i];

		int res = 1000;
		
		for (int p = 1; p <= 1000; ++p)
		{
			int currRes = p;
			F2(i, data)
			{
				if (data[i] > p)
				{
					int k = ceil((data[i] - p) / double(p));
					currRes += k;
				}	
			}
			res = min(res, currRes);
		}
		cout << "Case #" << t << ": " << res << endl;

	}

	return 0;
}
