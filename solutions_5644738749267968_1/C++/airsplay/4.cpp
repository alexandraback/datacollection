#include<fstream>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
double a[1001], b[1001];
int n;
int main(){
	ifstream fin("4.in");
	ofstream fout("4.out");
	int testSum;
	fin >> testSum;
	for (int test = 1; test <= testSum; test++){
		fout << "Case #" << test << ":" << ' ';
		fin >> n;
		for (int i = 1; i <= n; i++)
			fin >> a[i];
		for (int i = 1; i <= n; i++)
			fin >> b[i];
		sort(a+1, a+n+1);
		sort(b+1, b+n+1);
		int ans1 = 0;
		int l = 1, r = n;
		for (int i = n; i >= 1; i--){
			if (b[r] > a[i]){
				r--;
			}
			else{
				l++;
				ans1++;
			}
		}
		int ans2 = 0;
		l = 1;
		r = n;
		int start = 1;
		while ((b[r] > a[n]) && (r > 1)){
			r--;
			start++;
		}
		for (int i = start; i<=n; i++){
			if (a[i] > b[l]){
				ans2++;
				l++;
			}
			else{
				r--;
			}
		}
		fout << ans2 << ' ' << ans1 << endl;
	}

}
