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
		string str;
		cin >> str;
		str.append(1, '+');
		int moves = 0;
		for (int i = 1; i < str.size(); i++){
			if (str[i] != str[i-1]){
				moves++;
			}
		}
		cout << moves << endl;
	}
}
