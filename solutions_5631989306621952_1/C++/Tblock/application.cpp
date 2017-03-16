#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<ll> vll;

int main()
{	
	int t;
	cin >> t;
	int cas = 1;

	while (t--) {
		cout << "Case #" << cas << ": ";
		cas++;

		string s;
		cin >> s;

		string recon = "";

		char first = s[0];
		char last = *(max_element(s.begin(), s.end()));
		
		vb tbe;
		tbe.push_back(false);
		bool seenlast = false;
		char max = s[0];
		for (int i = 1; i < s.size(); i++) {
			if (s[i] == last) {
				seenlast = true;
				recon += s[i];
				tbe.push_back(true);
			}
			else if (s[i] >= max && !seenlast) {
				max = s[i];
				recon += s[i];
				tbe.push_back(true);
			}
			else {
				tbe.push_back(false);
			}
		}

		reverse(recon.begin(), recon.end());

		recon += s[0];
		for (int i = 1; i < s.size(); i++) {
			if (!tbe[i])
				recon += s[i];
		}

		cout << recon << endl;
	}
    return 0;
}
