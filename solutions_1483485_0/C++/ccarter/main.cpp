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
#include <strstream>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int main()
{

	//char t[50] = "ynficwlbkuomxsevzpdrjgthaq";
	//char t[50] = "abcdefghijklmnopqrstuvwxyz";
	char t[50] = "yhesocvxduiglbkrztnwjpfmaq";
	int n;
	char str[1000];
	scanf("%d%*c",&n);
	for (int i=1;i<=n;i++)
	{
		gets(str);
		for (int j=0;j<strlen(str);j++)
		{
			if (str[j]!=' ')
				str[j] = t[str[j]-'a'];
		}
		printf("Case #%d: %s\n",i,str);
	}

	return 0;
}

