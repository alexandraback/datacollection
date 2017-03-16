#include <bits/stdc++.h>
using namespace std;


#define Fr(i,a,b) for(int i=a;i<b;++i)

#define F first
#define S second
pair<int,int> v[10000];
bool mark[1010][2];
int t,n;
int main(){
	scanf("%d",&t);
	Fr(cas, 1, t+1){
		memset(mark, false, sizeof(mark));
		scanf("%d",&n);
		Fr(i,0,n) scanf("%d %d",&v[i].F,&v[i].S);
		int tenho = 0;
		int npassos = 0;
		bool imp = false;
		Fr(i,0,2*n){
			int pegarei = -1;
			bool podepegarfim = false;
			Fr(j,0,n){
				if(mark[j][1] == false && v[j].S <= tenho && podepegarfim == false){
					podepegarfim = true;
					pegarei = j;
					break;
				}
				else if(mark[j][0] == false && v[j].F <= tenho && (v[pegarei].S < v[j].S || pegarei == -1)){
					pegarei = j;
				}
			}
			if(pegarei == -1){
				break;
			}
			else{
				npassos++;
				if(podepegarfim){
					if(mark[pegarei][0] == false) tenho += 2;
					else tenho++;
					mark[pegarei][0] = true;
					mark[pegarei][1] = true;
				}
				else{
					mark[pegarei][0] = true;
					++tenho;
				}
			}
		}
		Fr(i,0,n){
			if(mark[i][0] == false || mark[i][1] == false) imp = true;
		}
		if(imp){
			printf("Case #%d: Too Bad\n",cas);
		}
		else{
			printf("Case #%d: %d\n",cas,npassos);
		}
	}
	return 0;
}
