
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>
#include <map>
#include <list>
#include <cmath>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void main()
{
	int T;
	ifstream in;
	ofstream out;
	in.open("A-large.in", ios_base::in);
	out.open("A.txt", ios_base::app);
	in>>T;
	for(int t = 0; t < T; ++t)
	{
		int r, c, w;
		in>>r>>c>>w;
		int ans = c / w * r;
		ans += w - 1;
		if(c % w)
			++ans;
		out<<"Case #"<<t + 1<<": "<<ans<<endl;
	}
	system("pause");
}
