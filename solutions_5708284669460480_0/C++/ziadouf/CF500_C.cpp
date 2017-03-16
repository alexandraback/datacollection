#include <stdio.h>
#include <functional>
#include <bitset>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <stack>
#include <string.h>
#include <numeric>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long ll;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define INF 1<<20
#define EPS 1e-5


int Z[100010];

void ZFunction(string &s)
{
	int N = sz(s);
    int L = 0, R = 0;
    Z[0] = N;
    for (int i = 1; i < N; i++) {
      if (i > R) {
        L = R = i;
        while (R < N && s[R-L] == s[R]) R++;
        Z[i] = R-L; R--;
      } else {
        int k = i-L;
        if (Z[k] < R-i+1) Z[i] = Z[k];
        else {
          L = i;
          while (R < N && s[R-L] == s[R]) R++;
          Z[i] = R-L; R--;
        }
      }
    }
}

int cntMatch (string &T , string &P)
{
	string str = P;
	str += "*";
	str += T;
//	for (int i=0 ; i<sz(str) ; i++) Z[i] = 0;
	ZFunction(str);
	int ret = 0;
	for (int i=sz(P) ; i<sz(str) ; i++)
	{
		if (Z[i] == sz(P)) ret++;
	}
//	cout << str << " " << ret << endl;
	return ret;
}

string word,target;
int K,L,S;
int totalCnt , occ;
int MaxNo;

void backtrack (string s)
{
	if (sz(s) == S)
	{
		int ans = cntMatch(s,target);
		totalCnt += ans;
		MaxNo = max(MaxNo , ans);
		occ++;
		return;
	}
	for (int i=0 ; i<sz(word) ; i++)
	{
		string tmp = s;
		tmp += word[i];
		backtrack(tmp);
	}
	return;
}
int main() {

	freopen("txt.in", "r", stdin);
//	freopen("txt.out", "w", stdout);

	int TC;
	cin >> TC;
	int CC = 1;
	while (TC--) {
		cin >> K >> L >> S;
		cin >> word >> target;
		totalCnt = occ = MaxNo = 0;
//		int n = sz(word);
//		ll cnt = 0;
//		for (int i=1; i<(1<<n) ; i++)
//		{
//			string s;
//			for (int j=0 ; j<n ; j++)
//			{
//				if ((i&(1<<j)) != 0) s += word[j];
//
//			}
//			string org = s;
//
//			cout << org << endl;
//			cnt += cntMatch(target,s);
//		}
		string s = "";
		backtrack(s);
		printf("Case #%d: ", CC++);
		printf("%.7lf\n",MaxNo - (totalCnt*1.0 / occ));
	}
}
