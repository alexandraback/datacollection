#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

ofstream out;
#define MAX 10000000

vector<long long int> palin_sq;

bool is_palin(string s) {
	for(int i = 0; i < (int)s.size()/2; ++i) {
		if(s[i] != s[s.size()-1-i])
			return false;
	}
	return true;
}
void populate(void) {
	string temp;
	long long int j;
	for(long long int i = 1; i <= MAX; ++i) {
		stringstream sout;
		sout << i;
		temp = sout.str();
		if(is_palin(temp)) {
			j = i*i;
			sout.str("");
			sout<<j;
			temp = sout.str();
			if(is_palin(temp)) {
				palin_sq.push_back(j);
			}
		}

	}
}
void solve(long long int A, long long int B) {
	long long int count = 0;
	for(int i = 0; i < palin_sq.size(); ++i){
		if(palin_sq[i] >= A && palin_sq[i] <= B)
			count++;
		else if(palin_sq[i] > B)
			break;
	}
	out<<count<<endl;

}

int main() {
	ifstream in;

	in.open("C-large-1.in");
	out.open("output.txt");
	int T;
	long long int A, B;

	populate();
	in>>T;

	for(int k = 0; k < T; ++k) {
		in>>A>>B;
		out<<"Case #"<<k+1<<": ";
		solve(A, B);
	}

	in.close();
	out.close();
	return 0;
}
