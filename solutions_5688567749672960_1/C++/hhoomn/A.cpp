#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <deque>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <sstream>

#define For(i,a,n) for(int i =a ; i < n ; ++i )
#define all(x) (x).begin(),(x).end()
#define n(x) (int)(x).size()
#define pb(x) push_back(x)
#define fr first
#define sc second

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll n,t;

ll po(ll x,ll y){
	ll r=1;
	For(i,0,y)
		r*=x;
	return r;
}
ll len(ll x){
	ll r = 0;
	while(x){
		r++;
		x/=10;
	}
	return r;
}
ll half1(ll x){
	ll ti=(len(x)+1)/2;
	For(i,0,ti)
		x/=10;
	return x;
}

ll half2(ll x){
	return x-half1(x)*po(10,(len(x)+1)/2);
}
ll sw(ll x){
	ll r=0;
	while(x){
		r=r*10+x%10;
		x/=10;
	}
	return r;
}
ll calc(ll x){
	if(x < 20)
		return x;
	if(x%10==0)
		return calc(x-1)+1;
	if(half1(x)==po(10,len(x)/2-1))
	{
		ll y = po(10,len(x)-1)-1;
		return calc(y)+x-y;
	}else{
		ll y = x-half2(x)+1;
		return calc(sw(y))+x-y+1;
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin >> t;
	For(i,0,t)
	{
		cin >> n;
		cout << "Case #" << i+1 << ": " <<  calc(n) << endl;
	}
	return 0;
}

//
// el psy congroo
//

