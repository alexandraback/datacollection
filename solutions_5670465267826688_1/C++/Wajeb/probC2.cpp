#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, string> mp;

int main() {

	ifstream cin("probClarge.in");
	ofstream cout("probClarge.txt");

	mp["1"] = "1"; mp["i"] = "i"; mp["j"] = "j"; mp["k"] = "k";

	mp["11"] = "1"; mp["1i"] = "i"; mp["1j"] = "j"; mp["1k"] = "k";
	mp["i1"] = "i"; mp["ii"] = "-1"; mp["ij"] = "k"; mp["ik"] = "-j";
	mp["j1"] = "j"; mp["ji"] = "-k"; mp["jj"] = "-1"; mp["jk"] = "i";
	mp["k1"] = "k"; mp["ki"] = "j"; mp["kj"] = "-i"; mp["kk"] = "-1";

	mp["-11"] = "-1"; mp["-1i"] = "-i"; mp["-1j"] = "-j"; mp["-1k"] = "-k";
	mp["-i1"] = "-i"; mp["-ii"] = "1"; mp["-ij"] = "-k"; mp["-ik"] = "j";
	mp["-j1"] = "-j"; mp["-ji"] = "k"; mp["-jj"] = "1"; mp["-jk"] = "-i";
	mp["-k1"] = "-k"; mp["-ki"] = "-j"; mp["-kj"] = "i"; mp["-kk"] = "1";

	mp["1-1"] = "-1"; mp["1-i"] = "-i"; mp["1-j"] = "-j"; mp["1-k"] = "-k";
	mp["i-1"] = "-i"; mp["i-i"] = "1"; mp["i-j"] = "-k"; mp["i-k"] = "j";
	mp["j-1"] = "-j"; mp["j-i"] = "k"; mp["j-j"] = "1"; mp["j-k"] = "-i";
	mp["k-1"] = "-k"; mp["k-i"] = "-j"; mp["k-j"] = "i"; mp["k-k"] = "1";

	mp["-1-1"] = "1"; mp["-1-i"] = "i"; mp["-1-j"] = "j"; mp["-1-k"] = "k";
	mp["-i-1"] = "i"; mp["-i-i"] = "-1"; mp["-i-j"] = "k"; mp["-i-k"] = "-j";
	mp["-j-1"] = "j"; mp["-j-i"] = "-k"; mp["-j-j"] = "-1"; mp["-j-k"] = "i";
	mp["-k-1"] = "k"; mp["-k-i"] = "j"; mp["-k-j"] = "-i"; mp["-k-k"] = "-1";

	int T;
	cin >> T;
	for(int t = 0; t < T; t++)
	{
		int L;
		unsigned long long X;
		string r;
		cin >> L >> X >> r;

		bool step1 = false, step2 = false, step3 = false, step4 = false;
		string curr = "";
		for(int i = 0; i < L; i++)
		{
			curr = curr + r[i];
			curr = mp[curr];
		}
		if( ( (curr == "-1") && (X % 2 == 1) ) ||
				( (curr ==  "i") && (X % 4 == 2) ) ||
				( (curr ==  "j") && (X % 4 == 2) ) ||
				( (curr ==  "k") && (X % 4 == 2) ) ||
				( (curr ==  "-i") && (X % 4 == 2) ) ||
				( (curr ==  "-j") && (X % 4 == 2) ) ||
				( (curr ==  "-k") && (X % 4 == 2) ) )
		{
			step1 = true;
//			cout << "step1" << endl;

			map<pair<int, string>, int> dpi;
			unsigned long long counter = 0;

			// finding i
			curr = "";
			int index;
			for(int i = 0; i < L; i = (i + 1) % L)
			{
				if(i == 0) counter++;

				curr = curr + r[i];
				curr = mp[curr];

				pair<int, string> p = make_pair(i, curr);
				if(dpi.count(p) > 0) break;
				dpi[p] = 1;
				if(curr == "i")
				{
					step2 = true;
//					cout << "step2" << endl;
					index = i;
					break;
				}
			}
			if(step2)
			{
				map<pair<int, string>, int> dpj;

				// finding j
				curr = "";
				for(int i = (index + 1) % L; i < L; i = (i + 1) % L)
				{
					if(i == 0) counter++;

//					cout << curr << endl;
					curr = curr + r[i];
//					cout << curr << endl;
					curr = mp[curr];
//					cout << curr << endl;

					pair<int, string> p = make_pair(i, curr);
					if(dpj.count(p) > 0) break;
					dpj[p] = 1;
					if(curr == "j")
					{
						step3 = true;
//						cout << "step3" << endl;
						index = i;
						break;
					}
				}
				if(step3)
				{
					if(counter <= X) step4 = true;
				}
			}
		}

		string res = step1 && step2 && step3 && step4 ? "YES" : "NO";
		cout << "Case #" << t + 1 << ": " << res << endl;

	}


	return 0;
}
