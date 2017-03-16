#include <iostream>
#include <string>

using namespace std;

int main()
{
	//freopen();
	//freopen();
	
	int t;
	cin >> t;
	for (int tc = 0; tc < t; ++tc){
		string s;
		cin >> s;
		int chars[256] = { 0 };
		for (auto c : s)
			chars[(char)c]++;
		
		int counts[10] = { 0 };
		// 6
		while (chars['X'])
		{
			counts[6]++;
			chars['S']--;
			chars['I']--;
			chars['X']--;
		}
		// 06
		while (chars['Z'])
		{
			counts[0]++;
			chars['Z']--;
			chars['E']--;
			chars['R']--;
			chars['O']--;
		}
		// 206
		while (chars['W'])
		{
			counts[2]++;
			chars['T']--;
			chars['W']--;
			chars['O']--;
		}
		// 8206
		while (chars['G'])
		{
			counts[8]++;
			chars['E']--;
			chars['I']--;
			chars['G']--;
			chars['H']--;
			chars['T']--;
		}
		// 48206
		while (chars['U'])
		{
			counts[4]++;
			chars['F']--;
			chars['O']--;
			chars['U']--;
			chars['R']--;
		}
		// 748206
		while (chars['S'])
		{
			counts[7]++;
			chars['S']--;
			chars['E']--;
			chars['V']--;
			chars['E']--;
			chars['N']--;
		}
		// 5748206
		while (chars['V'])
		{
			counts[5]++;
			chars['F']--;
			chars['I']--;
			chars['V']--;
			chars['E']--;
		}
		// 35748206
		while (chars['T'])
		{
			counts[3]++;
			chars['T']--;
			chars['H']--;
			chars['R']--;
			chars['E']--;
			chars['E']--;
		}
		// 135748206
		while (chars['O'])
		{
			counts[1]++;
			chars['O']--;
			chars['N']--;
			chars['E']--;
		}
		// 9135748206
		while (chars['N'])
		{
			counts[9]++;
			chars['N']--;
			chars['I']--;
			chars['N']--;
			chars['E']--;
		}
		printf("Case #%d: ", tc + 1);
		for (int i = 0; i < 10; ++i)
			while (counts[i]--)
				printf("%d", i);
		printf("\n");
	}
}