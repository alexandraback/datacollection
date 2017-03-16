#include <cstdio>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <queue>
#include <cstring>
#include <iomanip>
#include <deque>
#include <stack>
#include <map>
#include <set>

#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef pair<int, int> P2;
typedef pair<ll, ll> P2l;

#define INF 1000000

int main()
{
	int debug = 0;
	if(debug){
		//freopen("out_1.txt", "r", stdin);
		//srand((int)time(NULL));
		return 0;
	}
	
	freopen("A-small-attempt0.in", "r", stdin);//test.txt
	freopen("out.txt", "w", stdout);

	int T; cin>>T;
	forn(i,T) {
		string s; cin>>s;
		int nm[26];
		int ans[10];
		string tt[10]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
		char mc[10] ={'Z','W','U','X', 'G','O', 'T', 'F', 'S', 'I'};
		int mt[10]={0,2,4,6,8,1,3,5,7,9};
		forn(j,26) nm[j]=0;
		forn(j,10) ans[j]=0;
		forn(j,s.size()) nm[s[j]-'A']++;

		forn(j, 10){
			int t=nm[mc[j]-'A'];
			int ti=mt[j];
			if(t) { ans[ti]+=t; forn(z, tt[ti].size()) nm[tt[ti][z]-'A']-=t;}
		}
 
		cout<<"Case #"<<i+1<<": ";
		forn(j,10) forn(z,ans[j]) cout<<j;
		cout<<endl;
	}

	return 0;
}


