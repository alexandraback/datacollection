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

int bitnum(int m)
{
    int ans = 0;
    while (m) {
        m &= m - 1;
        ++ans;
    }
    return ans;
}

string calc()
{
    int N;
    cin >> N;
    vector<int> f1(N, -1);
    for (int i = 0; i < N; ++i) {
        cin >> f1[i];
        f1[i]--;
    }

    vector<int> stus;
    int ans = 2;
    for (int m = 0; m < (1<<N); ++m) {
        int bn = bitnum(m);
        if (bn <= ans) continue;

        stus.clear();
        for (int j = 0; j < N; ++j) {
            if ((m >> j) & 1) {
                stus.push_back(j);
            }
        }
        bool found = false;
        do {
            /*
            int fail = 0;
            for (int i = 0; i < stus.size() - 1; ++i) {
                if (f1[stus[i]] != stus[i+1] && f1[stus[i+1]] != stus[i]) {
                    fail++;
                }
            }
            if (f1[stus[0]] != stus[stus.size() - 1] && f1[stus[stus.size()-1]] != stus[0]) {
                fail++;
            }
            if (fail <= 1) {
                found = true;
                break;
            }
            */

            bool succ = true;
            for (int i = 0; i < stus.size(); ++i) {
                int p = (i - 1 + stus.size()) % stus.size();
                int n = (i + 1) % stus.size();
                if (f1[stus[i]] != stus[p] && f1[stus[i]] != stus[n]) {
                    succ = false;
                    break;
                }
            }
            if (succ) {
                found = true;
                break;
            }
        } while(next_permutation(stus.begin() + 1, stus.end()));

        if (found) {
            ans = bn;
        }
    }
    
    stringstream ss;
    ss << ans;
    return ss.str();
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
