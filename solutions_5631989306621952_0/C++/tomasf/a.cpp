#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef vector<bool> vb;

int main(void) {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		string s;
		cin >> s;
		string cur;
		cur.pb(s[0]);
		for(int i = 1; i < s.size(); i++){
			string s1, s2;
			s1 = cur;
			s1 += s[i];
			s2 += s[i];
			s2 += cur;
			if(s1 > s2){
				cur = s1;
			}else{
				cur = s2;
			}
		}
		cout << "Case #" << t << ": " << cur << endl;
	}	
	
	return 0;
}
