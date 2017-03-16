#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++)
    {
		int r,c,w;
		cin >> r >> c >> w;
		cout << "Case #" << t << ": " << (int)ceil(1.0*c/w)+w-1 << "\n";
	}


    return 0;
}
