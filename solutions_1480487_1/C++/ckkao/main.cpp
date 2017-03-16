#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int main() {
	ifstream cin("in.txt");
	ofstream cout("out.txt");
	int nCount = 0;
	int num;
	int judge[300] = {0};
	int sum;
	int total;
	int passnum;
	double factor;
	char a[3000];

	cin >> nCount;
	for(int i=1;i<=nCount;++i) {
		cin >> num;
		sum = 0;
		for(int j=0;j<num;++j) {
			cin >> judge[j];
			sum += judge[j];
		}

		total = sum*2; 
		factor = (double)total/num;
		
		// get others will win no need vote
		passnum = num;
		for(int j=0;j<num;++j) {
			if((double)judge[j] > factor) {
				total -= judge[j];
				--passnum;
			}
		}

		factor = (double)total / passnum;


		cout << "Case #"<<i<<":";
		for(int j=0;j<num;++j) {
			if((double)judge[j] >= factor) { //0
				double tmp = 0;
				sprintf(a," %.7lf",tmp);
				cout << a;
			}
			else {
				double needVote = factor - judge[j];
				double result = (double)needVote*100/sum;
				sprintf(a," %.7lf",result);
				cout << a;
			}
		}
		cout << endl;
	}
	system("pause");
}
