#include <stdio.h>
#include <string.h>

char ss[110];
char ss2[110], stemp[110];

int Operate1(){
	int a = 0, b = strlen(ss)-1;
	strcpy(ss2, ss);
	
	int op = 0;
	while(1){
		while(a <= b && ss2[a] == '+') a++;
		if(a > b) return op;
		
		if(a > 0){
			op++;
			for(int i=0; i<a; i++){
				stemp[a-i-1] = ss2[i];
			}
			for(int i=0; i<a; i++){
				if(stemp[i] == '+') ss2[i] = '-';
				else ss2[i] = '+';
			}
		}
		
		while(b >= a && ss2[b] == '+') b--;
		if(a > b) return op;
		op++;
		for(int i=0; i<=b; i++){
			stemp[b-i] = ss2[i];
		}
		for(int i=0; i<=b; i++){
			if(stemp[i] == '+') ss2[i] = '-';
			else ss2[i] = '+';
		}
	}
}
int Operate2(){
	int a = strlen(ss)-1;
	
	bool isPlus = true;
	int ctr = 0;
	
	for(int i=a; i>=0; i--){
		if(isPlus && ss[i] == '+') continue;
		if(!isPlus && ss[i] == '-') continue;
		
		isPlus = !isPlus;
		ctr++;
	}
	return ctr;
}

int main(){
	int jcase;
	
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	
	scanf("%d", &jcase);
	gets(ss);
	for(int icase=0; icase<jcase; icase++){
		gets(ss);
		int len = strlen(ss)-1;
		
		int ans1 = Operate2();
		printf("Case #%d: %d\n", icase+1, ans1);
	}
	
	return 0;
}
