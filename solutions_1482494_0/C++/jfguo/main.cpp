#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <map>
using namespace std;

typedef long long LL;
typedef unsigned int UINT32;

int a[2000];
int b[2000];
int N;

string calc()
{
	cin >> N;
	vector<pair<int,int> > seconds;
	for (int i=0; i<N; ++i) {
		cin >> a[i] >> b[i];
		seconds.push_back(make_pair(b[i],i));
	}

	int i, j;
	sort(seconds.begin(), seconds.end());

	int ans = N + 1;

	vector<int> first;
	for (int m = 0; m <= (1<<N)-1; ++m) {
		int t = 0;
		first.clear();
		for (i = 0; i < N; ++i) if ((m>>i)&1) {
			first.push_back(a[i]);
			t++;
		}
		sort(first.begin(), first.end());
		bool ok = true;
		for (i = 0; i < first.size(); ++i) {
			if (first[i] > i) {
				ok = false;
				break;
			}
		}
		if (!ok) continue;
	
		int cur = first.size();
		for (i = 0; i < seconds.size(); ++i) {
			if (seconds[i].first > cur) {
				ok = false;
				break;
			}
			if ((m>>seconds[i].second)&1) {
				cur++;
			} else {
				cur += 2;
			}
		}
		if (!ok) continue;
	
		if (t < ans) ans = t;
	}

	stringstream S;
	if (ans == N+1) {
		S << "Too Bad";
	} else {
		S << ans + N;
	}
	return S.str();

}

int main(void)
{
	int N;
	cin >> N;

    // NOTE: if using getline() to read the input, the following two lines should be
    // added to read the line sepeartor in the first line. 
    //string line;
    //getline(cin, line);
	for (int i=1; i<=N; ++i) {
		cout << "Case #" << i << ": " << calc() << endl;
	}

	return 0;
}
