#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int T, cas;
int s,p,t[1000];
int n;
#define Fr(i,a,b) for(int i=a;i<b;++i)
int pega_max_com(int num){
	if(num < 2 || num > 27) return -1;
	if(num%3==0) return num/3+1;
	else if(num%3==1) return -1;
	else return num/3+2;
}


int pega_max_sem(int num){
	if(num % 3 == 0) return num/3;
	else if(num%3==1) return num/3+1;
	else if(num%3==2) return num/3+1;
}


int main(){
	scanf("%d",&T);
	Fr(cas,1,T+1){
		scanf("%d %d %d",&n,&s,&p);
		int resp = 0;
		Fr(i,0,n){
			scanf("%d",&t[i]);
		}
		sort(t, t+n);
		Fr(i,0,n){
			if(pega_max_sem(t[i]) < p && pega_max_com(t[i]) >= p){
				if(s > 0){
					s--;
					resp++;
				}
			}
			else if(pega_max_sem(t[i]) >= p) resp++;
		}
		printf("Case #%d: %d\n",cas,resp);
	}
	return 0;
}









