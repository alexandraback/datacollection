#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c, d, v;
int value[1000000000];

int main(){
	/*
	ifstream cin;
	cin.open("clarge.in");
	ofstream cout;
	cout.open("clargereal.o");
	*/
	int tc; cin >> tc;
	for(int a = 1; a <= tc; a++){
		memset(value, 0, sizeof value);
		int c,d,v; cin >> c >> d >> v;
		int arr[d];
		for(int i = 0; i < d; i++){
			cin >> arr[i];
		}
		sort(arr, arr + d);
		for(int i = 0; i < d; i++){
			for(int j = 0; j <= c; j++){
				value[arr[i] * j] = 1;
			}
		}
		for(ll i = 0; i <= v; i++){
			
		}
	
	}

}
