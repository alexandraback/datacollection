#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

int calc()
{
    int N;
    cin >> N;

    /*
    map<string, int> m;
    string s;
    for (int i = 0; i < N; ++i) {
        cin >> s;
        m[s]++;
    }
    */
    vector<string> vs;
    vector<int> idx;
    string s;
    map<char, int> chnum;
    for (int i = 0; i < N; ++i) {
        cin >> s;
        vs.push_back(s);
        idx.push_back(i);

        for (int j = 0; j < s.length(); ++j) {
            chnum[s[j]] = 1;
        }
    }

    int ans = 0;
    do {
        string s = "";
        for (int i = 0; i < idx.size(); ++i) {
            s += vs[idx[i]];
        }
        int n = unique(s.begin(), s.end()) - s.begin();
        if (n == chnum.size()) {
            ++ans;
        }
    } while (next_permutation(idx.begin(), idx.end()));

    return ans;
}

int main(void)
{
	int T;
	cin >> T;
	//getline(cin, line);
	for (int ca=1; ca<=T; ++ca) {
		//getline(cin, line);
		cout << "Case #" << ca << ": " << calc() << endl;
	}
	return 0;
}
