#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n, m ,k, t;
int main(){
	freopen("c2.in","r",stdin);
	freopen("c1.out","w",stdout);
	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++){
		int ans = 0;
		scanf("%d%d%d",&n, &m, &k);
		if (n > m){
			int tmp = n;
			n = m;
			m = tmp;
		}
		ans = k;
	
		if (n <= 2){
		}
		else if (n == 3){
			if (m == 3){
				if (k >= 5)
					ans--;
			}
			else
			if (m == 4){
				if (k >= 8)
					ans-=2;
				else if (k >= 5)
					ans-=1;
			}
			else
			if (m == 5){
				if (k >= 11)
					ans-=3;
				else if (k >= 8)
					ans-=2;
				else if (k >= 5)
					ans--;
			}
			else{
				if (k >= 14)
					ans-=4;
				else if (k >= 11)
					ans-=3;
				else if (k >= 8)
					ans-=2;
				else if (k >= 5)
					ans--;	
				
			}
		}
		else{
			if (m == 4){
				if (k >= 12)
					ans-=4;
				else if (k >= 10)
					ans-=3;
				else if (k >= 8)
					ans-=2;
				else if (k >= 5)
					ans--;	
			}
			else{
				if (k >= 16)
					ans-=6;
				else if (k >= 14)
					ans-=5;
				else if (k >= 12)
					ans-=4;
				else if (k >= 10)
					ans-=3;
				else if (k >= 8)
					ans-=2;
				else if (k >= 5)
					ans--;
				
				
			}
			
		}
		printf("Case #%d: %d\n",cs, ans);
	}
	return 0;
}
