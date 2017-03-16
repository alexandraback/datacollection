#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;




int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++){
		//建立放数据的容器
		//建立数据的行列下标索引
		bool isok = true;
		int X,R,C;
		scanf("%d %d %d", &X,&R,&C);
		if (R*C%X != 0)
			isok = false;
		else{
			if (X == 1 || X == 2) isok = true;
			else if (X == 3){
				if (R*C < 6) isok = false;
				else isok = true;
			}
			else if (X == 4){
				if (R*C < 9) isok = false;
				else if (abs(R - C) < 2) isok = true;
				else if (R*C>12) isok = true;
				else isok = false;
			}
		}
		if (isok)
			printf("Case #%d: GABRIEL\n", t);
		else
			printf("Case #%d: RICHARD\n", t);

	}
}