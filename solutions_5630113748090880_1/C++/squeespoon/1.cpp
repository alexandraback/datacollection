#include <bits/stdc++.h>
using namespace std;


#define ll long long 

bool cnt[2555];

int main(){
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int t;
	cin>>t;
	int cas = 0;
	while(t--){
		cas++;
		int n;
		cin>>n;
		memset(cnt,0,sizeof(cnt));
		
		for(int i=1;i<2*n;i++){
			for(int j=1;j<=n;j++){
				int hh;
				scanf("%d",&hh);
				cnt[hh] = !cnt[hh]; 
			}
		}
		
		vector<int> ans;
		for(int i=1;i<=2500;i++){
			if(cnt[i]){
				ans.push_back(i);
			}
		}
		
		sort(ans.begin(),ans.end());
		
		printf("Case #%d:",cas);
		
		for(int h:ans){
			printf(" %d",h);
		}
		cout<<endl;
		
		
		
		
	}
	return 0;
}
