#include <bits/stdc++.h>
using namespace std;


#define F first
#define S second
#define MP make_pair
#define Fr(i,a,b) for(int i=a;i<b;++i)
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int t,h,n,m;
int ce[110][110];
int fl[110][110];
bool mark[110][110][1010];
int inci[] = {0,-1,0,1};
int incj[] = {1,0,-1,0};

struct no{
	int x,y,h;
	double c;
	no(int x=0, int y=0, int h=0, double c=0): x(x), y(y), h(h), c(c) {}
	bool operator <(const struct no &lhs) const{
		return c >= lhs.c;
	}
};

bool valid(int a, int b){
	return a >= 0 && b >= 0 && a < n && b < m;
}



bool pode(int a, int b, int c, int d, int alt){
	if(valid(a,b) && valid(c,d)){
		if(fl[a][b] + 50 <= ce[c][d] && fl[c][d] + 50 <= ce[c][d] && alt + 50 <= ce[c][d] && fl[c][d] + 50 <= ce[a][b]){
			return true;
		}
	}
	return false;
}





priority_queue<no> heap;
queue<no> fila;

int main(){
	scanf("%d",&t);
	Fr(cas,1,t+1){
		memset(mark, false, sizeof(mark));
		while(!heap.empty()) heap.pop();
		scanf("%d %d %d",&h,&n,&m);
		Fr(i,0,n){
			Fr(j,0,m){
				scanf("%d",&ce[i][j]);
			}
		}
		Fr(i,0,n){
			Fr(j,0,m){
				scanf("%d",&fl[i][j]);
			}
		}
		fila.push(no(0,0,h,0));
		while(!fila.empty()){
			no aux = fila.front(); fila.pop();
			if(mark[aux.x][aux.y][aux.h]) continue;
			mark[aux.x][aux.y][aux.h] = true;
			heap.push(aux);
			Fr(i,0,4){
				if(pode(aux.x, aux.y, aux.x+inci[i], aux.y+incj[i], h)){
					fila.push(no(aux.x+inci[i], aux.y+incj[i], h, 0));
				}
			}
		}
		double resp = 1000*1000*1000;
		memset(mark, false, sizeof(mark));
		while(!heap.empty()){
			no aux = heap.top(); heap.pop();
			if(mark[aux.x][aux.y][aux.h]) continue;
			if(aux.x == n-1 && aux.y == m-1){
				resp = aux.c;
				break;
			}
			mark[aux.x][aux.y][aux.h] = true;
			Fr(i,0,4){
				if(pode(aux.x, aux.y, aux.x+inci[i], aux.y+incj[i], aux.h)){
					if(aux.h-fl[aux.x][aux.y] >= 20)
						heap.push(no(aux.x+inci[i], aux.y+incj[i], aux.h-10, aux.c+1));
					else{
						heap.push(no(aux.x+inci[i], aux.y+incj[i], aux.h-100, aux.c+10));
					}
				}
			}
			heap.push(no(aux.x, aux.y, aux.h-1, aux.c+0.1));
		}
		printf("Case #%d: %.7lf\n",cas,resp);
	}
	return 0;
}

























