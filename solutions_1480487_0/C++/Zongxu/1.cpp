#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int n, num, s[200], sum, sum2, mins, minp, min2s, min2p;
bool eli[200];

int main() {
	freopen("a-small-attempt2.in", "r", stdin);
	freopen("a-small.out", "w", stdout);

	int T; cin>>T;
	for (int t=1; t<=T; t++) {
		cin>>n; sum = 0;
		for (int i=0; i<n; i++) {
			cin>>s[i];
			sum+=s[i];
			//if (i==0) {
			//	mins = s[0];
			//	minp = 0;
			//}
			//else if (i==1) {
			//	min2s = s[1];
			//	min2p = 1;
			//	if (s[0] > s[1]) {
			//		swap(mins, min2s);
			//		swap(minp, min2p);
			//	}
			//}
			//else {
			//	if (s[i]<mins) {
			//		min2s = mins; min2p = minp;
			//		mins = s[i]; minp = i;
			//	}
			//	else if (s[i]<min2s) {
			//		min2s = s[i]; min2p = i;
			//	}
			//}
		}

		bool changed;
		double avg;
		sum2 = sum;
		num = n;
		memset(eli, 0, sizeof(eli));
		do {
			avg = double(sum + sum2) / num;
			changed = false;
			for (int i=0; i<n; i++) {
				if (!eli[i]) {
					if (s[i]>avg) {
						eli[i] = true;
						sum2 -= s[i];
						num --;
						changed = true;
					}
				}
			}
		} while (changed);
		
		printf("Case #%d: ", t);
		cout<<fixed<<setprecision(6);
		for (int i=0; i<n; i++) {
			if (s[i] > avg)
				cout<<0<<' ';
			else
				cout<<100.0*(avg-s[i])/sum<<' ';
		}
		cout<<endl;
	}
}
