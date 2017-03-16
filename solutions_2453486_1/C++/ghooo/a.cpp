#include <iostream>
using namespace std;
int main(){
	freopen("A-small.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		if(i != 1) cout << endl;
		cout << "Case #" << i << ": ";
		char arr[4][4];

		int xs = 'X'*4, ys = 'O'*4, xt = 'X'*3+'T', yt='O'*3+'T';
		bool dotExists = false, xwon = false, ywon = false;

		for(int k = 0; k < 4; k++)
			for(int j = 0; j < 4; j++){
				cin >> arr[k][j];
				if(arr[k][j] == '.') dotExists = true;
			}

		for(int k = 0; k < 4; k++){
			int tot = 0;
			for(int j = 0; j < 4; j++) tot+=arr[k][j];
			if(tot == xs || tot == xt){ xwon = true; break;}
			if(tot == ys || tot == yt){ ywon = true; break;}
		}
		if(xwon) {cout << "X won"; continue;}
		if(ywon) {cout << "O won"; continue;}

		for(int k = 0; k < 4; k++){
			int tot = 0;
			for(int j = 0; j < 4; j++) tot+=arr[j][k];
			if(tot == xs || tot == xt){ xwon = true; break;}
			if(tot == ys || tot == yt){ ywon = true; break;}
		}
		if(xwon) {cout << "X won"; continue;}
		if(ywon) {cout << "O won"; continue;}

		int tot = 0;
		for(int k = 0; k < 4; k++){
			tot += arr[k][k];
		}
		if(tot == xs || tot == xt){ xwon = true;}
		else if(tot == ys || tot == yt){ ywon = true;}
		if(xwon) {cout << "X won"; continue;}
		if(ywon) {cout << "O won"; continue;}

		tot = 0;
		for(int k = 0; k < 4; k++){
			tot += arr[k][3-k];
		}
		if(tot == xs || tot == xt){ xwon = true;}
		else if(tot == ys || tot == yt){ ywon = true;}
		if(xwon) {cout << "X won"; continue;}
		if(ywon) {cout << "O won"; continue;}

		if(dotExists) cout << "Game has not completed";
		else cout << "Draw";
	}
	return 0;
}