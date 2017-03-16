#include <iostream>
#include <string>

using namespace std;

bool greedypig(string s);

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int blocklen;
		long long nblocks;
		cin >> blocklen >> nblocks;

		string block;
		cin >> block;

		if (nblocks > 12) nblocks = 12 + (nblocks%4);

		// concat blocks together
		string qstring;
		for (int k = 0; k < nblocks; k++) qstring += block;

		cout << "Case #" << t + 1<< ": ";
		if (greedypig(qstring)) cout << "YES\n";
		else cout << "NO\n";
	}

}


int conv(char q) {
	
	if (q=='i') return 2;
	if (q=='j') return 3;
	if (q=='k') return 4;
	
	cout << "wtf";
	return 142857;
}

int mult(int a, int b) {

	int sign = 1;
	if (a*b<0) sign = -1;

	if (a<0) a=-a;
	if (b<0) b=-b;

	int c;
	if (a == b && a == 1) c = 1;
	else if (a == b) c = -1;

	if (a==2 && b==3) c = 4;
	if (a==3 && b==4) c = 2;
	if (a==4 && b==2) c = 3;

	if (b==2 && a==3) c = -4;
	if (b==3 && a==4) c = -2;
	if (b==4 && a==2) c = -3;

	if (a==1) c = b;
	if (b==1) c = a;

	return c * sign;

}

// Assume already corrected for len
bool greedypig(string s) {

	int w=-1, p=-1;

	// greedy search from front for i
	int q = 1;
	for (int k = 0; k < s.length(); k++){
		q = mult(q, conv(s.c_str()[k]));
		if (q==2) {
			w = k+1;
			break;
		}
	}
//cout <<" REACHED1";
	// greedy search from back for k
	q = 1;
	for (int k = 0; k < s.length(); k++){
		q = mult(conv(s.c_str()[s.length()-1-k]), q);
		if (q==4) {
			p = k+1;
			break;
		}
	}
	if (w==-1 || p == -1) return false;
	//cout << "REACHED2";
	// full multiply
	q = 1;
	for (int k = 0; k < s.length(); k++){
		//cout << q << endl;
		q = mult(q, conv(s.c_str()[k]));
	}
	//cout << q << "REACHED3";
	if (q != -1) return false;
	//cout << "REACHED4";
	if (w + p > s.length()) return false;
	//cout << w << p << endl;
	return true;
}