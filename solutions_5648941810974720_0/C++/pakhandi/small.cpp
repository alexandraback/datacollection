//Author : pakhandi
//
using namespace std;

#include<bits/stdc++.h>

#define wl(n) while(n--)
#define fl(i,a,b) for(i=a; i<b; i++)
#define rev(i,a,b) for(i=a; i>=b; i--)

#define si(n) scanf("%d", &n)
#define sll(l) scanf("%lld",&l)
#define ss(s) scanf("%s", s)
#define sc(c) scanf("%c", &c)
#define sd(f) scanf("%lf", &f)

#define pi(n) printf("%d\n", n)
#define pll(l) printf("%lld\n", l)
#define ps(s) printf("%s\n", s)
#define pc(c) printf("%c\n", c)
#define pd(f) printf("%lf\n", f)

#define debug(x) cout<<"\n#("<<x<<")#\n"
#define nline printf("\n")

#define mem(a,i) memset(a,i,sizeof(a))

#define MOD 1000000007
#define ll long long int
#define u64 unsigned long long int

#define mclr(strn) strn.clear()
#define ignr cin.ignore()
#define PB push_back
#define SZ size
#define MP make_pair
#define fi first
#define sec second

int main()
{
	int i, j;

	int cases;
	int caseNo = 1;

	cin>>cases;

	wl(cases)
	{
		string s;
		cin>>s;
		ll n = s.size();

		map<char, int> mp;
		fl(i,0,n)
			mp[s[i]] ++;

		string ans = "";
		while( mp.find('Z') != mp.end() && (mp['Z'] != 0) ) {
			ans += '0';
			mp['Z']--;
			mp['E']--;
			mp['R']--;
			mp['O']--;
		}
		
		while( mp.find('X') != mp.end() && (mp['X'] != 0) ) {
			ans += '6';
			mp['S']--;
			mp['I']--;
			mp['X']--;
		}

		while( mp.find('W') != mp.end() && (mp['W'] != 0) ) {
			ans += '2';
			mp['T']--;
			mp['W']--;
			mp['O']--;
		}

		while( mp.find('G') != mp.end() && (mp['G'] != 0) ) {
			ans += '8';
			mp['E']--;
			mp['I']--;
			mp['G']--;
			mp['H']--;
			mp['T']--;
		}

		while( mp.find('U') != mp.end() && (mp['U'] != 0) ) {
			ans += '4';
			mp['F']--;
			mp['O']--;
			mp['U']--;
			mp['R']--;
		}

		while( mp.find('T') != mp.end() && (mp['T'] != 0) ) {
			ans += '3';
			mp['T']--;
			mp['H']--;
			mp['R']--;
			mp['E']--;
			mp['E']--;
		}

		
		while( mp.find('F') != mp.end() && (mp['F'] != 0) ) {
			ans += '5';
			mp['F']--;
			mp['I']--;
			mp['V']--;
			mp['E']--;
		}


		while( mp.find('O') != mp.end() && (mp['O'] != 0) ) {
			ans += '1';
			mp['O']--;
			mp['N']--;
			mp['E']--;
		}

		while( mp.find('S') != mp.end() && (mp['S'] != 0) ) {
			ans += '7';
			mp['S']--;
			mp['E']--;
			mp['V']--;
			mp['E']--;
			mp['N']--;
		}
		
		while( mp.find('I') != mp.end() && (mp['I'] != 0) ) {
			ans += '9';
			mp['N']--;
			mp['I']--;
			mp['N']--;
			mp['E']--;
		}


		sort(ans.begin(), ans.end());
		cout<<"Case #"<<caseNo<<": ";
		caseNo++;
		cout<<ans;
		nline;
	}


	return 0;
}
/*
	Powered by Buggy Plugin
*/