
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
       long long K,C, S;
       cin >> K >> C >> S;
       long long min_needed = K / C;
       if( K % C > 0)
       {
            min_needed++;
       }
       if(min_needed > S)
       {
            printf("Case #%d: IMPOSSIBLE\n", tcase);
       }

       long long bases[C+1];
       bases[0] = 1;
       for(int idx = 1; idx <= C; idx++)
       {
            bases[idx] = bases[idx-1] * K;
       }

       long long start = 0;
       vector<long long> check;
       while(start < K)
       {
            long long next = 1;
            for(int base_idx = C-1; base_idx >= 0; base_idx--)
            {
                if(start < K)
                {
                    next += bases[base_idx] * start;
                    start++;
                }
                else
                {
                    next += bases[base_idx] * 0;
                }
                
            }

            check.push_back(next);
        }
        printf("Case #%d:", tcase);
        for(int i = 0; i < check.size(); i++)
        {
            printf(" %lld",check[i]);
        }
        printf("\n");
	}
	return 0;
}