#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cmath>
#include <queue>
#include <list>
#include <map>
#include <deque>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	//freopen("A-small-attempt2.in", "r", stdin); freopen("a-small1.out", "w", stdout);
	//freopen("A-small-attempt2.in", "r", stdin); freopen("a-small2.out", "w", stdout);
	//freopen("A-small-attempt3.in", "r", stdin); freopen("a-small3.out", "w", stdout);
	freopen("A-large.in", "r", stdin); freopen("a-large.out", "w", stdout);

	int cases;
	cin >> cases;
	cin.ignore();
	for (int cnt = 1; cnt <= cases; cnt++) {

		int p;
		double dp;
		double sum=0;
		int j[1000];
		cin >> p;
		dp=p;
		for (int i=0;i<p;i++) {
			cin >> j[i];
			sum += j[i];
		}
		double sump=sum;
		double ave;
		double k[1000]={1};
		int f[1000]={0};
		int flag =1;
		while (flag==1){
		ave = (sum+sump)/dp;
		flag =0;
		for (int i=0;i<p;i++){
			if (f[i]!=1){
				k[i]=(ave-j[i])/sum*100.0;
			if (k[i]<0) {
				k[i]=0;
				f[i]=1;
				flag=1;
				sump=sump-j[i];
				dp--;
			}
			}
		}
		}

		cout << "Case #" << cnt << ":";
		for (int i=0;i<p;i++) {
		cout << " " <<fixed<< setprecision(10)<<k[i];
		}
		cout << endl;
	}

	return 0;
}
