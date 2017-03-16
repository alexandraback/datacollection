#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int T;
int K, L, S;
string alphabet;
string target;

long double maxBananas;


long double getExpected(string &str, int i)
{
	if (i==S){
		int found=-1;
		int count=0;
		do {
			found = str.find(target,found+1);
			if (found!=string::npos) 
				count++;
		}while (found!=string::npos);
		maxBananas = max(maxBananas, (long double)count);
		return count;
	}

	long double expected = 0;

	for (int j=0; j<alphabet.size(); j++)
	{
		str[i] = alphabet[j];
		expected += (1.0/(double)K) * getExpected(str,i+1);
	}
	return expected;
}

int main()
{
	ifstream cin;
	cin.open("B-small-attempt0.in");

	ofstream cout;
	cout.open("monkey_sevag_small.out");


	cin>>T;

	string str;

	for (int t=1; t<=T; t++)
	{
		cin>>K>>L>>S;
		cin>>alphabet;
		cin>>target;

		maxBananas=0;

		str.clear();
		for (int i=0; i<S; i++){
			str.push_back('A');
		}

		long double expectedBananas = getExpected(str,0);

		long double ans = maxBananas - expectedBananas;

		cout<<fixed<<setprecision(12);
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}

	return 0;
}