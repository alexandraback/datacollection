#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;
typedef unsigned int uint;
typedef long long vlong;

vector<vlong> geldigeDeler;

vlong grootste_gemene_deler(vlong a, vlong b)
{
	vlong c;
	while (a> 0) {
		c = a;
		a = b % a;
		b = c;
	}

	return b;
}



void solve(istream& is, uint index)
{
	vlong teller; vlong noemer;

	is >> teller;
	is.get();
	is >> noemer;


	//Verklein input
	vlong gcd;
	gcd = grootste_gemene_deler(teller, noemer);
	teller /= gcd;
	noemer /= gcd;

	//Noemer geldig ?
	bool geldig = false;
	for (int i = 0; i < geldigeDeler.size(); i++) {
		if (geldigeDeler[i] == noemer) {
			geldig = true;
		}
	}


	cout << "Case #" << index << ": ";
	int itt = 1;
	if (geldig) {
		while ((double)teller / (double)noemer < 0.5) {
			itt++;
			noemer = noemer / 2;
		}
		cout << itt << endl;
	}
	else {
		cout << "impossible" << endl;
	}
}

void oef(istream& is)
{
	uint n;
	is >> n;
	for (uint i = 0; i < n; i++)
		solve(is, i + 1);
}



int main()
{
	vlong teller = 1;
	for (int i = 1; i < 46; i++) {
		geldigeDeler.push_back(teller);
		teller *= 2;
	}



#ifdef EIGENTEST
	ifstream myfile;
	myfile.open("C:\\Users\\Brouckaert\\Desktop\\gcj\\data\\test.txt");
	oef(myfile);
	cin.get();
#else
	ifstream myfile;
	myfile.open("C:\\Users\\Brouckaert\\Desktop\\gcj\\data\\A-large.in");
	oef(myfile);
	//cin.get();
#endif
	return 0;
}

