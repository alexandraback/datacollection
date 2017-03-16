//VERDICT:

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<cmath>
#include<set>
#define pb push_back
#define foR(i,j,n) for(int i=j;i<n;i++)
typedef long long ll;
using namespace std;
const int maxn=1000000,inf=1000000000,mod=1000003;
set<pair<int,int> > st;
int main(){
	int t;
	cin>>t;
	foR(j,1,t+1){
		st.clear();
		int a,b,ans=0;
		scanf("%d%d",&a,&b);
		vector<int> v;
		foR(i,a,b+1){
			v.clear();
			int c=i;
			while(c){
				v.pb(c%10);
				c/=10;
			}
			reverse(v.begin(),v.end());
			foR(p,1,v.size()){
				c=0;
				foR(h,0,v.size()){
					c*=10;
					c+=v[(p+h)%v.size()];
				}
				if(c>=a&&c<=b&&c!=i){
					st.insert(make_pair(i,c));
				}
			}
		}
		ans=st.size()/2;
		printf("Case #%d: %d\n",j,ans);
	}
	return 0;
}
