#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main()
{
        int t;
        cin >> t;
        for (int j=1;j<=t;j++)
        {
        	int r,c,w;
        	cin >> r >> c >> w;
        	int ans = ((c/w)*r) + w;
        	if (c%w==0) ans--;

            cout << "Case #" << j;
            printf(": %d\n",ans);
        }

        return 0;
}