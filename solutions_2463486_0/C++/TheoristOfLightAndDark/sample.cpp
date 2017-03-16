#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;
 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define fill(a,v) memset(a, v, sizeof a)
#define INF (int)1e9
#define EPS	1e-9

typedef long long LL;
typedef vector<long long> vll;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

#define ONLINE_JUDGE 1

vector<long long int> pal;
vector<long long int> final;

void check_pal(long long int num){
	if(num!=0){
		while(num%10==0)
			num /= 10;
		pal.push_back(num);
	}
}

bool isPal(long long int n){
	long long int rev = 0;
	long long int cp = n;
	while(cp!=0){
		rev = rev*10+cp%10;
		cp /= 10;
	}
	if(n==rev)
		return true;
	return false;
}

#ifndef ONLINE_JUDGE
	#define fout output_string
	#define fin input_string
	#define MULTILINE(...) #__VA_ARGS__
#endif

int main() {
#ifdef ONLINE_JUDGE
    ofstream fout("C:\\Users\\Karan\\Downloads\\out");
    ifstream fin("C:\\Users\\Karan\\Downloads\\B");
#endif

#ifndef ONLINE_JUDGE
	stringstream input_string;
	stringstream output_string;
	stringstream correct_output_string;
	input_string << MULTILINE(3
1 4
10 120
100 1000);
	correct_output_string << MULTILINE(1);
#endif

	// Code starts here...
	//Even-len pal
	REP(i,10)
		REP(j,10)
			REP(k,10)
				REP(l,10)
					check_pal(i*10000001+j*1000010+k*100100+l*11000);
	//Odd-len pal
	REP(i,10)
		REP(j,10)
			REP(k,10)
				REP(l,10)
					check_pal(i*1000001+j*100010+k*10100+l*1000);
	sort(all(pal));

	for(int i=0;i<pal.size();i++)
		if(isPal(pal[i]*pal[i]))
			final.pb(pal[i]*pal[i]);

	int t;
	long long int a,b;
	fin >> t;
	REP(i,t){
		fin >> a >> b;
		int count = 0;
		REP(j,final.size())
			if(final[j]>=a && final[j]<=b)
				count++;
		fout << "Case #" << i+1 << ": " << count << endl;
	}

#ifndef ONLINE_JUDGE
	printf("\nYOUR OUTPUT:\n");
	printf("%s",output_string.str().c_str());
	printf("\nCORRECT OUTPUT:\n");
	printf("%s\n\n",correct_output_string.str().c_str());
	getchar();
#endif

    return 0;
}