#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include <algorithm>

using namespace std;

int largestFaker(vector<string>& first, vector<string>& second, unordered_map<string, int>& count1, unordered_map<string, int>& count2, int start) {
	if (start == first.size())
		return 0;
	int c1 = 0;
	if (count1[first[start]] > 1 && count2[second[start]] > 1) {
		count1[first[start]]--;
		count2[second[start]]--;
		c1 = 1 + largestFaker(first, second, count1, count2, start + 1);
		count1[first[start]]++;
		count2[second[start]]++;
	}
	int c2 = largestFaker(first, second, count1, count2, start + 1);
	return max(c1, c2);
}

int main(int argc, char **argv) {
	ifstream in(argv[1]);
	ofstream out(argv[2]);
	int case_num;
	in >> case_num;
	for (int i = 0; i < case_num; ++i) {
		int n;
		in >> n;
		unordered_map<string, int> count1, count2;
		vector<string> f, s;
		for (int j = 0; j < n; ++j) {
			string first, second;
			in >> first >> second;
			f.push_back(first);
			s.push_back(second);
		}
		for (int i = 0; i < f.size(); ++i)
			count1[f[i]]++;
		for (int i = 0; i < s.size(); ++i)
			count2[s[i]]++;
		int c = largestFaker(f, s, count1, count2, 0);
		cout << c << "\n";
		out << "Case #" << i + 1 << ": " << c << "\n"; 
	}
	in.close();
	out.close();
	return 0;
}