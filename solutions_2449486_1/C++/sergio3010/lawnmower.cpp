#include <bits/stdc++.h>

using namespace std;



#define fr(i,a,b) for(int i=a;i<b;++i)






int t,n,m;
int gr[1010][1010];
int ml[1010], mc[1010];







int main(){
	scanf("%d",&t);
	fr(cas,1,t+1){
		scanf("%d %d",&n,&m);
		fr(i,0,n) fr(j,0,m) scanf("%d",&gr[i][j]);
		fr(i,0,n){
			ml[i] = 0;
			fr(j,0,m){
				ml[i] = max(ml[i], gr[i][j]);
			}
		}
		fr(i,0,m){
			mc[i] = 0;
			fr(j,0,n){
				mc[i] = max(mc[i], gr[j][i]);
			}
		}
		bool pode = true;
		fr(i,0,n){
			fr(j,0,m){
				if(gr[i][j] == ml[i] || gr[i][j] == mc[j]) continue;
				pode = false;
 			}
		}
		printf("Case #%d: ",cas);
		if(pode) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}













