// IN THE NAME OF GOD

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long int lld;
typedef long double ldb;

#define all(c) c.begin(),c.end()
#define tr(c,it) for(__typeof(c.begin()) it; it!=c.end(); it++)

#define ff ifstream cin; ofstream cout; cout.open("out.txt");

// Aditya Jain

int main(){
	ff
	cin.open("A-large.in");
	string str;
	int t, j=0;
	cin >> t;
	while(t--){
		j++;
		cin >> str;
		string ans;
		ans = ans + str[0];
		for(int i=1; i<str.length();i++){
			if(str[i]>=ans[0]){
				ans = str[i] + ans;
			}
			else ans = ans + str[i];
		}
		cout << "Case #" << j << ": ";
		cout << ans << endl;
	}
}
