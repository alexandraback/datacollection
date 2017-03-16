#include <bits/stdc++.h>
using namespace std;
#define int long long

int r, c, w;

int lg2(int x)	{
	if(x <= 1)	{
		return x;
	}
	return lg2(x / 2);
}

void pain()	{
	cin >> r >> c >> w;
	if(w == 1)	{
		cout << r * c << "\n";
		return;
	}
	cout << (r - 1) * (c / w) + (c / w) +  w - (c % w == 0) << "\n";
}

#undef int
int main()	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string input = "a2i.txt";
	string output = "a2o.txt";
	freopen(input.c_str(), "r", stdin);
	freopen(output.c_str(), "w", stdout);
	int tt; cin >> tt;
	for(int iii=1; iii<=tt; iii++)	{
		cout << "Case #" << iii << ": ";
		pain();
	}
}

