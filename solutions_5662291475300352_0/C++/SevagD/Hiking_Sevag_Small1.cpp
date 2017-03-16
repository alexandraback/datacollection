#include <iostream>
#include <fstream>
using namespace std;

int T, N, D, H, M;
int hikersPos[2];
int hikersTime[2];
long double hikersSpeed[2];

int main() 
{
	ifstream cin;
	cin.open("C-small-1-attempt2.in");

	ofstream cout;
	cout.open("Hiking_Sevag_small1.out");

	cin>>T;

	for (int t=1; t<=T; t++) 
	{
		cin>>N;
		int h=0;
		for (int i=0; i<N; i++) {
			cin>>D>>H>>M;
			for (int j=0; j<H; j++) {
				hikersPos[h] = D;
				hikersTime[h] = M;
				hikersSpeed[h] = 360.0/(long double)M;
				M++;
				h++;
			}
		}

		int fastIndx;
		int slowIndx;
		if (hikersSpeed[0] > hikersSpeed[1]) {
			fastIndx = 0;
			slowIndx = 1;
		} else {
			fastIndx = 1;
			slowIndx  = 0;
		}

		if (hikersTime[0] == hikersTime[1]) {
			cout<<"Case #"<<t<<": "<<0<<endl;
		}else {
			long double timeNeededBySlow = (360 - hikersPos[slowIndx])/hikersSpeed[slowIndx];

			long double relativeSpeed = hikersSpeed[fastIndx] - hikersSpeed[slowIndx];
			long double distBetween = hikersPos[slowIndx] + 360 - hikersPos[fastIndx];
			long double timeNeededToCatch = distBetween/relativeSpeed;

			if (timeNeededToCatch <= timeNeededBySlow) {
				cout<<"Case #"<<t<<": "<<1<<endl;
			} else {
				cout<<"Case #"<<t<<": "<<0<<endl;
			}
			
		}
	}


	return 0;
}