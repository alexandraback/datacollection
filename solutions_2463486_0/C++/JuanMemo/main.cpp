#include <stdio.h>
#include <algorithm>
using namespace std;

int tabla[10000000],casos,a,b,total = 1;
unsigned long long int memo[22];

int getSize(unsigned long long int x){
	int r = 0;
	while(x > 0){
		x/= 10;
		r++;
	}
	return r;
}
int numAt(unsigned long long int x,int pos){
	for(int i = 0;i < pos;i++){
		x /= 10;
	}
	x %= 10;
	return x;
}
bool esPalindromo(unsigned long long int x){
	int size = getSize(x);
	int j = size-1;
	for(int i = 0;i < size;i++){
		if(numAt(x,i)!=numAt(x,j--))
			return false;
	}
	return true;
}
int main(){
	freopen("in.txt","r",stdin);
	memo[0] = 1;
	int r;
	for(int i = 2;i <= 10000000;i++){
		if(esPalindromo(i)){
			tabla[i]++;
			if(i <= 3162)
				tabla[i*i]++;
			else if(esPalindromo(i*i))
				memo[total++] = i*i;				
			if(tabla[i] == 2)
				memo[total++] = i;			
		}
	}
	sort(memo,memo+total);
	scanf("%d",&casos);
	for(int i = 1;i <= casos;i++){
		scanf("%d %d",&a,&b);
		r = 0;
		for(int j = 0;j < total;j++)
			if(memo[j] >= a && memo[j] <= b)
				r++;
		printf("Case #%d: %d\n",i,r);		
	}
	return 0;
}
