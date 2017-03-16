#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

int f(int i)
{
	if (i == 1) return 9;
	if (i == 2) return 99;
	if (i == 3) return 999;
}

int f1(int i)
{
	return 0;
//	if (i == 1) return 0;
//	if (i == 2) return 10;
//	if (i == 3) return 100;
}


int main()
{
	freopen("B-small-attempt1.in", "r", stdin);
//	freopen("in.txt", "r", stdin);
//	ofstream fout("out.txt");
	freopen("out.txt", "w", stdout);
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		string s1, s2;
		cin >> s1 >> s2;
		int wid1 = s1.size();
		int wid2 = s2.size();
		bool is_fis = true;
//		while(s1.size() > 1 && (s1[0] == '?' || s1[0] == '0')  && s2.size() > 1 && (s2[0] == '?' || s2[0] == '0')) {
//			s1.erase(s1.begin());
//			s2.erase(s2.begin());
//		}
//		while(s2.size() > 1 && s2[0] == '?') {
//		}
		int min_d = 1000000;
		int ans_c = -1;
				int ans_j = -1;
		for (int j = f1(s1.size()); j <= f(s1.size()); ++j)
		{
			bool eq = true;
			string s3 = to_string(j);
			s3.insert(s3.begin(), s1.size() - s3.size(), '0');
//			cout << s3 << endl;
			for (int k = 0; k < s1.size(); ++k)
			{
				if ((s1[k] != '?' && s3[k] != s1[k]))
				{
					eq = false;
				}
			}

			if (eq)
			{
				for (int k = f1(s1.size()); k <= f(s1.size()); ++k)
				{
					bool eq1 = true;
					string s4 = to_string(k);
					s4.insert(s4.begin(), s2.size() - s4.size(), '0');
					for (int l = 0; l < s2.size(); ++l)
					{
						if ((s2[l] != '?' && s4[l] != s2[l]))
						{
							eq1 = false;
						}
					}
					if (eq1)
					{
//			cout << s4 << endl;
						if (min_d > abs(k - j))
						{
							min_d = abs(k - j);
							ans_c = j;
							ans_j = k;
						}
//						break;
					}
				}
			}
		}
		printf("Case #%d: ", i + 1);
		cout << setfill('0') << setw(wid1) << ans_c <<
				" " <<setfill('0') << setw(wid2)<< ans_j << endl;
	}
	return 0;
}

