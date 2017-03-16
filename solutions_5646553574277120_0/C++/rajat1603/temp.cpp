#include<bits/stdc++.h>
#define author rajat1603
#define pb push_back
#define mp make_pair
using namespace std;
const int mod = 1e9 + 7;
int main(){
	int t;
	cin>>t;
	int tc = 0;
	while(t--){
		printf("Case #%d: ",++tc);
		int c,d,v;
		cin>>c>>d>>v;
		bool val[31]={0};
		bool mark[31]={0};
		vector<int> lol;
		while(d--){
			int temp;
			cin>>temp;
			mark[temp]=1;
			lol.pb(temp);
		}
		int n = lol.size();
		int p = 1<<n;
		for(int i=0;i<p;++i){
			int temp = i;
			int x = 0;
			int sum = 0;
			while(temp){
				if(temp&1){
					sum+=lol[x];
				}
				x++;
				temp>>=1;
			}
			if(sum<=v){
				val[sum]=1;
			}
		}
		int ans = 0;
		for(int i=1;i<=v;++i){
			if(!val[i]){
				ans++;
				vector<int> xx;
				for(int j=0;j<=v;++j){
					if(val[j]&&i+j<=v){
						xx.pb(j+i);
					}
				}
				for(int ii=0;ii<xx.size();++ii){
					val[xx[ii]]=1;
				}
			}
		}
		printf("%d\n",ans);
	}
}
