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
#include <sys/time.h>
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



#define MAX 2005000
vector<li> a[MAX];

int main(){
	rep(i,MAX)if(i){
		li tmp = i;
		li base = 1;
		for(;10 <= tmp;tmp /= 10) base *= 10;
		tmp = i;
		while(true){
			tmp = tmp % 10 * base + tmp / 10;
			if(tmp == i) break;
			if(i < tmp) a[i].pb(tmp);
		}
	}
	
	li T;
	cin>>T;
	rep(turn_play, T){
		li n, m;
		cin>>n>>m;
		li res = 0;
		for(li i = n; i <= m; i++){
			rep(j, sz(a[i]))if(a[i][j] <= m) res++;
		}
		cout<<"Case #"<<turn_play + 1<<": "<<res<<endl;
	}
}
