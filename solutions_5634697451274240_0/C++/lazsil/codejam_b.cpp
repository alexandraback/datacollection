#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main()
{
	int num_of_testcases;
	cin >> num_of_testcases;
	for (int t = 1; t <= num_of_testcases; ++t){
		string s;
		cin >> s;

		int cnt = 0;

		bool reverse = false;
		for (int i = s.length() - 1; i >= 0; --i) {
			if ((reverse == false && s[i] == '-') || (reverse == true && s[i] == '+'))
			{
				cnt++;
				reverse = !reverse;
			}
		}


		cout << "Case #" << t << ": " << cnt <<  "\n";
	}

    return 0;
}

