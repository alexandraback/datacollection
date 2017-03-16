#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int t;
	int n;
	int X;
	int k;
	bool imajos;
	double X2;

	int J[210];
	double Y[210];
	double tmp;
	bool b[210];

	cin >> t;

	for (int ti = 0; ti < t; ti++){
		cin >> n;
		X = 0;
		for (int i = 0; i < n; i++){
			cin >> J[i];
			b[i] = true;
			X += J[i];
		}

		k = 0; X2 = (double)X;
		for (int i = 0; i < n; i++){
			if ((double)2.0*X2/(double)(n-k) < (double)J[i]  && b[i]){
				k++;
				b[i] = false;
				X2 -= 0.5*(double)J[i];
				i = -1;
			}
		}

		for (int i = 0; i < n; i++){
			Y[i] = ((double)2.0*X2/(double)((n-k)*X) - (double)J[i]/(double)X) * (double)100.0;
			if (Y[i] < 0.0)
				Y[i] = 0.0;
		}

		printf("Case #%d:", ti+1);
		for (int i = 0; i < n; i++){
			printf(" %.6lf", Y[i]);
		}
		printf("\n");
	}

	return 0;
}