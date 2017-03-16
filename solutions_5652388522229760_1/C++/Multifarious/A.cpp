
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
        long long Q;
        cin >> Q;
        if(Q == 0)
        {
            printf("Case #%d: INSOMNIA\n",tcase);
            continue;
        }
        int tseen = 0;
        int seen[10];
        memset(seen,0,sizeof(seen));

        long long tempq, cur = Q;
        int next;
        while(true)
        {
            tempq = cur;
            while(tempq > 0)
            {
                next = tempq % 10;
                if(seen[next] == 0)
                {
                    seen[next] = 1;
                    tseen++;
                }
                tempq = tempq / 10;
            }

            if(tseen >= 10)
            {
                break;
            }
            else
                cur += Q;
        }
        printf("Case #%d: %lld\n",tcase,cur);
	}
	return 0;
}