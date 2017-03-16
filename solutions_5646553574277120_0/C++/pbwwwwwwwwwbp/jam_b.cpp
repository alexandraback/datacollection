#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int coins[101];

bool myfunction (int i,int j) { return (i<j); }

int main() {
	int ii, jj, kk;
	int temp1, temp2, temp3;
	int c, d, v, t;
	int cnt, total, rnd;

	cin>> t;
	getchar();
	for (ii = 0; ii < t; ii++) {
		cnt = 0;
		total = 0;
		cin>>c>>d>>v;
		getchar();
		coins[0] = 0;
		for (jj = 0; jj < d; jj++) {
			cin>>coins[jj + 1];
		}
		getchar();

		sort(coins, coins + d, myfunction);

//		for (jj = 0; jj <=d; jj++) {
//			cout<<coins[jj]<<" ";
//		}
		total = 0;
		/*
		if (coins[1] > 1) {
			jj = 0;
		}
		else {
			jj = 1;
		}
		*/

		for (jj = 0; jj < d; jj++) {
			total += c * coins[jj];
			for (kk = total; kk < coins[jj + 1] - 1;) {
//				cout<<"TOTAL: "<<total<<"; WHILE "<<coins[jj+1] - 1<<endl;
//				cout<<"ADDING: "<<cnt + 1<<"; iter: "<<jj<<"; num "<<total + 1<<endl;
				total += c * (total + 1);
				kk = total;
				cnt ++;
			}
		}
		total += c*coins[d];

		for (kk = total; kk < v;) {
//			cout<<"ADDING: "<<cnt + 1<<"; num "<<total + 1<<endl;
			total += c * (total + 1);
			kk = total;
			cnt++;
		}



		cout<<"Case #" <<ii + 1 <<": "<<cnt<<endl;
	}



	return 0;
}








