
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 100005

using namespace std;

char s[N];

int main(){

	int tc = 0, caso = 1;
	scanf("%d", &tc);
	
	while(tc--){
		
		scanf("%s", s);
		int len = strlen(s);	
		
		int flip = 0, ans = 0;	
		for(int i = len - 1; i >= 0; i--){
			
			if(flip&1){
				
				if(s[i] == '+')s[i] = '-';
				else s[i] = '+';	
			}
			
			if(s[i] == '-'){
				
				ans++;
				flip ^= 1;
			}
		}
		
		printf("Case #%d: %d\n", caso++, ans);
	}


}

