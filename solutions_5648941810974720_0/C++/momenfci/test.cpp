#include <bits/stdc++.h>
using namespace std;

#define sz(v)			(int)(v.size())
#define all(v)			v.begin(),v.end()
#define mems(a , i)		memset(a , i , sizeof(a))
#define memc(a , b)		memcpy(a , b , sizeof(a))
#define mp(x , y)		make_pair(x , y)
#define pb(x)			push_back(x)
#define ansy			{cout << "-1" << endl;return 0;}
#define ansn			{cout << "No" << endl;return 0;}
#define IOS				ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define mod				1000000007
#define PI				3.14159265358979323846
#define fi				first
#define se				second
const double EPS = 1e-8;

int cnt[30];
pair < pair <char , int> , string > ma[10];
void fun(){
	ma[0].fi.fi = '0' , ma[0].fi.se = 'Z' , ma[0].se = "ZERO";
	ma[1].fi.fi = '2' , ma[1].fi.se = 'W' , ma[1].se = "TWO";
	ma[2].fi.fi = '8' , ma[2].fi.se = 'G' , ma[2].se = "EIGHT";
	ma[3].fi.fi = '6' , ma[3].fi.se = 'X' , ma[3].se = "SIX";
	ma[4].fi.fi = '7' , ma[4].fi.se = 'S' , ma[4].se = "SEVEN";
	ma[5].fi.fi = '5' , ma[5].fi.se = 'V' , ma[5].se = "FIVE";
	ma[6].fi.fi = '4' , ma[6].fi.se = 'U' , ma[6].se = "FOUR";
	ma[7].fi.fi = '3' , ma[7].fi.se = 'R' , ma[7].se = "THREE";
	ma[8].fi.fi = '1' , ma[8].fi.se = 'O' , ma[8].se = "ONE";
	ma[9].fi.fi = '9' , ma[9].fi.se = 'N' , ma[9].se = "NINE";
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/momen/Downloads/A-small-attempt0.in", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	IOS;
	fun();
	int T;
	cin >> T;
	string s;
	for(int t = 1 ; t <= T ; t++){
		mems(cnt , 0);
		cin >> s;
		for(int i = 0 ; i < sz(s) ; i++)
			cnt[(s[i] - 'A')]++;
		s = "";
		for(int i = 0;i <= 9 ; i++){
			int c = ma[i].fi.se - 'A';
			while(cnt[c] > 0){
				string ss = ma[i].se;
				for(int j = 0;  j < sz(ss) ; j++){
					cnt[(ss[j] - 'A')]--;
				}
				s += ma[i].fi.fi;
			}
		}
		sort(s.begin() , s.end());
		cout << "Case #" << t << ": " << s << endl;
	}
	return 0;
}
