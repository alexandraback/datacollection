#pragma warning(disable : 4996)
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

void process(int t){
	string s;
	cin >> s;
	vector<int> chars(26, 0);
	for (int i = 0; i < s.size(); i++){
		chars[s[i] - 'A']++;
	}
	vector<pair<string, int>> numbers;

	numbers.push_back(make_pair("EIGHT", 8));
	numbers.push_back(make_pair("SIX", 6));
	numbers.push_back(make_pair("SEVEN", 7));
	numbers.push_back(make_pair("FIVE", 5));
	numbers.push_back(make_pair("FOUR", 4));
	numbers.push_back(make_pair("NINE", 9));
	numbers.push_back(make_pair("THREE", 3));
	numbers.push_back(make_pair("TWO", 2));
	numbers.push_back(make_pair("ONE", 1));
	numbers.push_back(make_pair("ZERO", 0));
	vector<int> res(10, 0);
	for (int i = 0; i < 10; i++){
		vector<int> v(26, 0);
		for (int j = 0; j < numbers[i].first.size(); j++)
			v[numbers[i].first[j] - 'A']++;
		while (true){
			bool ok = true;
			for (int j = 0; j < 26; j++)
				if (v[j] > chars[j])
					ok = false;
			if (!ok)
				break;
			for (int j = 0; j < 26; j++)
				chars[j] -= v[j];
			res[numbers[i].second]++;
		}
	}
	cout << "Case #"<< t <<": ";
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < res[i]; j++)
			cout << i;
	cout << "\n";

}

int main()
{
	freopen("d:\\acm\\CodeJam\\2016\\Round1B\\A\\A.in", "r", stdin);
	freopen("d:\\acm\\CodeJam\\2016\\Round1B\\A\\A.out", "w", stdout);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++){
		process(t+1);
	}
	return 0;
}