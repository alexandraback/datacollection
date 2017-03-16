#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++){
		//建立放数据的容器
		//建立数据的行列下标索引
		int smax;
		scanf("%d",&smax);

		char level_num[1100] = {};
		//scanf("%s", &level_num);
		int level_number[1100] = {};
		int rule = 0;
		int person_number = 0;
		char nothing;
		scanf("%c", &nothing);
		for (int i = 0; i < smax + 1; i++){
			//level_number[i] = level_num[i] - '0';
			
			
			scanf("%c", &level_num[i]);
			level_number[i] = level_num[i] - '0';
			
			if (rule < i){
				int addPerson = i - rule;
				rule += addPerson;
				person_number += addPerson;
			}
			rule += level_number[i];
		}
		printf("Case #%d: %d\n", t, person_number);

	}
}