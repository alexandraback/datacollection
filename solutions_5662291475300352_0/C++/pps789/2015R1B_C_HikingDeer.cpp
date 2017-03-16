#include<iostream>
#include<algorithm>
using namespace std;

int n;
int d[555555], h[555555], m[555555];

int main(){
	freopen("input.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++){
		cout << "Case #" << tc << ": ";
		cin >> n;
		for (int i = 0; i < n; i++) cin >> d[i] >> h[i] >> m[i];

		int tot_hiker = 0;
		for (int i = 0; i < n; i++) tot_hiker += h[i];
		if (tot_hiker == 1){
			cout << 0 << endl;
			continue;
		}

		if (n == 1){
			double v1 = 360. / m[0];
			double v2 = 360. / (m[0] + 1);
			double left_dis = ((double)(360 - d[0]));
			double t2 = left_dis / v2;
			double l1 = t2 * v1;
			if (l1 - left_dis >= 360.){
				cout << 1 << endl;
			}
			else{
				cout << 0 << endl;
			}
			continue;
		}

		if (n == 2){
			if (d[0] == d[1]){
				double v1 = 360. / m[0];
				double v2 = 360. / m[1];
				if (m[0] > m[1]) swap(v1, v2);
				double left_dis = ((double)(360 - d[0]));
				double t2 = left_dis / v2;
				double l1 = t2 * v1;
				if (l1 - left_dis >= 360.){
					cout << 1 << endl;
				}
				else{
					cout << 0 << endl;
				}
			}
			else{
				double a1 = ((double)d[0]), a2 = ((double)d[1]);
				double v1 = 360. / m[0], v2 = 360. / m[1];
				if (a1 > a2){
					swap(a1, a2); swap(v1, v2);
				}

				if (v1 == v2){
					cout << 0 << endl;
				}
				else if (v1 < v2){
					double t1 = (360. - a1) / v1;
					double l2 = t1 * v2;
					if (l2 - (360. - a1) >= 360.){
						cout << 1 << endl;
					}
					else{
						cout << 0 << endl;
					}
				}
				else{
					double t2 = (360. - a2) / v2;
					double l1 = t2 * v1;
					if (l1 >= 360. + (360. - a1))
						cout << 1 << endl;
					else cout << 0 << endl;
				}
			}
		}
	}
}