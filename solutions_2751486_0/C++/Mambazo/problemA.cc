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
    string name;
    int n;
};

struct output
{
    int val;
};

istream& operator>>(istream& is, input& in)
{
    is >> in.name;
    is >> in.n;

    return is;
}

ostream& operator<<(ostream& os, const output& out)
{
    os << out.val;

    return os;
}

int isVowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int isValid(int n, const string& name)
{
    //cout << n << " " << name << " ";
    int start = 0;
    bool inZone = false;
    for (int i = 0; i < name.length(); ++i) {
	if (!inZone && !isVowel(name[i])) {
	    //cout << "+" << i;
	    inZone = true;
	    start = i;
	}
	else if (inZone && isVowel(name[i])) {
	    //cout << "." << i;
	    inZone = false;
	    if (i - start >= n) {
		//cout << "TRUE" << endl;
		return true;
	    }
	}
    }
    if (inZone) {
	//cout << "+" << name.length();
	if (name.length() - start >= n) {
	    //cout << "TRUE" << endl;
	    return true;
	}
    }

    //cout << "false" << endl;
    return false;
}

output solve(input in)
{
    output out;

    out.val = 0;
    for (int i = 0; i < in.name.length(); ++i) {
	for (int j = 1; j <= in.name.length() - i; ++j) {
	    if (isValid(in.n, in.name.substr(i, j)))
		out.val++;
	}
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
