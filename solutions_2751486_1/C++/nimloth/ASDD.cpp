#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<deque>
#include<utility>
#include<map>
#include<math.h>
#include<memory.h>

#define li long long
#define fs first
#define sc second
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define mp make_pair

using namespace std;

long long INF = 1e9 + 7;

inline int mod(int x){
	if(x < 0) return -x;
	else
		return x;
}

int p[1000005], sum[1000005];

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("OUTPUT.txt", "w", stdout);
	//cout.setf(ios::fixed);
	//cout.precision(10);
	int T;
	cin >> T;
	for(int z = 0; z < T; z++){
		string s;
		cin >> s;
		int l = s.length();
		int n;
		cin >> n;
		int k = 0;
		int con = 0;
		for(int i = 0; i < l; i++){
			if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u'){
				k++;
				con++;
			}
			else
				k = 0;
			p[i] = k;
		}
		if(n == 1){
			if(con > 0)
				cout << "Case #" << z + 1 << ": " << l * (l - 1) / 2 + l<< "\n";
			else
				cout << "Case #" << z + 1 << ": " << 0 << "\n";
			continue;
		}
		for(int i = 0; i < l; i++)
			sum[i] = 0;
		for(int i = 1; i < l; i++)
			if(p[i] < n)
				sum[i] = sum[i - 1];
			else
				sum[i] = i - n + 2;
		int summ = 0;
		for(int i = 0; i < l; i++)
			summ += sum[i];
		cout << "Case #" << z + 1 << ": " << summ << "\n";
	}
	return 0;
}