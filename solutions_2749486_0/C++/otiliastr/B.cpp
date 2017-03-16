#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;

int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B1.out","w",stdout);
	int T,x,y;
	cin>>T;
	for (int t = 1; t<=T; ++t)
	{
		cin>>x>>y;
		cout << "Case #" << t << ": ";
    
        string ch;
        if (y > 0)
            ch = "SN";
        else
            ch = "NS";
        for (int i = 0; i < abs(y); ++i)
            cout << ch;

        if (x > 0)
            ch = "WE";
        else
            ch = "EW";
        for (int i = 0; i < abs(x); ++i)
            cout << ch;

        cout << "\n";
	}
	return 0;
}
