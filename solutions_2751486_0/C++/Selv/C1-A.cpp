#include<cstdio>
#include<string.h>

using namespace std;

char T[1000100];


int z(char a){
	if(a=='a') return 0;
	if(a=='e') return 0;
	if(a=='i') return 0;
	if(a=='o') return 0;
	if(a=='u') return 0;
	
	
	
	return 1;
}
int Tnum;
void test(){
	Tnum++;
	int n,l;
	scanf("%s %d",T,&n);
	l=strlen(T);
	int x=0;
	for(int i=0;i<n;i++) if(z(T[i]))x++;
	int mG=-1;
	if(x==n) mG=0;
	int wyn=mG+1;
	for(int i=n;i<l;i++){
		x+=z(T[i]);
		x-=z(T[i-n]);
		if(x==n) mG=i-n+1;
		wyn+=mG+1;
	}
	
	
	printf("Case #%d: %d\n",Tnum,wyn);
}

int main(){
	int n;
	scanf("%d", &n);
	while(n--) test();
	return 0;
}
