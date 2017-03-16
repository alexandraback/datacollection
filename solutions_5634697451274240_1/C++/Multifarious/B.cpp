
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <stack>
#include <cmath>
#include <string.h>
#include <queue>
#include <set>
using namespace std;
 
typedef vector < string > vs;
typedef vector <int> vi;
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define deb(x) cout << #x << ": " << x << endl;
#define debv(x) for(int i = 0; i < (x).size(); i++) cout << x[i] << ' '; cout << endl;



int main()
{
    int T;
	cin >> T;

	for(int tcase = 1; tcase <= T; tcase++)
	{
        string cakes = "";
        cin >> cakes;
        int N = cakes.size();
        int cnt = 0;

        char last = '+';
        for(int idx = N-1; idx >= 0; idx--)
        {
            if(cakes[idx] != last)
            {
                cnt++;
                last = cakes[idx];
            }
        }
        printf("Case #%d: %d\n",tcase,cnt);
	}
	return 0;
}