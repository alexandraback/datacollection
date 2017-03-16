#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>

using namespace std;

char gmap[27] = "yhesocvxduiglbkrztnwjpfmaq";

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);

	int caseId = 1;
	char s[256];
	int n;
	scanf("%d\n", &n);
	while (gets(s))
	{
		for (int i = 0; s[i] != '\0'; ++i)
			if (s[i] != ' ')
				s[i] = gmap[s[i] - 'a'];

		printf("Case #%d: ", caseId++);
		puts(s);
	}

	return 0;
}