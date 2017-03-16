#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <utility>
#include <cmath>
#include <string>
#include <map>

using namespace std;

template <typename T>
string v2s(const vector<T>& v)
{
    ostringstream ss;
    for (int i = 0; i < v.size(); ++i) {
        if (i > 0)
            ss < " ";
        ss << v[i];
    }
    return ss.str();
}

template <typename T>
vector<T> s2v(const string& s)
{
    istringstream ss(s);
    vector<T> v;
    T t;
    while (cin >> t)
	v.push_back(t);
    return v;
}

struct input
{
    int N;
    vector<int> d;
    vector<int> n;
    vector<int> w;
    vector<int> e;
    vector<int> s;
    vector<int> dd;
    vector<int> dp;
    vector<int> ds;
};

struct output
{
    int attacks;
};

istream& operator>>(istream& is, input& in)
{
    is >> in.N;
    in.d = vector<int>(in.N);
    in.n = vector<int>(in.N);
    in.w = vector<int>(in.N);
    in.e = vector<int>(in.N);
    in.s = vector<int>(in.N);
    in.dd = vector<int>(in.N);
    in.dp = vector<int>(in.N);
    in.ds = vector<int>(in.N);
    for (int i = 0; i < in.N; ++i) {
	is >> in.d[i] >> in.n[i] >> in.w[i] >> in.e[i] >> in.s[i] >> in.dd[i] >> in.dp[i] >> in.ds[i];
    }

    return is;
}

ostream& operator<<(ostream& os, const output& out)
{
    os << out.attacks;

    return os;
}

output solve(input in)
{
    output out;
    out.attacks = 0;

    vector<int> wall(2000, 0);

    for (int d = 0; d <= 676060; ++d) {
	//cout << d;
	int w = 1000;
	int e = -1000;
	int s = 0;
	bool anyAttacks = false;
	bool allDone = true;
	vector<int> wall2 = wall;
	for (int i = 0; i < in.N; ++i) {
	    if (in.n[i] == 0)
		continue;
	    else
		allDone = false;

	    if (in.d[i] != d)
		continue;
	    else
		anyAttacks = true;

	    //cout << "." << in.w[i] << "|" << in.e[i] << "|" << in.s[i] << "|";
	    //for (int j = in.w[i]; j < in.e[i]; ++j)
	    //	  cout << wall[j + 1000] << "_";
	    for (int j = in.w[i]; j < in.e[i]; ++j) {
		if (in.s[i] > wall[j + 1000]) {
		    //cout << "*" << in.w[i];
		    out.attacks++;
		    break;
		}
	    }

	    //cout << "#" << in.w[i] << "|" << in.e[i] << "|" << in.s[i];
	    for (int j = in.w[i]; j < in.e[i]; ++j) {
		wall2[j + 1000] = max(wall2[j + 1000], in.s[i]);
	    }
    
	    in.d[i] += in.dd[i];
	    in.n[i]--;
	    in.w[i] += in.dp[i];
	    in.e[i] += in.dp[i];
	    in.s[i] += in.ds[i];
	}
	//cout << endl;
	if (anyAttacks)
	    wall = wall2;
	if (allDone)
	    break;
    }

    return out;
}

int main(int argc, char* argv[])
{
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
	input in;
	cin >> in;
	
	output out = solve(in);

        cout << "Case #" << t + 1 << ": " << out << endl;
    }

    return 0;
}
