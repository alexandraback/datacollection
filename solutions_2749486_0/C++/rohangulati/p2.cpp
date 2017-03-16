/*
ID: rohangu1
LANG: C++
TASK: 
*/

#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <cstdio>
#include <iterator>

using namespace std;

typedef vector<int> vi;
typedef vector< vi > vvi;
typedef pair<int,int> ii;
typedef long long LL;

#define FOR(i,a,b) for(i=a;i<=b;i++)
#define FORr(i,a,b) for(i=a;i>=b;i--)
#define tr(c, it) \
		for(typeof(c.begin()) it = c.begin() ; it != c.end() ; it++)
#define max(a,b) (a>b?(a):(b))
#define min(a,b) (a>b?(b):(a))
#define all(a) (a).begin(),(a).end()
#define mp(i,j) make_pair(i,j)
#define sz(a) a.size()
#define pb(i) push_back(i) 
#define lb(i) lower_bound(i)
#define ub(i) upper_bound(i)
#define bs(i) binary_search(i)
#define fx first
#define sx second
#define MOD 1000000007

int gcd(int x, int y)
{
    while (y > 0) {
        int z = y;
        y = x % y;
        x = z;
    }
    return x;
}

ifstream in("p2.in",ifstream::in);
ofstream out("p2.out",ios::out);

// cout<<"Case #"<<c<<": "<<ans<<endl;

char ans[510];
char tmp[5];

int main(){
	int i,j,x,y,c;
	int cases;
	in>>cases;
	FOR(c,1,cases){
		in>>x>>y;
		if(x>0){
			tmp[1] = 'W';
			tmp[2] = 'E';
		}
		else{
			tmp[1] = 'E';
			tmp[2] = 'W';
		}
		if(y>0){
			tmp[3] = 'S';
			tmp[4] = 'N';
		}
		else{
			tmp[3] = 'N';
			tmp[4] = 'S';
		}
		j = 0;
		FOR(i,1,abs(x)){
			ans[++j] = tmp[1];//'W';
			ans[++j] = tmp[2];//'E';
		}
		FOR(i,1,abs(y)){
			ans[++j] = tmp[3];//'S';
			ans[++j] = tmp[4];//'N';
		}
		ans[j+1] = '\0';
		out<<"Case #"<<c<<": "<<ans+1<<endl;
	}
	return 0;
}
