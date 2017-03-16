#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

int TTT,A,B;
int d[20];

bool pal(int x){
	int xx=x;
	int y=0;
	while (x>0){
		y=y*10+x%10; x/=10;
	}
	return xx==y;
}

int main(){
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d",&TTT);
	for (int TT=1; TT<=TTT; TT++){
		printf("Case #%d: ",TT);
		scanf("%d %d",&A,&B);
		int cnt=0;
		for (int i=A; i<=B; i++){
			if (pal(i)) {
				int j=int(sqrt(i));
				if (j*j!=i) continue;
				if (pal(j)) {
					cnt++;
					//printf("pal_%d ",i); 
				}
			}
		}
		printf("%d\n",cnt);
	}
	
	fclose(stdout);
	fclose(stdin);
}
