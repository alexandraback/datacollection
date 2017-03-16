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
#define rep(i,to) for(int i=0;i<((int)(to));++i)
#define pb        push_back
#define sz(v)     ((int)(v).size())
#define bit(n)    (1ll<<(li)(n))
#define all(vec)  (vec).begin(),(vec).end()
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define MP        make_pair
#define F         first
#define S         second


#define MAX 105
li a[MAX];

int main(){
	li T;
	cin>>T;
	rep(play_turn, T){
		li n,s,p;
		cin>>n>>s>>p;
		rep(i,n) cin>>a[i];
		sort(a,a+n);
		reverse(a,a+n);
		li res=0;
		cerr<<s<<" "<<p<<endl;
		rep(i,n){
			li i0 = a[i] / 3;
			a[i] -= i0;
			li i1 = a[i] / 2;
			a[i] -= i1;
			li i2 = a[i];
			cerr<<i0<<" "<<i1<<" "<<i2<<endl;
			if(p <= i2){
				res++;
			}else if(p <= i2 + 1 && 1 <= s && i1 == i2 && 0 < i2){
				res++;
				s -= 1;
			}
		}
			cerr<<res<<endl<<endl;
		cout<<"Case #"<<play_turn+1<<": "<<res<<endl;
	}
}
