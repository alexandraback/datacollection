#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <stack>
#include <map>
#include <iomanip>

using namespace std;

int main() {
	ifstream cin("A-large.in");
	ofstream cout("123.out");
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		string ss;
		ss+=s[0];
		for(int j=1;j<s.length();j++){
			if(s[j]>=ss[0]) ss=s[j]+ss;
			else
				ss+=s[j];
		}
		cout<<"Case #"<<(i+1)<<": "<<ss<<endl;
	}
	cin.close();
	cout.close();
	return 0;
}
