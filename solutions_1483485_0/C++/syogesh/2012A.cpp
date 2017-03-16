#include <vector>
#include <list>
#include <map>
#include <set>
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

using namespace std;

#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define ll long long int
#define ii pair<int,int>
#define CLEAR(x,val) memset(x,val,sizeof(x))
#define SZ(v) (v).size()


char a[26] = { 'y' , 'h' , 'e' , 's' , 'o' , 'c' , 'v' , 'x' , 'd' , 'u' , 'i' , 'g' , 'l' , 'b' , 'k' , 'r' , 'z' , 't' , 'n' , 'w' , 'j' , 'p' , 'f' , 'm' , 'a' , 'q' };
int main()
{
	int testcase; scanf("%d" , &testcase) ;	
	
	cin.ignore();
	for( int cs = 1; cs <= testcase; cs++ ) {
		string s;getline(cin , s);
		int sz = s.size();
		char ans[sz];
		for( int i = 0; i < sz; i++ ) {
			if( s[i] != ' ') ans[i] = a[s[i]-'a'];
			else ans[i] = ' ';
		}
		cout << "Case #" << cs << ": ";
		rep( i , 0 , sz ) cout << ans[i];
		cout << "\n";
	}
	return 0;
}
