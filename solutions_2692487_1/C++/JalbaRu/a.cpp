#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
//	freopen("1.txt","r",stdin);
//	freopen("A-small-attempt0.in","r",stdin);
//	freopen("AoutSmall.txt","w",stdout);
	freopen("A-large.in","r",stdin);
	freopen("AoutLarge.txt","w",stdout);
	int TT;
	cin>>TT;
	for(int T=0;T<TT;T++){
		printf("Case #%d: ",T+1);
		int a,n;
		cin>>a>>n;
		vector<int> s(n);
		for(int i=0;i<n;i++)
			cin>>s[i];
		sort(s.begin(),s.end());
		int j=0;
		int ans=n;
		int step=0;
		while(j<s.size()){
			while(j<s.size() && s[j]<a){
				a+=s[j];
				j++;
			}
			ans=min(ans,step+int(s.size())-j);
			if(j<s.size()){
				step++;
				if(a-1==0) break;
				a=a+(a-1);
			}
		}
		printf("%d\n",ans);
	}


		

}
