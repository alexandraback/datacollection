#include <cstdio>
#include<algorithm>
#include <vector>
using namespace std;

int T,R,N,M,K;
int table[10];
int count2,count3,count4,count5;

int found;
void test(int a1,int a2,int a3){
	for(int i=1;i<=K;i++){
		if(table[i] == 1) continue;
		else if(table[i] == a1) continue;
		else if(table[i] == a2) continue;
		else if(table[i] == a3) continue;
		else if(table[i] == a1*a2) continue;
		else if(table[i] == a2*a3) continue;
		else if(table[i] == a1*a3) continue;
		else if(table[i] == a1*a2*a3) continue;
		else return ;
	}
	found = true;
	printf("%d%d%d\n",a1,a2,a3);
}

int main(){
	freopen("C-small-1-attempt0.in","r",stdin);
	freopen("C-small-1.out","w",stdout);
	
	printf("Case #1:\n");
	scanf("%d %d %d %d %d",&T,&R,&N,&M,&K);
	for(int i=1;i<=R;i++){
		count2 = count3 = count4 = count5 = 0;
		for(int j=1;j<=K;j++) scanf("%d",&table[j]);
		found = false;
		for(int j=2;j<=M;j++) for(int k=j;k<=M;k++) for(int l=k;l<=M;l++) if(!found) test(j,k,l);
	}
	return 0;
}