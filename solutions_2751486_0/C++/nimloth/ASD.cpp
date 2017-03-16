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

int main(){
	freopen("A-small-attempt0 (1).in", "r", stdin);
	freopen("OUTPUT.txt", "w", stdout);
	//cout.setf(ios::fixed);
	//cout.precision(10);
	int T;
	cin >> T;
	for(int z = 0; z < T; z++){
		string s;
		cin >> s;
		int l = s.length();
		int sum = 0;
		int n;
		cin >> n;
		for(int i = 0; i < l; i++)
			for(int j = i; j < l; j++){
				int k = 0;
				for(int w = i; w <= j; w++){
					if(s[w] != 'a' && s[w] != 'e' && s[w] != 'i' && s[w] != 'o' && s[w] != 'u'){
						k++;
						if(k >= n){
							sum++;
							break;
						}
					}
					else
						k = 0;
				}
			}
		cout << "Case #" << z + 1 << ": " << sum << "\n";
	}
	return 0;
}