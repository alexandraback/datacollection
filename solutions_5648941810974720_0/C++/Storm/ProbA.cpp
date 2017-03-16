#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>

using namespace std;

int main()
{
	freopen("C:\\Projects\\gcj\\input.txt", "r", stdin);
	freopen("C:\\Projects\\gcj\\output.txt", "w", stdout);

	int z;
	cin >> z;
	for (int q1=0;q1<z;q1++) {
		string str;
		cin >> str;
		vector<int> count(26,0);
		for (int i=0;i<str.size();i++) {
			count[str[i] - 'A']++;
		}

		vector<int> result(10, 0);
		int t = count['Z'-'A'];
		result[0] = t;
		count['Z'-'A'] -= t;
		count['E'-'A'] -= t;
		count['R'-'A'] -= t;
		count['O'-'A'] -= t;

		t = count['U'-'A'];
		result[4] = t;
		count['F'-'A'] -= t;
		count['O'-'A'] -= t;
		count['U'-'A'] -= t;
		count['R'-'A'] -= t;

		t = count['W'-'A'];
		result[2] = t;
		count['T'-'A'] -= t;
		count['W'-'A'] -= t;
		count['O'-'A'] -= t;
		
		t = count['X'-'A'];
		result[6] = t;
		count['S'-'A'] -= t;
		count['I'-'A'] -= t;
		count['X'-'A'] -= t;

		t = count['S'-'A'];
		result[7] = t;
		count['S'-'A'] -= t;
		count['E'-'A'] -= t * 2;
		count['V'-'A'] -= t;
		count['N'-'A'] -= t;

		t = count['O'-'A'];
		result[1] = t;
		count['O'-'A'] -= t;
		count['N'-'A'] -= t;
		count['E'-'A'] -= t;

		t = count['V'-'A'];
		result[5] = t;
		count['F'-'A'] -= t;
		count['I'-'A'] -= t;
		count['V'-'A'] -= t;
		count['E'-'A'] -= t;

		t = count['G'-'A'];
		result[8] = t;
		count['E'-'A'] -= t;
		count['I'-'A'] -= t;
		count['G'-'A'] -= t;
		count['H'-'A'] -= t;
		count['T'-'A'] -= t;

		t = count['H'-'A'];
		result[3] = t;
		count['T'-'A'] -= t;
		count['H'-'A'] -= t;
		count['R'-'A'] -= t;
		count['E'-'A'] -= t * 2;

		t = count['N'-'A'];
		result[9] = t/2;

		string r="";
		for (int i=0;i<10;i++) {
			for (int j=0;j<result[i];j++) {
				if (i==0) r = r + "0";
				else if (i==1) r = r + "1";
				else if (i==2) r = r + "2";
				else if (i==3) r = r + "3";
				else if (i==4) r = r + "4";
				else if (i==5) r = r + "5";
				else if (i==6) r = r + "6";
				else if (i==7) r = r + "7";
				else if (i==8) r = r + "8";
				else if (i==9) r = r + "9";
			}
		}
		cout << "Case #" << (q1+1) << ": " << r << endl;
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}