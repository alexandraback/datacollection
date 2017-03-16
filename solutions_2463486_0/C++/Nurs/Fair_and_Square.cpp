#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;
vector <long long> v;
bool check(long long x){
long long y=0, z=x;
while (x){
	y*=10ll;
	y+=x%10ll;
	x/=10ll;
}
if (y==z)
	return 1;
	return 0;
}
int main(){
int i, t, ans;
long long l, r, k;
cin>>t;
for (k=1ll; k<10000000ll; ++k){
if (check(k) && check(k*k))
	v.push_back(k*k);
}
for (i=1; i<=t; ++i){
cin>>l>>r;
ans=upper_bound(v.begin(), v.end(), r)-lower_bound(v.begin(), v.end(), l);
printf("Case #%i: %i\n", i, ans);
}
return 0;
}