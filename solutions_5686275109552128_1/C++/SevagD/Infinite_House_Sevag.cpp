#include <iostream>
#include <fstream>
#include <queue>
using namespace std;


int main() 
{
	ifstream cin;
	cin.open("B-large.in");

	ofstream cout;
	cout.open("Inf_House_Sevag_large.out");

	int T;
	int D;
	int A[1005];

	cin>>T;

	for (int t=1; t<=T; t++) {

		int bestTime = 1e9;

		cin >> D;
		int maxElem = 0;
		for (int i=0; i<D; i++) {
			cin>>A[i];
			maxElem = max(maxElem, A[i]);
		}

		bestTime = maxElem;

		for (int target=2; target<=maxElem; target++) {
			int splits = 0;
			for (int i=0; i<D; i++) {
				int current = A[i];
				while (current>target) {
					current-=target;
					splits++;
				}
			}

			int res = target+splits;
			bestTime = min(bestTime, res);
		}
	

		cout<<"Case #"<<t<<": "<<bestTime<<endl;
	}

	return 0;
}