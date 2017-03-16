#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<climits>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;

#define y1 mine
#define mp make_pair

double pi = acos(-1);
ll power(ll a, ll b){ ll p_res = 1; while (b > 0){ if (b % 2 == 1) { p_res *= a; b--;} a *= a; b /= 2;} return p_res;}


string str1, str2;
int l = 1000, r = 1000;
int sub = 100000;
int val1[10];
int val2[10];
int temp1, temp2;
void make_val(){

}
void func(){
	

	vector<int> loc1, loc2;

	for (int i = str1.size()-1; i >= 0; i--){
		if (str1[i] != '?')
			loc1.push_back(i);
	}
	for (int i = str2.size()-1; i >= 0; i--){
		if (str2[i] != '?')
			loc2.push_back(i);
	}
	if (str1.size() == 1){
		for (int tt1 = 0; tt1 <= 9; tt1++){
			
			for (int tt2 = 0; tt2 <= 9; tt2++){
				int n1 = tt1;
				int n2 = tt2;
				for (int l1 = 0; l1 < loc1.size(); l1++){
					int di = loc1[l1];
					if (di == 0) {
						n1 = ((str1[0] - '0'));

					}
				}
				for (int l2 = 0; l2 < loc2.size(); l2++){
					int di = loc2[l2];
					if (di == 0) {
						n2 = ((str2[0] - '0'));
					}
				}
				if (abs(n1 - n2) < sub){
					l = n1;
					r = n2;
					sub = abs(n1 - n2);
				}
				else if (abs(n1 - n2) == sub){
					if (n1 < l){
						l = n1;
						r = n2;
					}
					else if (n1 == l && n2 < r){
						l = n1;
						r = n2;
					}
				}
			}
		}
	}
	if (str1.size() == 2){
		for (int tt1 = 0; tt1 <= 99; tt1++){
			
			for (int tt2 = 0; tt2 <= 99; tt2++){
				int n1 = tt1;
				int n2 = tt2;
				for (int l1 = 0; l1 < loc1.size(); l1++){
					int di = loc1[l1];
					if (di == 1) {
						n1 = (n1 / 10) * 10 + ((str1[1] - '0'));

					}
					if (di == 0) {
						n1 = ((str1[0] - '0')) * 10 + n1 % 10;
					}
				}
				for (int l2 = 0; l2 < loc2.size(); l2++){
					int di = loc2[l2];
					if (di == 1) {
						n2 = (n2 / 10) * 10 + ((str2[1] - '0'));
					}
					if (di == 0) {
						n2 = ((str2[0] - '0')) * 10 + n2 % 10;
					}
				}
				if (abs(n1 - n2) < sub){
					l = n1;
					r = n2;
					sub = abs(n1 - n2);
				}
				else if (abs(n1 - n2) == sub){
					if (n1 < l){
						l = n1;
						r = n2;
					}
					else if (n1 == l && n2 < r){
						l = n1;
						r = n2;
					}
				}
			}
		}
	}
	if (str1.size() == 3){
		for (int tt1 = 0; tt1 <= 999; tt1++){
			
			for (int tt2 = 0; tt2 <= 999; tt2++){
				int n1 = tt1;
				int n2 = tt2;
				for (int l1 = 0; l1 < loc1.size(); l1++){
					int di = loc1[l1];
					if (di == 2) {
						n1 = (n1 / 10) * 10 + ((str1[2] - '0'));
					}
					if (di == 1) {
						n1 = (n1 / 100) * 100 + ((str1[1] - '0')) * 10 + n1 % 10;

					}
					if (di == 0) {
						n1 = ((str1[0] - '0')) * 100 + (n1 % 100);
					}
				}
				for (int l2 = 0; l2 < loc2.size(); l2++){
					int di = loc2[l2];
					if (di == 2) {
						n2 = (n2 / 10) * 10 + ((str2[2] - '0'));
					}
					if (di == 1) {
						n2 = (n2 / 100) * 100 + ((str2[1] - '0')) * 10 + n2 % 10;

					}
					if (di == 0) {
						n2 = ((str2[0] - '0')) * 100 + (n2 % 100);
					}
				}
				if (abs(n1 - n2) < sub){
					l = n1;
					r = n2;
					sub = abs(n1 - n2);
				}
				else if (abs(n1 - n2) == sub){
					if (n1 < l){
						l = n1;
						r = n2;
					}
					else if (n1 == l && n2 < r){
						l = n1;
						r = n2;
					}
				}
			}
		}
	}
}
int main(){
	//freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T; cin >> T;

	for (int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";
		if (t == 17)
			int dd = 11;
		cin >> str1 >> str2;
		sub = l = r = 100000;
		func();
		if (str1.size() == 2 && l < 10)
			cout << "0";

		if (str1.size() == 3 && l < 100)
			cout << "0";
		if (str1.size() == 3 && l < 10)
			cout << "0";


		cout << l << " ";
		if (str1.size() == 2 && r < 10)
			cout << "0";
		if (str1.size() == 3 && r < 100)
			cout << "0";
		if (str1.size() == 3 && r < 10)
			cout << "0";
		cout << r;
		cout << endl;
	}


	return 0;
}


