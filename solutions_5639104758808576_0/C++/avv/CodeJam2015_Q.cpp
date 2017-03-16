

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



class
{
public:

};


int main(int argc, char* argv[])
{
	int T;
	fstream cin("input.txt");
	fstream cout("result.txt",fstream::out);
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		int s;
		cin  >> s;
		vector<int> data;
		string str;
		cin >> str;
		F2(i, str)
		{
			data.push_back(str[i] - '0');
		}
		
		int res = 0;
		int av = 0;
		F2(i, data)
		{
			if (i > av)
			{
				int add = i - av;
				res += add;
				av += add + data[i];
			}
			else
			{
				av += data[i];
			}
		}
		cout << "Case #" << t + 1 << ": " << res << endl; 
	}



	return 0;
}
