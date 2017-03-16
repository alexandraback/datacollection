#include<bits/stdc++.h>
#define author rajat1603
#define pb push_back
#define mp make_pair
using namespace std;
const int mod = 1e9 + 7;
int t,n,m,s;
string a,b;
int total=0;
int maxi=0;
vector<string> v;
void solve(int left,string ans){
	if(left<0){
		return ;
	}
	if(left==0){
		v.pb(ans);
		return ;
	}
	for(int i=0;i<n;++i){
		string temp = ans;
		temp+=a[i];
		solve(left-1,temp);
	}
}
void solve2(){
	int x = v.size();
	while(x--){
		string temp = v[x];
		//cout<<temp<<" ";
		int coun = 0;
		for(int i=0;i<temp.size();++i){
			bool bb = 0;
			for(int j=0;j<m;++j){
				if(i+j>=temp.size()||temp[i+j]!=b[j]){
					bb=1;
					break;
				}
			}
			if(!bb){
				coun++;
			}
		}
		total+=coun;
		maxi = max(maxi , coun);
	}
}
int main(){
	cin>>t;
	int tc = 0;
	while(t--){
		printf("Case #%d: ",++tc);
		total = 0;
		maxi = 0;
		v.clear();
		cin>>n>>m>>s;
		cin>>a>>b;
		string ans="";
		solve(s,ans);
		solve2();
		if(total==0||v.size()==0||maxi==0){
			printf("0.0\n");
		}
		else{
			double temp = total;
			temp/=v.size();
			double ans = maxi;
			ans-=temp;
			printf("%lf\n",ans);
		}
	}
}
