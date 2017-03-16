#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <bitset>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <algorithm>
//#include <sys/time.h>
using namespace std;
#define li        long long int
#define rep(i,to) for(li i=0;i<((li)(to));++i)
#define pb        push_back
#define sz(v)     ((li)(v).size())
#define bit(n)    (1ll<<(li)(n))
#define all(vec)  (vec).begin(),(vec).end()
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define MP        make_pair
#define F         first
#define S         second

vector<li> base;

bool isGreater(vector<li> V)
{
	rep(i, sz(V))if(V[i] == -1) V[i] = 0;
	vector<li> sqr(sz(V) * 2 - 1, 0);
	if(sz(base) != sz(sqr)) return sz(base) < sz(V);
	rep(i, sz(V))rep(j, sz(V)) sqr[i + j] += V[i] * V[j];
	rep(i, sz(base))if(base[i] != sqr[i]) return base[i] < sqr[i];
	return false;
}

bool isSmaller(vector<li> V)
{
	rep(i, sz(V))if(V[i] == -1) V[i] = 10;
	vector<li> sqr(sz(V) * 2 - 1, 0);
	if(sz(base) != sz(sqr)) return sz(sqr) < sz(base);
	rep(i, sz(V))rep(j, sz(V)) sqr[i + j] += V[i] * V[j];
	rep(i, sz(base))if(base[i] != sqr[i]) return sqr[i] < base[i];
	return true;
}

li dp[100][2][11];

li recur(li rem, li middle, li sum)
{
	if(10 <= sum) return 0;
	if(rem == 0) return 1;
	li &res = dp[rem][middle][sum];
	if(res != -1) return res;
	res = 0;
	rep(num, 4) res += recur(rem - 1, middle, sum + num * num * (middle && rem == 1 ? 1 : 2));
	return res;
}

li cal(vector<li> V, li digit, li sum)
{
	if(isGreater(V)) return 0;
	if(isSmaller(V)) return recur((sz(V) + 1) / 2 - digit, sz(V) % 2, sum);
	if(sz(V) - 1 - digit < digit) return 0;
	
	li res = 0;
	rep(num, 4){
		V[digit] = V[sz(V) - 1 - digit] = num;
		res += cal(V, digit + 1, sum + num * num * (digit == sz(V) - 1 - digit ? 1 : 2));
	}
	return res;
}

li cal(li A)
{
	base.clear();
	for(; A; A /= 10) base.pb(A % 10);
	reverse(all(base));
	
	li sum = 0;
	for(li digit = 1; digit <= sz(base); digit++)rep(num, 4)if(num){
		vector<li> V(digit, -1);
		V[0] = V.back() = num;
		sum += cal(V, 1, num * num * (1 == sz(V) ? 1 : 2));
	}
	return sum;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	li T;
	cin >> T;
	
	rep(step, T){
		li A, B;
		cin >> A >> B;
		cout << "Case #" << step + 1 << ": " << cal(B) - cal(A - 1) << endl;
	}
}



