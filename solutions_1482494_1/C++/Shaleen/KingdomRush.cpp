#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <string.h>
using namespace std;

typedef vector<int> vi;
typedef vector< vector<int> > vvi; 
typedef vector<string> vs;

#define PB push_back
const long double PI = 3.1415926535897932384626433832795;
bool operator<(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.first < b.first;
}
int main(int argc, char *argv[])
{
	int num_tc, N;
	ifstream myfile;
	myfile.open(argv[1]);
	myfile >> num_tc;
	
	for (int i=0; i<num_tc; ++i) {
		myfile >> N;
		vi A, B;
		int a, b;
		bool played[N];
		for (int l = 0; l < N; ++l) played[l] = false;
		vector <pair<int, int> > Bmore;
		for (int j=0; j<N; ++j) {
			myfile >> a >> b;
			A.PB(a); B.PB(b);
			Bmore.PB(make_pair(b, j));
		}
		sort(Bmore.begin(), Bmore.end());
		int res = 0, stars = 0;
		while(Bmore.size()) {
			while (Bmore.size() && Bmore[0].first <= stars) {
				if (played[Bmore[0].second]) ++stars;
				else stars += 2;
				++res;
				played[Bmore[0].second] = true;
				Bmore.erase(Bmore.begin());
			}
			if (Bmore.size()) {
				int play = -1, diff = 0;
				for (int l = 0; l < A.size(); ++l) {
					if (!played[l] && A[l] <= stars) {
						if (B[l] - A[l] > diff) {
							diff = B[l] - A[l];
							play = l;
						}
					}
				}
				if (play == -1) {
					cout << "Case #" << i + 1 << ": " << "Too Bad" << "\n";
					goto done;
				}
				++res;
				played[play] = true;
				++stars;
			}
		}
		cout << "Case #" << i + 1 << ": " << res << "\n";
done: {}
	}
	myfile.close();
	return 0;
}
