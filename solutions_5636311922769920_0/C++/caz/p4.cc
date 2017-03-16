#include <fstream>
#include <vector>

using namespace std;

int main()
{
	int t;
	ifstream ifs;
	ofstream ofs;
	ifs.open("in.txt");
	ofs.open("output.txt");
	ifs >> t;
	for (int i = 1; i <= t; i++)
	{
		int k, c, s;
		ifs >> k >> c >> s;
		ofs << "Case #" << i << ": ";
		for (int i = 1; i <= k; i++)
			ofs << i << " ";
		ofs << endl;
	}
	return 0;
}
