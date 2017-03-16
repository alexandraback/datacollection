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
string v2s(const vector<T>& v, const string& sep = " ")
{
    ostringstream ss;
    for (int i = 0; i < v.size(); ++i) {
        if (i > 0)
            ss << sep;
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
    int X;
    int Y;
};

struct output
{
    vector<char> moves; 
};

istream& operator>>(istream& is, input& in)
{
    is >> in.X;
    is >> in.Y;

    return is;
}

ostream& operator<<(ostream& os, const output& out)
{
    os << v2s(out.moves, "");

    return os;
}

output solve(input in)
{
    output out;

    char FX = 'E';
    char BX = 'W';
    if (in.X < 0) {
	FX = 'W';
	BX = 'E';
	in.X = -in.X;
    }

    char FY = 'N';
    char BY = 'S';
    if (in.Y < 0) {
	FY = 'S';
	BY = 'N';
	in.Y = -in.Y;
    }

    int x = 0;
    int y = 0;
    int step = 1;
    while (x < in.X || y < in.Y) {
	if (x < in.X) {
	   x += step;
	   step++;
	   out.moves.push_back(FX);
	}
	if (y < in.Y) {
	   y += step;
	   step++;
	   out.moves.push_back(FY);
	}
    }
    if (x > in.X) {
	for (int i = 0; i < x - in.X; ++i) {
	    out.moves.push_back(FX);
	    out.moves.push_back(BX);
	}
    }
    if (y > in.Y) {
	for (int i = 0; i < y - in.Y; ++i) {
	    out.moves.push_back(FY);
	    out.moves.push_back(BY);
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
