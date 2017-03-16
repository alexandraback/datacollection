#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <stack>

using namespace std;

string s1,s2;
int len;
long long bestans, bestans1, bestans2;
int arr1[50], arr2[50];
int a[50],b[50], aa[50], bb[50];
void parse() {
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	cin >> s1 >> s2;
	len = s1.length();
	for (int i = 0; i < len; i++){
		if (s1[i]=='?')
			a[i] = -1;
		else
			a[i] = s1[i]-'0';
	}

	for (int i = 0; i < len; i++){
		if (s2[i]=='?')
			b[i] = -1;
		else
			b[i] = s2[i]-'0';
	}

	bestans = -1;
}

long long abs(long long a, long long b){
	if (a < b)
		return b -a ;
	else return a-b;
}


void makeans(){
	long long ans1 = 0;
	for (int i = 0; i < len; i++)
		ans1 = ans1*10 + a[i];

	long long ans2 = 0;
	for (int i = 0; i < len; i++)
		ans2 = ans2*10 + b[i];

	if (abs(ans1, ans2) < bestans || bestans == -1){
		bestans = abs(ans1, ans2);
		bestans1 = ans1;
		bestans2 = ans2;

		for (int i = 0 ; i < len; i++){
			arr1[i] = a[i];
			arr2[i] = b[i];
		}

	}
	else if (abs(ans1, ans2) == bestans){
		if (ans1 < bestans1){
			bestans1 = ans1;
			bestans2 = ans2;

			for (int i = 0 ; i < len; i++){
				arr1[i] = a[i];
				arr2[i] = b[i];
			}
		}
		else if (ans1 == bestans1){
			if (ans2 < bestans2){
				bestans1 = ans1;
				bestans2 = ans2;

			for (int i = 0 ; i < len; i++){
				arr1[i] = a[i];
				arr2[i] = b[i];
			}
			}
		}
	}
}

void makeit(int a[], int flag, int x){
	for (int i = flag; i < len; i++)
		if (a[i] == -1){
			if (x == 1)
				a[i] = 9;
			else a[i] = 0;
		}
}

void makeup(int a[], int b[], int flag){
		if (a[flag] < b[flag]){
			makeit(a, flag+1, 1);
			makeit(b, flag+1, 0);
		}
		else{
			makeit(a, flag+1, 0);
			makeit(b, flag+1, 1);
		}

		makeans();
}



void solve(int flag1) {
	int flag = flag1;
	if (flag >= len){
		makeans();
		return;
	}

	while (flag < len && a[flag] == b[flag]){
		if (a[flag]==-1)
			a[flag] = b[flag] = 0;
		flag ++;
	}
	//cout << "OK1 " << endl;
	if (flag >= flag1+1){
		for (int i = 0; i < 20; i++){
			aa[i] = a[i];
			bb[i] = b[i];
		}


		flag --;
		if(s1[flag] == '?' && s2[flag] == '?'){
			a[flag] = 0;
			b[flag] = 1;
			makeup(a, b, flag);
			for (int i = 0; i < 20; i++){
				a[i] = aa[i];
				b[i] = bb[i];
			}

			a[flag] = 1; b[flag] = 0; makeup(a,b,flag);
			for (int i = 0; i < 20; i++){
				a[i] = aa[i];
				b[i] = bb[i];
			}

			a[flag] = 0; b[flag] = 0; 
			//cout << "OK2 " << flag << a[0] << b[0] << endl;
		}
		flag ++;
		
	}

	if (a[flag]!=-1 && b[flag]!=-1){
		//cout << "OK3 " << a[0]<< a[1] <<b[0] << b[1]<<endl;
		makeup(a, b, flag);
		//makeans();
		return;
	} 
	

	else if (a[flag]== -1 && b[flag] != -1){
		//cout << "OK " << endl;
		for (int i = 0; i < 20; i++){
			aa[i] = a[i];
			bb[i] = b[i];
		}

		if (b[flag] != 0){
			a[flag] = b[flag] - 1;
			makeup(a, b, flag);
		}

		for (int i = 0; i < 20; i++){
			a[i] = aa[i];
			b[i] = bb[i];
		}


		if (b[flag] != 9){
			a[flag] = b[flag] +1;
			makeup(a, b, flag);
		}

		for (int i = 0; i < 20; i++){
			a[i] = aa[i];
			b[i] = bb[i];
		}

		a[flag] = b[flag];
		solve(flag + 1);

	}

	else if (b[flag] == -1 && a[flag] != -1){
		for (int i = 0; i < 20; i++){
			aa[i] = a[i];
			bb[i] = b[i];
		}

		if (a[flag] != 0){
			b[flag] = a[flag] - 1;
			makeup(a, b, flag);
		}

		for (int i = 0; i < 20; i++){
			a[i] = aa[i];
			b[i] = bb[i];
		}


		if (a[flag] != 9){
			b[flag] = a[flag] +1;
			makeup(a, b, flag);
		}

		for (int i = 0; i < 20; i++){
			a[i] = aa[i];
			b[i] = bb[i];
		}

		b[flag] = a[flag];
		
		solve(flag + 1);
	}
}

int main() {
	int T;
	cin >> T;
	//cout << "!!!!!!" << endl;
	for (int i = 1; i <= T; i++){
		parse();
	//	cout << "OK" << endl;
		solve(0);
		cout << "Case #" << i << ": ";
		for (int i =0 ; i < len; i++)
			cout << arr1[i];
		cout << " ";
		for (int i =0 ; i < len; i++)
			cout << arr2[i];
		cout << endl;
	}
	return 0;
}



