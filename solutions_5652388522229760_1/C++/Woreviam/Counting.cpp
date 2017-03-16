
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 100005

using namespace std;

bool vis[11];
bool valid(){
	
	for(int i = 0; i < 10; i++)if(!vis[i])return false;
	return true;
}	

void fill(long long cur){
	
	while(cur > 0)vis[cur%10] = true, cur /= 10;	
}

int main(){

	int tc = 0, caso = 1;
	scanf("%d", &tc);
	
	while(tc--){
		
		long long n;
		scanf("%lld", &n);
		
		if(n == 0)printf("Case #%d: INSOMNIA\n", caso++);
		else{
			
			long long cur = n;
			memset(vis, false, sizeof vis);
			
			while(!valid()){
				
				fill(cur);
				cur += n;
			}
			
			printf("Case #%d: %lld\n", caso++, cur - n);
		}
	}


}

