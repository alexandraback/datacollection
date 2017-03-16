#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <iterator>

using namespace std;

int main(int argc, char *args[]) {
    freopen("./A-small-attempt1.in","rt",stdin);
    freopen("small.out","wt",stdout);

    int T;
	scanf("%d", &T);
	for (int caseNum = 1; caseNum <= T; ++caseNum) {
	    int smax;
	    char a[2000];
		scanf("%d %s", &smax, &a);

		int sumOfStandingPeople = 0;
		int requiredFriends = 0;
		for (int i = 0; i <= smax; i++){
			int value = a[i] - '0';
			if(value == 0) continue;
			if(sumOfStandingPeople + requiredFriends < i){
				requiredFriends += i - (sumOfStandingPeople + requiredFriends);				
			}
			sumOfStandingPeople += value;
		}
		printf("Case #%d: %d\n", caseNum, requiredFriends);
	}
}
