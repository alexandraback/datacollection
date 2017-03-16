/*SampleInput
3
1 1 1
1 7 7 
2 5 1
*/
#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
#define mins(a,b,c) ((a<b)? (a<c?a:c) : (b<c?b:c));
#define loop(i,n) for(i=0;i<n;i++)
#define TEST(t) int t; cin>>t; while(t--)
#define CJTEST(t) int t, z; cin>>t; for(z=1;z<=t;z++)
#define ll long long	
int main(){
	fio;
	freopen("in", "r", stdin);
	freopen("out.out", "w", stdout);
	CJTEST(t){
		ll r,c,w; cin>>r>>c>>w;
		cout<<"Case #"<<z<<": "<<((c/w)*r + w-1 + ((c%w)!=0))<<endl;
	}
	return 0;
}
