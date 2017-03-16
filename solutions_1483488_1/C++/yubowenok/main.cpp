#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

bool num[2001000];

int intlen(int n){
	int len = 0;
	while(n){
		n/=10;
		len++;
	}
	return len;
}

int main(){
	freopen("output", "w", stdout);

	int cs;
	int a,b;
	cin>>cs;
	for(int css=1;css<=cs;css++){
		printf("Case #%d: ", css);
		cin>>a>>b;
		int ans = 0;
		int n, nk;
		memset(num, 0, sizeof(num));

		for(n=a; n<=b; n++){
			int len = intlen(n);
			int v = 0;
			
			//cout << n << ":" << endl;

			for(int i=0;i<len;i++){
				if(n>=a && n<=b && num[n]==false){
					num[n] = true;
					//cout << n << endl;
					v++;
				}
				while(1){
					nk = n/10+n%10*(int)pow(10.0, len-1);
					if(intlen(nk)==len){
						n = nk;
						break;
					}else{
						n = nk;
						i++;
					}
				}
			}
			ans += v*(v-1)/2;
		}

		cout<<ans<<endl;
	}
}