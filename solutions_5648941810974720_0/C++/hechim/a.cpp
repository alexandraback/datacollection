#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

ifstream fin("a.in");
ofstream fout("a.out");

vector<int> nums;
int order[] = {0,2,6,8,3,7,5,4,9,1};

vector<string> letters;
void populatelett() {
	letters.push_back("ZERO");
	letters.push_back("ONE");
	letters.push_back("TWO");
	letters.push_back("THREE");
	letters.push_back("FOUR");
	letters.push_back("FIVE");
	letters.push_back("SIX");
	letters.push_back("SEVEN");
	letters.push_back("EIGHT");
	letters.push_back("NINE");
}

pair<string,bool> finddigit(string x, string lett) {
	map<char,int> cnt;
	for(int i=0; i<(int)lett.size(); i++) {
		if(cnt.count(lett[i])==0)
			cnt[lett[i]] = 1;
		else
			cnt[lett[i]]++;
	}

	string y;
	for(int i=0; i<(int)x.size(); i++) {
		if(cnt.count(x[i])>0) {
			cnt[x[i]]--;
			if(cnt[x[i]]==0)
				cnt.erase(x[i]);
		}
		else
			y.push_back(x[i]);
	}

	return make_pair<string,bool>(y,(cnt.size()==0));
}

string getnumber(string x) {
	nums.clear();

	cout << x << endl;
	int i = 0;
	while(i<=9) {
		int digit = order[i];
		cout << digit << " ";
		pair<string,bool> p = finddigit(x,letters[digit]);
		if(p.second) {
			x = p.first;
			nums.push_back(digit);
		}
		else {
			i++;
		}
		cout << x << endl;
	}

	sort(nums.begin(), nums.end());
	string y;
	for(int i=0; i<(int)nums.size(); i++)
		y.push_back( nums[i]+'0' );
	return y;
}

int main() {

	populatelett();
	int T; fin>>T;
	for(int t=1; t<=T; t++) {
		string x;
		fin >> x;
		string y = getnumber(x);
		fout << "Case #" << t << ": " << y << endl;
	}
	return 0;

}
