#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>

#define ln printf("\n")
#define rep(a,b) for(int a = 0; a < b; a++)

using namespace std;

int a[1111];
int b[1111];
int n;

bool read(){
	scanf("%d", &n);
	
	rep(i,n){
		scanf("%d%d", &a[i], &b[i]);
	}
	
	return true;
}

int cn = 1;

void process(){
	printf("Case #%d: ", cn++);
	
	int s = 0;
	int cont = 0;
	while(n){
		int lvl2 = -1;
		rep(i,n){
			if(b[i] <= s) lvl2 = i;
		}
		
		if(lvl2 != -1){
			if(a[lvl2] == -1) s++;
			else s += 2;
			
			a[lvl2] = a[n-1];
			b[lvl2] = b[n-1];
			n--;
			cont++;
		}
		else{
			int lvl1 = -1;
			
			rep(i,n){
				if(a[i] != -1){
					if(a[i] <= s){
						if(lvl1 == -1) lvl1 = i;
						else if(b[i] > b[lvl1]) lvl1 = i;
					}
				}
			}
			
			if(lvl1 == -1){
				printf("Too Bad\n");
				return;
			}
			s++;
			a[lvl1] = -1;
			cont++;
		}
	}
	
	printf("%d\n", cont);
}

int main(){
	freopen("a.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t = -1;
	scanf("%d", &t);
	while(t-- && read()) process();
	
	//while(1);
	
	return 0;
}
