#include<cstdio>
#include<iostream>
#include<map>
using namespace std;

map<int,int> mp;
int main(){
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.ans","w",stdout);
	int t,n,i,cs = 1,a[100];
	cin>>t;
	while(t--){
		cin>>n;
		for(i = 0;i<n;i++) cin>>a[i];
		int mask;
		mp.clear();
		printf("Case #%d:\n",cs++);
		for(mask = 1;mask<(1<<n);mask++){
			int sum = 0;
			for(i = 0;i<n;i++){
				if(mask & (1<<i))
					sum+=a[i];
			}
			
			if(mp.find(sum)!=mp.end()){
				bool flag = 0;
				for(i = 0;i<n;i++){
					if(mask & (1<<i)){
						if(flag) printf(" ");
						flag = 1;
						printf("%d",a[i]);
					}
				}
				printf("\n");
				mask = mp[sum];

				flag = 0;
				for(i = 0;i<n;i++){
					if(mask & (1<<i)){
						if(flag) printf(" ");
						flag = 1;
						printf("%d",a[i]);
					}
				}
				printf("\n");
				break;
			}
			mp[sum] = mask;

		}
		if(mask == (1<<n)) printf("Impossible\n");
	}
	return 0;
}