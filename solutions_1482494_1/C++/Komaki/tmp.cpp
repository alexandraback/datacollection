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

#define MAX 1005
pair<li,li> a[MAX];
li used[MAX];

int main()
{
	li T;
	cin >> T;
	rep(turn, T){
		memset(used, false, sizeof(used));
		li n;
		cin >> n;
		rep(i, n) cin >> a[i].S >> a[i].F;
		sort(a, a + n);
		
		li res = 0;
		li star = 0;
		li pos = 0;
		while(pos < n){
			res++;
			if(a[pos].F <= star){
				if(used[pos]) star += 1;
				else star += 2;
				used[pos++] = true;
			}else{
				li target = n - 1;
				for(;0 <= target; target--){
					if(!used[target] && a[target].S <=star){
						break;
					}
				}
				if(target == -1) break;
				used[target] = true;
				star += 1;
			}
		}
		printf("Case #%lld: ", turn + 1);
		if(pos < n) cout << "Too Bad"<<endl;
		else cout << res << endl;
	}
}
