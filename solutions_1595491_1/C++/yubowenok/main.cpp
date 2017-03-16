#include <iostream>

using namespace std;

int main(){
	freopen("output", "w", stdout);

	int cs;
	int n, s, p;
	cin>>cs;
	for(int css=1;css<=cs;css++){
		printf("Case #%d: ", css);
		cin>>n>>s>>p;
		int ans = 0;
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			if(a==0) {
				if(p==0)ans++;
			}else{

			if(a%3==0){
				if(a/3>=p)ans ++;
				else if(a/3+1>=p && s>0){
					ans ++;
					s--;
				}
			}else if(a%3==1){
				if(a/3+1>=p){
					ans++;
				}
			}else if(a%3==2){
				if(a/3+1>=p){
					ans ++;
				}else if(a/3+2>=p && s>0){
					ans ++;
					s--;
				}
			}

			}
		}
		cout<<ans<<endl;
	}
}