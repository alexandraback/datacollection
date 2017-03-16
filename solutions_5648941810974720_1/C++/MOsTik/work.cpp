#include<iostream>
#include<fstream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;
#ifdef Nameless
#define FILES freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#else
#define FILES //freopen("input.txt","r",stdin); freopen("output.txt","r",stdin);
#endif

typedef long long Long;
typedef long double Double;

#define left awefawef



int w[11];
int num[26];


const char* qq[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
string Q[10];
int letters[10][26];

int left;
string s;

bool found;
void rec(int d)
{
	if (d>0 && num['Z'-'A'] != 0)
		return;
	if (d>2 && num['W'-'A'] != 0)
		return;
	if (d>4 && num['R'-'A'] != 0)
			return;
	if (d>5 && num['F'-'A'] != 0)
			return;
	if (d>6 && num['X'-'A'] != 0)
				return;
	if (d>7 && num['V'-'A'] != 0)
					return;
	if (d>8 && num['G'-'A'] != 0)
					return;



	if (found)
		return;
	if (d==10) {

		if (left>0)
			return;
		for (int i = 0; i < 26; ++i) {
			if (num[i] != 0)
				return;
		}
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < w[i]; ++j) {
				cout << i;
			}
		}
		cout << endl;
		found = true;
		return;
	}



	for (int i = 0;; ++i) {
		if (Q[d].length()*i>left) {
			break;
		}
		bool ok = true;
		for (int j = 0; j < 26; ++j) {
			num[j] -= letters[d][j]*i;
			if (num[j] <0)
				ok = false;
		}
/*
		cout << d << " " << i << endl;
		for (int i = 0 ;i < 26; ++i) {
			cout << num[i] << " ";
		}
		cout << endl;
		cout << endl;
*/
		w[d] = i;
		left -= Q[d].length()*i;
		if (ok) {
			rec(d+1);

		}
		left += Q[d].length()*i;
		for (int j = 0; j < 26; ++j) {
			num[j] += letters[d][j]*i;
		}
	}
}

void solve(int test = 0)
{
	cout << "Case #" << test+1  << ": ";

	cin >> s;
	left = s.length();
	memset(num,0,sizeof num);
	for (int i = 0; i < s.length(); ++i) {
		num[s[i]-'A']++;
	}
	found = false;
	rec(0);
}

int main(){
    FILES;
    cin.tie(0);
    ios_base::sync_with_stdio(0);
//    solve();
    int test;
    cin >> test;

    for (int i = 0; i < 10; ++i) {
    	Q[i] = string(qq[i]);

    }
    for (int i = 0; i< 10; ++i) {
    	for (int j = 0;j < Q[i].length(); ++j) {
    		letters[i][Q[i][j]-'A']++;
    	}
    }
    for (int i = 0; i < test; ++i) {
        solve(i);
    }
    return 0;
}
