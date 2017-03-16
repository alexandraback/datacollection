#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <ctime>

using namespace std;

bool vowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;	
	return false;
}

int main () {
        int T;  
        cin >> T;
	//cout << "T = " << T << endl;
        string line;
        getline(cin,line);
        for (int i = 0; i < T; ++i) {
		int X, Y;
		cin >> X >> Y;
		//cout << "X = " << X << ", Y = " << Y << endl;
		getline(cin,line);
                cout << "Case #" << i+1 << ": ";
		if (X > 0) while (X > 0) { cout << "WE"; X--; }
		if (X < 0) while (X < 0) { cout << "EW"; X++; }
		if (Y > 0) while (Y > 0) { cout << "SN"; Y--; }
		if (Y < 0) while (Y < 0) { cout << "NS"; Y++; }
		cout << endl;
        }   
}
