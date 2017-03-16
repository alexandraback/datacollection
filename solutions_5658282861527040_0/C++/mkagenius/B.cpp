#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	int T; cin >> T;
	for(int tc=1;tc<=T; tc++){
		int a,b,k;	
		int ans = 0;
		cin >> a>>b>>k;
		for(int i = 0 ; i < a; i++){
			for(int j = 0; j < b; j++){
				if((i&j) < k){
					ans++;
				}
			}
		}
		cout<<"Case #"<<tc<<": " << ans << endl;
	}
	return 0;
}
