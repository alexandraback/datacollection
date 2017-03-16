#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool testing = 0;

int n;
double a[1010], backup[1010];
bool used[1010];

const double eps = 0.0000000001;

int f(const bool dec, const double b[1010]){
	int cnt = 0;
	for(int i=0; i<n; i++) used[i] = false;
	
	for(int i=0; i<n; i++){
		int j;
		double x = a[i];
		
		if(dec){
			for(j=0;;j++)
				if(!used[j]) break;
			if(testing) cout << "__here:__ " << x << ' ' << b[j] << endl;
			if(x < b[j]){
				for(j=n-1;;j--)
					if(!used[j]) break;
				x = max(x, b[j]-eps);
			}
			else{
				x = 1;
			}
		}
		
		for(j=0; j<n; j++){
			if(!used[j] && b[j] > x){
				used[j] = true;
				break;	
			}
		}
		
		if(j == n){
			cnt++;
			for(j=0; ; j++){
				if(!used[j]){
					used[j] = true;
					break;
				}
			}
		}

		if(testing) cout << "__" << x << ' ' << b[j] << endl;
	}
	return cnt;
}

void main(){
	//*
	freopen("dd.in", "r", stdin);
	freopen("dd.out", "w", stdout);
	//*/

	int T;
	cin >> T;
	for(int tc=1; tc<=T; tc++){
		double b[1010];
		cin >> n;
		for(int i=0; i<n; i++) cin>>a[i];
		for(int i=0; i<n; i++) cin>>b[i];
		sort(a, a+n);
		sort(b, b+n);

		cout << "Case #" << tc << ": ";
		for(int i=0; i<n; i++) backup[i] = a[i];
		cout << f(true, b) << ' ';
		for(int i=0; i<n; i++) a[i] = backup[i];
		cout << f(false, b) << endl;
	}
}
/*
4
1
0.5
0.6
2
0.7 0.2
0.8 0.3
3
0.5 0.1 0.9
0.6 0.4 0.3
9
0.186 0.389 0.907 0.832 0.959 0.557 0.300 0.992 0.899
0.916 0.728 0.271 0.520 0.700 0.521 0.215 0.341 0.458

9
1 4 6 10 13 14 15 17 18
2 3 5 7 8 9 11 12 16


Case #1: 0 0
Case #2: 1 0
Case #3: 2 1
Case #4: 8 4
*/