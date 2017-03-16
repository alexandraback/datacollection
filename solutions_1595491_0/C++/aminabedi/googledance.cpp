//VERDICT:

#include<iostream>
#include<algorithm>
#include<cstring>
//#include<cstdlib>
#include<vector>
//#include<cstdio>
//#include<iomanip>
//#include<map>
//#include<set>
#include<queue>
//#include<deque>
//#include<utility>
#include<cmath>
#define pb push_back
#define mkp make_pair
#define foR(i,j,n) for(int i=j;i<n;i++)
#define error(x) cerr<<#x<<"="<<x<<endl;
#define stf(x) st.find(x)!=st.end()
#define X first
#define Y second
#define pii pair<int,int>
typedef long long ll;
using namespace std;
const int maxn=1000000,inf=1000000000,mod=1000003;
int main(){
	int t,n,s,p;
	cin>>t;
	foR(i,0,t){
		cin>>n>>s>>p;
		int ans=0,t,x=0;
		foR(j,0,n){
			cin>>t;
			if(t>=3*p-2)
				ans++;
			else if(t>=3*p-4&&t)
				x++;
		}
		ans+=min(s,x);
		cout<<"Case #"<<i+1<<": "<<ans<<endl;
	}	
	return 0;
}
