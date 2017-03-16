#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define ll long long

int main(){
	freopen("out.txt","w",stdout);
	int t;
	int tc = 0;
	scanf("%d",&t);
	while(t--){
		int n,m,k,loop;
		scanf("%d %d %d %d",&n ,&m, &k ,&loop);
		
		printf("Case #%d: ",++tc);
		int tmp = min(n*m, min(n*k, m*k));
		
		if(n*m*k<=loop*tmp){
			printf("%d\n",n*m*k);
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					for(int l = 0; l < k; l++){
						printf("%d %d %d\n",i+1 ,j+1 ,l+1); 
					}
				}
			}
		} else {
			int ans = loop*tmp;
			printf("%d\n",ans);
			int tbs = -1;
			if(n > m && n > k) tbs = 0; else
			if(m > n && m > k) tbs = 1; else
			tbs = 2;
			
			if(tbs == 0){
				priority_queue < pii > pq;
				for(int i = 0 ; i < n; i++) pq.push(mp(0,i));
				for(int i = 0; i < m && ans; i++){
					for(int j = 0; j < k && ans; j++){
						int ttmp = loop;
						for(int l = 0; l < n && ans && ttmp; l++){
							pii le = pq.top(); pq.pop();
							le.fi--;
							pq.push(le);
							printf("%d %d %d\n",le.se+1 ,i+1 ,j+1); 
							ans--;
							ttmp--;
						}
					}
				}
			} else
			
			if(tbs == 1){
				priority_queue < pii > pq;
				for(int i = 0 ; i < m; i++) pq.push(mp(0,i));
				
				for(int i = 0; i < n && ans; i++){
					for(int j = 0; j < k && ans; j++){
						int ttmp = loop;
						for(int l = 0; l < m && ans && ttmp; l++){
							pii le = pq.top(); pq.pop();
							le.fi--;
							pq.push(le);
							printf("%d %d %d\n",i+1 ,le.se+1 ,j+1); 
							ans--; ttmp--;
						}
					}
				}
			} else {
				priority_queue < pii > pq;
				for(int i = 0 ; i < k; i++) pq.push(mp(0,i));
				
				for(int i = 0; i < n && ans; i++){
					for(int j = 0; j < m && ans; j++){
						int ttmp  = loop;
						for(int l = 0; l < k && ans && ttmp; l++){
							pii le = pq.top(); pq.pop();
							le.fi--;
							pq.push(le);
							printf("%d %d %d\n",i+1 ,j+1 ,le.se+1); 
							ans--; ttmp--;
						}
					}
				}
			}
		}
	}
}
