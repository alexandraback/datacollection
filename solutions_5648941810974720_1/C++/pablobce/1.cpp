#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <cmath>
#include <set>
#include <algorithm>
#include <stack>
#include <stdio.h>
using namespace std;

#define forsn(i,s, n) for(int i=(int)s; i<(int)(n); i++)
#define forn(i, n) forsn(i,0,n)
#define fore(i,n) forn(i,n.size())
#define fori(i, n) for(typeof n.begin() i=n.begin(); i!=n.end();i++)
#define RAYA cout<<"-----------------"<<endl;
#define dbg(x) cout<<#x<<":"<<(x)<<endl;

typedef long long int tint;
typedef long double ldouble;
#define pii pair <int,int>

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(n) n.begin(),n.end()

const tint INF=2000000000;


int main(){
	int T;
	cin>>T;
	string s;
	forn(caso,T){
		vector<int> v ('Z'-'A'+1);
		cin>>s;
		fore(i,s)v[s[i]-'A']++;
		vector<int> res (10);
		res[0]= v['Z'-'A']; //"ZERO" contando las Z
		res[2]= v['W'-'A']; //"TWO" las W
		res[6]= v['X'-'A']; //"SIX" las X
		res[8]= v['G'-'A']; //"EIGHT" las G
		res[3]= v['H'-'A']-res[8]; //"THREE" las H (menos los 8)
		res[4]= v['R'-'A']-res[3]-res[0]; //"FOUR" las R (menos los 3 y 0)
		res[1]= v['O'-'A']-res[0]-res[2]-res[4]; //"ONE" las O menos 0,2,4
		res[5]= v['F'-'A']-res[4]; //"FIVE" las F menos 4
		res[7]= v['V'-'A']-res[5];//"SEVEN" las V menos 5
		res[9]= v['I'-'A'] -res[6]-res[8]-res[5]; //"NINE" las I menos 6,8,5
		cout<<"Case #"<<caso+1<<": ";
		forn(i,10)forn(j,res[i])cout<<i;
		cout<<endl;
	}
    return 0;
}
