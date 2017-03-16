#include <fstream>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	ifstream in("in.txt");
	ofstream out("out.txt");

	int T = 0;
	in >> T;
	for (int i = 1; i <= T; ++i)
	{
		int N = 0;
		in >> N;
		unordered_map<int, int> mymap;
		int h = 0;
		for (int j = 0; j < 2*N-1; ++j)
		{
			for (int k = 0; k < N; ++k)
			{
				in >> h;
				if (mymap.find(h) != mymap.end())
				{
					mymap[h]++;
				}
				else mymap.insert(pair<int, int>(h, 1));
			}
		}
		vector<int> result;
		for (auto i = mymap.begin(); i != mymap.end(); ++i)
		{
			// cout<<i->first<<" "<<i->second<<endl;
			if (i->second % 2 != 0)
			{
				result.push_back(i->first);
			}
		}
		// cout<<result.size()<<endl;
		sort(result.begin(), result.end());
		out<<"Case #"<<i<<":";
		for (int j = 0; j < N; ++j)
		{
			out<<" "<<result[j];
		}
		out<<endl;

	}
}