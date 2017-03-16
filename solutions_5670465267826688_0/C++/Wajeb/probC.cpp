#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, string> mp;

int main() {

	ifstream cin("probCsmall.in");
	ofstream cout("probCsmall.txt");

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
		int L, X;
		string r, s = "";
		cin >> L >> X >> r;
		for(int i = 0; i < X; i++) s = s + r;

		bool foundi = false, foundj = false, foundk = false;
		string curr = "";
		int index = 0;
		for(int i = 0; i < L * X; i++) // finding i
		{
			curr = curr + s[i];
			curr = mp[curr];
			if(curr == "i")
			{
				index = i;
				foundi = true;
				break;
			}
		}
		if(foundi)
		{
			curr = "";
			for(int i = index + 1; i < L * X; i++) // finding j
			{
				curr = curr + s[i];
				curr = mp[curr];
				if(curr == "j")
				{
					index = i;
					foundj = true;
					break;
				}
			}
			if(foundj)
			{
				curr = "";
				for(int i = index + 1; i < L * X; i++) // finding k
				{
					curr = curr + s[i];
					curr = mp[curr];
				}
				if(curr == "k") foundk = true;
			}
		}

		string res = foundi && foundj && foundk ? "YES" : "NO";
		cout << "Case #" << t + 1 << ": " << res << endl;

	}


	return 0;
}
