#include<stdio.h>
bool pal(long long int x){
	long long int y=x,z=0;
	for(; y; y/=10)
		z=z*10+y%10;
	return x==z;
}
int main(){
	freopen("D:\\a.txt","w",stdout);
	for(int i=1; i<=10000000; i++){
		if(pal(i) && pal(1LL*i*i))
			printf("%I64dLL,",1LL*i*i);
	}
	return 0;
}