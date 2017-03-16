#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
#include <iomanip>
#include <map>
#include <queue>
#include <ctime>
#include <stack>
#include <bitset>

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define bitcnt(x) __builtin_popcountll(x)
#define rt return

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

const int INF = (int)1e9 + 37;
const ld PI = acos(-1.0);
const int MAXN = (int)5e4 + 222;

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};
const char dir[4] = {'L', 'U', 'R', 'D'};

const string a[10] = {"ZERO", "ONE", "WTO", "RHTEE", "UOFR", "FIVE", "XIS", "VESEN", "GIEHT", "NINE"};

int main(){
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	int T;
	cin >> T;
	for (int Test=1;Test<=T;Test++){
		string s;
		string left;
		cin >> s;
		vector <int> cnt(10);
		vector <bool> used((int)s.length());
		for (int i=0;i<(int)s.length();i++){
			if (s[i] == 'Z'){
				cnt[0]++;
				used[i] = 1;
			} else if (s[i] == 'W'){
				cnt[2]++;
				used[i] = 1;
			} else if (s[i] == 'U'){
				cnt[4]++;
				used[i] = 1;
			} else if (s[i] == 'X'){
				cnt[6]++;
				used[i] = 1;
			}  else if (s[i] == 'G'){
				cnt[8]++;
				used[i] = 1;
			} 
		}
		
		for (int i=0;i<10;i++){
			for (int j=0;j<cnt[i];j++){
				for (int ii=1;ii<(int)a[i].length();ii++){
					for (int k=0;k<(int)s.length();k++){
						if (!used[k] && s[k] == a[i][ii]){
							used[k] = 1;
							break;
						}
					}
				}
			}
		}
		
		for (int i=0;i<(int)s.length();i++){
			if (!used[i] && s[i] == 'O'){
				cnt[1]++;
				used[i] = 1;
			}
		}
		
		for (int i=0;i<cnt[1];i++){
			for (int ii=1;ii<(int)a[1].length();ii++){
				for (int k=0;k<(int)s.length();k++){
					if (!used[k] && s[k] == a[1][ii]){
						used[k] = 1;
						break;
					}
				}
			}
		}
		
		for (int i=0;i<(int)s.length();i++){
			if (!used[i] && s[i] == 'F'){
				used[i] = 1;
				cnt[5]++;
			}
		}
		
		for (int i=0;i<cnt[5];i++){
			for (int ii=1;ii<(int)a[5].length();ii++){
				for (int k=0;k<(int)s.length();k++){
					if (!used[k] && s[k] == a[5][ii]){
						used[k] = 1;
						break;
					}
				}
			}
		}
		
		for (int i=0;i<(int)s.length();i++){
			if (!used[i] && s[i] == 'S'){
				cnt[7]++;
				used[i] = 1;
			}
		}
		
		for (int i=0;i<cnt[7];i++){
			for (int ii=1;ii<(int)a[7].length();ii++){
				for (int k=0;k<(int)s.length();k++){
					if (!used[k] && s[k] == a[7][ii]){
						used[k] = 1;
						break;
					}
				}
			}
		}
		
		for (int i=0;i<(int)s.length();i++){
			if (!used[i] && s[i] == 'H'){
				cnt[3]++;
				used[i] = 1;
			}
		}
		
		for (int i=0;i<cnt[3];i++){
			for (int ii=1;ii<(int)a[3].length();ii++){
				for (int k=0;k<(int)s.length();k++){
					if (!used[k] && s[k] == a[3][ii]){
						used[k] = 1;
						break;
					}
				}
			}
		}
		
		int noused = 0;
		for (int i=0;i<(int)s.length();i++){
			if (!used[i]){
				noused++;
			}
		}
		
		cnt[9] = noused / 4;
		
		printf("Case #%d: ", Test);
		
		for (int i=0;i<10;i++){
			for (int j=0;j<cnt[i];j++){
				cout << i;
			}
		}
		cout << endl;
		
	}
				
    rt 0;
}
