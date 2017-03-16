#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pr;

int main(){

	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		ll n;
		cin>>n;
		bool track[10];
		for(int j=0;j<10;j++) track[j]=false;
		if(n==0) {
			printf("Case #%d: INSOMNIA\n",i+1);  
			continue;
		}
		ll iter=1L,num=0L;
		bool found=false;
		string s;
		while(1){
			s=to_string(n*iter);
			for(int j=0;j<s.size();j++){
				if(!track[s[j]-'0']){
					track[s[j]-'0']=true;
					num++;
					if(num==10){
						found=true;
						break;
					}
				} 
			}
			if(found) break;
			iter++;
		}
		printf("Case #%d: %lld\n",i+1,iter*n);
	}
}