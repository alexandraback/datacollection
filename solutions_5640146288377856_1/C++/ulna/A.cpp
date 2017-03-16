#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <deque>
#include <vector>
#include <map>
#include <cmath>
#include <cstdlib>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <climits>
#include <ctype.h>
#include <utility>
using namespace std;

#define ft first
#define sd second
#define pb push_back
#define endl '\n'
#define cpy(a,e) memcpy(a,e,sizeof(e))
#define clr(a,e) memset(a,e,sizeof(a))
#define rep(i,n) for (int (i)=0;(i)<(n);i++)
#define repd(i,n) for (int (i)=(n)-1;(i)>=0;i--)
#define reps(i,s,e) for (int (i)=(s);(i)<=(e);i++)
#define repds(i,s,e) for (int (i)=(s);(i)>=(e);i--)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin;ofstream fout;
	fin.open("in.txt");fout.open("out.txt");
	int t;
	fin >> t;
	long long r,c,w;
	rep(i,t) {
		fin >> r >> c >> w;
		long long temp=r-1,ans=0;
		if (temp>=1) {
			ans+=c/w*temp;
		}
		long long p=0;
		while(p+w<=c) p+=w,ans++;
		long long left=c-p;
		if (left>=1) {
			ans++;
		}
		ans+=w-1;
		fout << "Case #" << i+1 << ": " << ans << endl; 
	}
	return 0;
}

