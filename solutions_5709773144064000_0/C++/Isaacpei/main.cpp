#include <iostream>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;
typedef long long ll;
const double eps=1e-8;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	double c,f,x;
	int t;
	cin>>t;
	for(int cas=1;cas<=t;cas++) {
		cin>>c>>f>>x;
		double ans=x/2;
		double pre=2,ti=0;
		while(ti<ans){
			ti+=c/pre;
			pre+=f;
			ans=min(ans,ti+x/pre);
		}
		printf("Case #%d: %.7lf\n",cas,ans);
	}
    return 0;
}