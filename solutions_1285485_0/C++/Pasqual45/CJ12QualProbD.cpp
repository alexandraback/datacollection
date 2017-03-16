#include <set>
#include <fstream>
#include <string>
using namespace std;
typedef pair<int, int> pii;

namespace {
	static int GCD(int a, int b) { return b==0 ? a : GCD(b,a%b); }
};

int main()
{
	ifstream fin("D-small-attempt0.in");
	ofstream fout("D-small-attempt0.out");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	int H,W,D;
	string s;

	for (unsigned int zz=1; zz<=numberOfCases; ++zz)
	{
		fin >> H >> W >> D;
		getline(fin, s);

		int h1=-1, w1=-1;
		for (int i=0; i<H; ++i)
		{
			getline(fin, s);
			int loc = s.find('X');
			if (loc != string::npos)
				h1 = i-1, w1 = loc - 1;
		}

		H-=2;
		W-=2;
		int maxSqrDist = D*D;
		
		set<pii> results;
		for (int i=-51; i<=51; ++i)
		{
			bool reflectH = (i%2)!=0;
			int h2 = (reflectH ? H-1-h1 : h1) + H * i;
			int dh = h2-h1;

			for (int j=-51; j<=51; ++j)
			{
				bool reflectW = (j%2)!=0;
				int w2 = (reflectW ? W-1-w1 : w1) + W * j;
				int dw = w2-w1;

				int sqrDist = dh*dh + dw*dw;
				if (sqrDist <= maxSqrDist && sqrDist > 0)
				{
					int z = GCD(abs(dh), abs(dw));
					results.insert(make_pair(dh/z, dw/z));
				}
			}
		}

		fout << "Case #" << zz << ": " << results.size() << endl;
	}

	return 0;
}