#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
using namespace std;

double v[205] ;
int s[205], sum , n;

int judge(double pi, int number)
{
	double pt = s[number] + pi * sum  , TTT = 1 - pi, V;

	for (int i = 0 ; i < n ; i++)
	{
		if (number == i || s[i]*1.0 > pt) continue ;
		V = (pt-s[i]) * 1.0 / sum ;
		TTT = TTT - V ;
		if (TTT < 0)
            return 0 ;
	}
	return 1 ;
}

int main ()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
	int T, i, tt=0;
	cin >> T;
	while(T--)
	{
	    cin >> n ;
	    sum = 0 ;
		for (i = 0 ; i < n ; i++)
		{
			scanf ("%d", &s[i]) ;
			sum += s[i] ;
		}
        cout << "Case #"<<++tt<<":" ;
		for (i = 0 ; i < n ; i++)
		{
            double left = 0, right = 1, mid ;
            while (right-left > 1e-9)
            {
                mid =(left +right)/2.0;
                if (judge(mid, i)) left = mid ;
                else right = mid ;
            }
			v[i] = mid ;
		}
		for (i = 0 ; i < n ; i++)
            printf(" %lf",v[i]*100);

        cout << endl;
	}
	return 0 ;
}
