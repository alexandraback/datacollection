#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
	int T, t, cnt, need, sum, i;
	string S;
	cin >> T;
        for (t = 0; t < T; t++)
        {
            cin >> cnt >> S;

			need = 0;
            sum = 0;
            for (i = 0; i < cnt+1; i++)
            {
                if (sum < i)
                {
                    if (need < i - sum) need = i - sum;
                }
                sum += S[i]-'0';
            }
            cout << "Case #"<< t+1 << ": " << need << endl;
        }

	return 0;
}