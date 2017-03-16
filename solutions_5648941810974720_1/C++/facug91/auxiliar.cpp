/*
	By: facug91
	From: 
	Name: 
	Date: 30/04/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define next sbjkdfh329re9fdshfd98fyh
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
#define MOD 1000000000ll
#define MAXN 100000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

string s;
string numbers[] = {"ZERO", "TWO", "SIX", "SEVEN", "FIVE", "FOUR", "THREE", "ONE", "EIGHT", "NINE"};
int numbersInt[] = {0, 2, 6, 7, 5, 4, 3, 1, 8, 9}, c[300];
vi ans;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		memset(c, 0, sizeof c);
		cin>>s;
		for (i=0; i<s.length(); i++) c[s[i]]++;
		ans.clear();
		for (i=0; i<=9; i++) {
			int mini = INT_MAX;
			for (j=0; j<numbers[i].length(); j++) {
				if ((i == 3 || i == 6) && numbers[i][j] == 'E') mini = min(mini, c[numbers[i][j]]/2);
				else if (i == 9 && numbers[i][j] == 'N') mini = min(mini, c[numbers[i][j]]/2);
				else mini = min(mini, c[numbers[i][j]]);
			}
			//cerr<<"i "<<i<<" mini "<<mini<<endl;
			for (j=0; j<mini; j++) ans.push_back(numbersInt[i]);
			for (j=0; j<numbers[i].length(); j++) c[numbers[i][j]] -= mini;
		}
		sort(ans.begin(), ans.end());
		cout<<"Case #"<<it<<": ";
		for (i=0; i<ans.size(); i++) cout<<ans[i];
		cout<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
