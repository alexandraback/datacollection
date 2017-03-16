//------------------------------------------------------------------------------
//  Problem : 
//  User    : 
//  Date    : 
//------------------------------------------------------------------------------


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

char A[1111];


void work(int testcase) {
	scanf("%s", A);
	int len = strlen(A);
	string s = "";
	s = s + A[0];
	for (int i = 1; i < len; ++i) {
		if (A[i] >= s[0]) s = A[i] + s;
		else s = s + A[i];
	}
	printf("Case #%d: ", testcase);
	cout << s << endl;
}

int main( int argc , char *argv[] )
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int TC;
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc) {
		work(tc);
	}
	return 0;
}
