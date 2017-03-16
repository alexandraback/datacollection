#include <iostream>
#include <sstream>
#include <numeric>
#include <set>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <strings.h>
#include <limits.h>
#include <stdlib.h>
#include <float.h>
#include <strings.h>
#include <string.h>
using namespace std;

int main(){
	int tests;
	cin >> tests;
	for (int t = 0; t < tests; t++){
		cout << "Case #" << (t+1) << ": ";
		string s;
		cin >> s;
		string result;
		result.append(1, s[0]);
		for (int i = 1; i < s.size(); i++){
			if (s[i] >= result[0]){
				result = s[i] + result;
			} else {
				result = result + s[i];
			}
		}
		cout << result << endl;
	}
}
