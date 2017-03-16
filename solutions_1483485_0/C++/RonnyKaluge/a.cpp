#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

#define A first
#define B second

int main()
{
	int i, T;
	char s[1000];
	char tr[] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
	cin >> T;
	cin.getline(s, 1000);
	for (int t=1; t<=T; ++t)
	{
		cin.getline(s, 1000);
		for (i=strlen(s); i--; )
		{
			if (s[i] <= 'z' && s[i] >= 'a')
				s[i] = tr[s[i]-'a'];
		}
		cout << "Case #" << t << ": " << s << endl;
	}
	return 0;
}
