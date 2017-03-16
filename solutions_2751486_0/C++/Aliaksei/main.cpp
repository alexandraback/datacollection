#include <iostream>
#include <string>
#include <cstdlib>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <fstream>
#include <queue>
using namespace std;

double f(int n, int x, int y)
{
    int k = 1;
    for (; k * (k + 1) <= 2*n; k += 2);
    if (x+y > k || -x+y > k || y > k-2)
        return 0.0;
    k -= 2;
    if (x+y < k && -x+y < k)
        return 1.0;
    double res = 0;
    double c = 1.0;
    n -= k*(k+1)/2;
    if (y < n-k-1)
        return 1.0;

    for (int i=n; i > y; i--)
    {
        res += c;
        c *= i;
        c /= n-i+1;
        res *= 0.5;
        c *= 0.5;
    }
    for (int i = y; i > 0; i--)
        res *= 0.5;
    return res;
}



int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	f(11, 4, 0);
	int st;
	cin >> st;	
	for(int steps = 0; steps< st; steps++)
	{
		string s; int k;
		cin >> s >> k;
		vector<int> v(s.size()+1, 0);
		int n = s.size();
		int ans = 0;
		for(int i = 0; i < n; ++i)
			for(int j = i; j < n; ++j){
				int temp = 0, maxtemp = 0;
				for(int l = i; l <= j; ++l)
					if(s[l]!='a' && s[l]!= 'e' && s[l] != 'i' && s[l]!= 'o' &&s[l]!= 'u')
					{
						temp +=1;
						maxtemp = max(temp, maxtemp);
					}
					else
						temp = 0;
				if(maxtemp>=k)
					++ans;
			}

			printf("Case #%d: %d\n", steps+1, ans);		
	}

}