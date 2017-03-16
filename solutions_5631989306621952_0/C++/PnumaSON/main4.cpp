#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include <string.h>
#include <bitset>
#include <functional>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <iomanip>
#define mp(a, b) make_pair(a, b)
typedef long long ll;
using namespace std;



int main(){

	char strc[50];
	string ret;
	int lim;
	cin >> lim;
	for (int i = 0; i < lim; i++){
		cin >> strc;
		ret = strc[0];
		for (int j = 1; j < strlen(strc); j++){
			if (ret[0] <= strc[j]){
				ret = strc[j] + ret;
			}
			else{
				ret = ret + strc[j];
			}

		}
		cout << "Case #" << i + 1 << ": " << ret << endl;
	}
	




	return 0;
}