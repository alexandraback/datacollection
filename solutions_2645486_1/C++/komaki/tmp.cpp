#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <bitset>
#include <complex>
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

#define MAX 10050
li a[MAX];
li e, r, n;

li recur(li pos, li rem)
{
	if(pos == n) return 0;
	rem = min(rem, e);
	
	li ans = 0;
	for(li use = 0; use <= rem; use++){
		ans = max(ans, a[pos] * use + recur(pos + 1, rem - use + r));
	}
	return ans;
}

int main()
{
	li T;
	cin >> T;
	rep(step, T){
	
		cin >> e >> r >> n;
		rep(i, n) cin >> a[i];
		
		vector<pair<li, li> > V;
		rep(i, n) V.pb(MP(a[i], i));
		sort(all(V));
		reverse(all(V));
		
		li sizes[MAX];
		li used[MAX];
		
		rep(i, n) sizes[i] = i == 0 ? e : r;
		rep(i, n) used[i] = 0;
		
		long long int ans = 0;
		rep(i, n){
			li pos = V[i].S;
			li queue_size = 0;

			for(li t = pos; 0 <= t; t--){
				li enqueue_size = min(e - queue_size, sizes[t]);
				li usable = max((li)0, enqueue_size - used[t]);
				used[t] += usable;
				ans += (long long int)usable * a[pos];
				queue_size += enqueue_size;
				if(e <= queue_size) break;
			}
			
		}
		
		cout << "Case #" << step + 1 << ": " << ans << endl;
		//cout << recur(0, e) - ans << endl;
	}
}






