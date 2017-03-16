#include <bits/stdc++.h>
using namespace std;


#define F first
#define S second
#define MP make_pair
#define Fr(i,a,b) for(int i=a;i<b;++i)
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int t,n,v[100];











int main(){
	scanf("%d",&t);
	Fr(cas,1,t+1){
		map<int,vector<int> > m;
		printf("Case #%d:\n",cas);
		scanf("%d",&n);
		Fr(i,0,n){
			scanf("%d",&v[i]);
		}
		Fr(i,0,1<<n){
			int r = 0;
			Fr(j,0,n){
				if(i&(1<<j)){
					r += v[j];
				}
			}
			if(m.find(r) == m.end()){
				m[r] = vector<int>();
				m[r].push_back(i);
			}
			else m[r].push_back(i);
		}
		Fr(i,0,1<<n){
			vector<int> aux = m[i];
			Fr(j,0,aux.size()){
				Fr(k,0,j){
					if((aux[j]&aux[k]) == 0){
						bool lol = false;
						Fr(l,0,n){
							if(aux[j]&(1<<l)){
								if(!lol) lol = true;
								else printf(" ");
								printf("%d",v[l]);
							}
						}
						printf("\n");
						lol = false;
						Fr(l,0,n){
							if(aux[k]&(1<<l)){
								if(!lol) lol = true;
								else printf(" ");
								printf("%d",v[l]);
							}
						}
						printf("\n");
						goto saida;
					}
				}
			}
		}
		saida:;
	}
	return 0;
}
