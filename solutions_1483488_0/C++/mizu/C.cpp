#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
#include <stdio.h>
#include <strstream>
using namespace std;

typedef long long LL;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int> > vii;
typedef vector<vector<string> > vss;
typedef pair<int, int> pii;
#define x first
#define y second
#define INF 0x7fffffff
//#define INFLL 0x7fffffffffffffff
#define INFLL LLONG_MAX
#define SIZE(v) int((v).size())
#define ALL(v) (v).begin(), (v).end()
#define FOR(i,x) for(int i=0;i<x;i++)
#define FORic(i,y,x) for(int i=y;i<=x;i++)
#define FORdc(i,y,x) for(int i=y;i>=x;i--)
#define FILL(a,v) memset(a, v, sizeof(a))
#define PI 3.14159265358979323846

int num_recycled(int n, int B, int bai)
{
	int ans = 0;
	int original = n;
	while(1){
		int hitoketa = n%10;
		n /= 10;
		n += bai*hitoketa;
		if(n==original) break;
		if(original < n && n <= B){
			ans++;
		}
	}
	return ans;
}

int main()
{
	char buf[256*8];
	int T;
	gets(buf);
	string sb = buf;
	istrstream istr(sb.data());
	istr >> T;
	FOR(ttt,T){
		gets(buf);
		sb = buf;
		istrstream cins(sb.data());
		int A;
		int B;
		cins>>A>>B;
		int ib = B;
		int keta = 0;
		while(ib){
			ib /= 10;
			keta++;
		}
		int bai = 1;
		FOR(i,keta){
			bai *= 10;
		}
		bai /= 10;
		int ans = 0;
		FORic(i, A, B){
			ans += num_recycled(i, B, bai);
		}

		printf("Case #%d: %d\n", ttt+1, ans);
	}
}
