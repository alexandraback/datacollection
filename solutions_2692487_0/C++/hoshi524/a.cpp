#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <cassert>
using namespace std;
static const double EPS = 1e-9;
typedef long long ll;

int m[111];
int main() {
	// freopen ("input.txt", "r", stdin);
	// freopen ("output.txt", "w", stdout);

	int a,n,t;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>a>>n;
		for(int j=0;j<n;j++){
			cin>>m[j];
		}
		if(a==1){
			cout<<"Case #"<<(i+1)<<": "<<n<<endl;
			continue;
		}
		sort(m,m+n);
		int ans=n,z=0;
		for(int j=0;j<n;j++){
			ans=min(ans,z+n-j);
			while(a<=m[j]){
				z++;
				a+=a-1;
			}
			a+=m[j];
		}
		ans=min(ans,z);
		cout<<"Case #"<<(i+1)<<": "<<ans<<endl;
	}
}