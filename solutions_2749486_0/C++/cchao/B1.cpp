#include <cstdio>
#include <iostream>
using namespace std;

void move(int type, int s, int e, int &l){
	while(s != e){
		if(s < e){
			s -= l++;
			s += l++;
			putchar(type?'S':'W');
			putchar(type?'N':'E');
		}
		else{
			s += l++;
			s -= l++;
			putchar(type?'N':'E');
			putchar(type?'S':'W');
		}
	}
}
int main(){
	int T;
	scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase){
		int x, y;
		scanf("%d%d", &x, &y);
		int a = 0, b= 0, l = 1;
		printf("Case #%d: ", kase);
		move(0, a, x, l);
		move(1, b, y, l);
		puts("");
	}
	return 0;
}
